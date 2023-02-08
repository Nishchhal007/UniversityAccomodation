#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <cstring>

using namespace std;

int num_student = 0;

void Electrician(string);
void Plumber(string);
void Cleaner(string);
void Furniture(string hostel_name);

class student
{
	int reg_num;
	string name;
	string father_name;
	int room_no;
	string address;
	string hostel_name;
	string username;
	string password;
	int mess_bill;

public:
	student()
	{
		reg_num = -1;
		room_no = -1;
		mess_bill = 0;
		username = "";
		password = "";
		hostel_name = "";
	}
	void set_info_of_student()
	{
		cout << "Enter name of student" << endl;
		getline(cin, name);
		cout << "Enter name of father of the student" << endl;
		getline(cin, father_name);
		cout << "Enter address of student" << endl;
		getline(cin, address);
		reg_num = ++num_student;
		username = name.substr(0, 3) + to_string(reg_num);
		password = name.substr(0, 2) + father_name.substr(0, 2) + to_string(reg_num);
	}

	int get_reg_num()
	{
		return reg_num;
	}

	string get_name_of_student()
	{
		return name;
	}
	string get_user_id()
	{
		return username;
	}
	string get_password()
	{
		return password;
	}
	void print_info()
	{
		cout << "Name of student:   " << name << endl;
		cout << "Registration number of student:" << reg_num << endl;
		cout << "Room no of student:" << room_no << endl;
		cout << "Name of the hostel:" << hostel_name << endl;
		cout << "Fathers name:      " << father_name << endl;
		cout << "Address of student:" << address << endl;
	}
	void get_CIS_id()
	{
		cout << "CIS ID - " << username << endl;

		cout << "Password - " << get_password() << endl;
	}

	int request_service()
	{

		cout << "1.Get Your CIS ID" << endl;
		cout << "2.View Mess Bill" << endl;
		cout << "3 for Electrician" << endl;
		cout << "4 for Plumber" << endl;
		cout << "5 for Room Cleaning" << endl;
		cout << "6 for Furniture" << endl;
		cout << "7 for exit" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			get_CIS_id();
			return 1;
			break;
		case 2:
			// complaint2();
			return 1;
			break;
		case 3:
			Electrician(hostel_name);
			return 1;
			break;
		case 4:
			Plumber(hostel_name);
			return 1;
			break;
		case 5:
			Cleaner(hostel_name);
			return 1;
			break;
		case 6:
			Furniture(hostel_name);
			return 1;
			break;
		case 7:

			return 0;
			break;

		default:
			cout << "Invalid Choice" << endl;
			break;
		}
	}
};

class hostel_info
{
	string Electrician;
	string Plumber;
	string Cleaner;

public:
	hostel_info()
	{
	}
	string get_electrician()
	{
		return Electrician;
	}
	string get_plumber()
	{
		return Plumber;
	}
	string get_cleaner()
	{
		return Cleaner;
	}
};

class inventory
{
	int num_of_tables;
	int num_of_bed;
	int num_of_chair;
	int num_of_almirah;

public:
	inventory()
	{
		set_tables(5);
		set_almirah(5);
		set_bed(5);
		set_chair(5);
	}
	int get_tables()
	{
		return num_of_tables;
	}
	int get_bed()
	{
		return num_of_bed;
	}
	int get_chair()
	{
		return num_of_chair;
	}
	int get_almirah()
	{
		return num_of_almirah;
	}
	int set_tables(int x)
	{
		num_of_tables = x;
	}
	int set_bed(int x)
	{
		num_of_bed = x;
	}
	int set_chair(int x)
	{
		num_of_chair = x;
	}
	int set_almirah(int x)
	{
		num_of_almirah = x;
	}
};

class room
{

	int capacity;
	int occupancy;
	student *residents;

public:
	int get_vacancy()
	{
		return capacity - occupancy;
	}

	void setcapacity(int x = 2)
	{
		residents = new student[x];
		capacity = x;
		// for(int i=0; i<x; i++)
		// {
		// 	residents[i] = new student;
		// }
		occupancy = 0;
	}

	void addstudent(student s)
	{

		if (occupancy < capacity)
		{
			residents[occupancy] = s;
			occupancy++;
		}
		else
		{
			cout << "Room already full\n";
		}
	}

	void deletestudent(int roll)
	{
		int flag = 0;
		for (int i = 0; i < occupancy; i++)
		{
			if (residents[i].get_reg_num() == roll)
			{
				// residents[i].set_reg_num(-1);
				flag = 1;
				occupancy--;
				break;
			}
			if (flag == 0)
				cout << "Student does not exist in this room\n";
			else
			{
				cout << "Deleted Successfully\n";
			}
		}
	}
};

class hostel
{
	string hostel_name;

	room room_list[10];

public:
	inventory stock;
	hostel_info info;

	hostel()
	{
		cout << "Enter Hostel Name - ";
		cin >> hostel_name;
	}

	int check_vacancy()
	{
		int vacancy = 0;
		for (int i = 0; i < 10; i++)
		{
			vacancy += room_list[i].get_vacancy();
		}
		return vacancy;
	}
	string getname()
	{
		return hostel_name;
	}
};

void Electrician(string hostel_name)
{

	ifstream file1;
	file1.open("hostel.txt", ios::in);

	hostel temp;
	file1.read((char *)&temp, sizeof(temp));
	bool flag = 0;
	while (!file1.eof())
	{
		// cout << temp.getname() << "--> " << temp.check_vacancy() << endl;
		if (temp.getname() == hostel_name)
		{
			flag = 1;
			cout << "Contact at " << temp.info.get_electrician() << endl;
		}

		file1.read((char *)&temp, sizeof(temp));
	}
	if (flag == 0)
	{
		cout << "Hostel Not alloted" << endl;
	}

	file1.close();
}

void Plumber(string hostel_name)
{

	ifstream file1;
	file1.open("hostel.txt", ios::in);

	hostel temp;
	file1.read((char *)&temp, sizeof(temp));
	bool flag = 0;
	while (!file1.eof())
	{
		// cout << temp.getname() << "--> " << temp.check_vacancy() << endl;
		if (temp.getname() == hostel_name)
		{
			flag = 1;
			cout << "Contact at " << temp.info.get_plumber() << endl;
		}

		file1.read((char *)&temp, sizeof(temp));
	}
	if (flag == 0)
	{
		cout << "Hostel Not alloted" << endl;
	}

	file1.close();
}

void Cleaner(string hostel_name)
{

	ifstream file1;
	file1.open("hostel.txt", ios::in);

	hostel temp;
	file1.read((char *)&temp, sizeof(temp));
	bool flag = 0;
	while (!file1.eof())
	{
		// cout << temp.getname() << "--> " << temp.check_vacancy() << endl;
		if (temp.getname() == hostel_name)
		{
			flag = 1;
			cout << "Contact at " << temp.info.get_cleaner() << endl;
		}

		file1.read((char *)&temp, sizeof(temp));
	}
	if (flag == 0)
	{
		cout << "Hostel Not alloted" << endl;
	}

	file1.close();
}

void Furniture(string hostel_name)
{

	ifstream file1;
	file1.open("hostel.txt", ios::in);

	hostel temp;
	file1.read((char *)&temp, sizeof(temp));
	bool flag = 0;
	while (!file1.eof())
	{
		if (temp.getname() == hostel_name)
		{
			flag = 1;
			cout << "Status of almirah " << temp.stock.get_almirah() << endl;
			cout << "Status of bed " << temp.stock.get_bed() << endl;
			cout << "Status of chairs " << temp.stock.get_chair() << endl;
			cout << "Status of tables " << temp.stock.get_tables() << endl;
		}

		file1.read((char *)&temp, sizeof(temp));
	}
	if (flag == 0)
	{
		cout << "Hostel Not alloted" << endl;
	}

	file1.close();
}

int adminView();
int studentView();
int studentLogin();
// int checkCredentials(string userName, string password);
int deleteStudentbyRollno();
int getListOfStudentsWithTheirPresenseCount();
void registerstudent();

int adminView()
{
	int goBack = 0;

	while (1)
	{
		system("cls");
		cout << "\n 1 Register a Student";
		cout << "\n 1 add hostelt";
		cout << "\n 1 allot a hostel";
		cout << "\n 3 Delete student";
		cout << "set warden" << endl;
		cout << "\n 4 Student List";
		cout << "Enter Mess Bill" << endl;
		cout << "\n 0. Go Back <- \n";
		int choice;
		cout << "\n Enter you choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			registerstudent();
			break;
		case 2:
			deleteAllStudents();
			break;
		case 3:
			deleteStudentbyRollno();
			break;
		case 4:
			checkListOfStudentsRegistered();
			break;
		case 5:
			checkPresenseCountbyRollno();
			break;
		case 6:
			getListOfStudentsWithTheirPresenseCount();
			break;
		case 0:
			goBack = 1;
			break;
		default:
			cout << "\n Invalid choice. Enter again ";
			getchar();
		}

		if (goBack == 1)
		{
			break;
		}
	}
	return 0;
}

class admin
{
	string username;
	string password;

public:
	admin()
	{
		username = "admin";
		password = "anuy";
	}

	bool admin_login()
	{
		string u;
		string p;
		cout << "\n Enter username : ";
		cin >> u;
		cout << "\n Enter password : ";
		cin >> p;
		if (username == u && password == p)
		{
			adminView();
			return 1;
		}
		else
		{
			cout << "\n Error ! Invalid Credintials.." << endl;
			cout << "\n Press any key for main menu " << endl;
			getchar();
			getchar();
			return 0;
		}
	}
};

int studentLogin()
{
	system("cls");
	cout << "\n -------- Student Login ---------";
	studentView();

	return 0;
}

int checkStudentCredentials(string username, string password)
{
	ifstream read;
	read.open("db.dat");

	if (read)
	{

		int recordFound = 0;
		string line;
		string temp = username + ".dat";
		cout << "\n file name is : " << temp;
		while (getline(read, line))
		{
			if (line == temp)
			{
				recordFound = 1;
				break;
			}
		}

		if (recordFound == 0)
			return 0;
		else
			return 1;
	}
	else
	{
		return 0;
	}
}

int getAllStudentsbyName()
{
	cout << "\n List of All Students by their Name \n";
	cout << "\n Please any key to continue..";
	getchar();
	getchar();
	return 0;
}

int getAllStudentsbyRollNo()
{
	cout << "\n List of All Students by their Roll No \n";
	cout << "\n Please any key to continue..";
	getchar();
	getchar();
	return 0;
}

int deleteStudentbyRollno()
{
	cout << "\n Delete any Student by their Roll No \n";
	// int status;
	// string username;
	// cin>>username;
	//     char fileName[100] = username + ".dat";
	//     //cout<<"Enter the Name of File: ";
	//     // cin>>fileName;
	//     status = remove(fileName);
	//     if(status==0)
	//         cout<<"\nFile Deleted Successfully!";
	//     else
	//         cout<<"\nError Occurred!";
	//     cout<<endl;
	//     return 0;
	cout << "\n Please any key to continue..";
	getchar();
	getchar();
	return 0;
}

int checkPresenseCountbyRollno()
{
	cout << "\n Check presense count of any Student by Roll No \n";
	cout << "\n Please any key to continue..";
	getchar();
	getchar();
	return 0;
}

int checkAllPresenseCountbyRollno()
{
	cout << "\n Check presense count of All Students by Roll No & Name \n";
	cout << "\n Please any key to continue..";
	getchar();
	getchar();
	return 0;
}

int studentView()
{
	cout << "\n ------- Student Login-------- \n";
	string username, password;
	cout << "\n Enter username : ";
	cin >> username;
	cout << "\n Enter password : ";
	cin >> password;
	int res = 0;

	ifstream file1;
	file1.open("student.txt", ios::in);

	student temp;
	file1.read((char *)&temp, sizeof(temp));

	while (!file1.eof())
	{

		if (temp.get_user_id() == username && temp.get_password() == password)
		{
			res = 1;
			break;
		}

		file1.read((char *)&temp, sizeof(temp));
	}

	file1.close();

	if (res == 0)
	{
		cout << "\n Invalid Credentials !!";
		cout << "\n Press any key for Main Menu..";
		getchar();
		getchar();
		return 0;
	}

	int goBack = 0;
	while (1)
	{
		system("cls");
		goBack = temp.request_service();

		if (goBack == 0)
			break;
	}
}

int markMyAttendance(string username)
{
	cout << "\n Mark Attendance for today !!";
	cout << "\n Please any key to continue..";

	getchar();
	getchar();

	return 0;
}

int countMyAttendance(string username)
{
	cout << "\n Count my attendace for today !!";
	cout << "\n Please any key to continue..";
	getchar();
	getchar();
	return 0;
}

int deleteAllStudents()
{
	cout << "\n In delete all students !!";
	cout << "\n Please any key to continue..";
	getchar();
	getchar();
	return 0;
}

int checkListOfStudentRegistered()
{
	cout << "\n List of All registered registered !!";
	cout << "\n Please any key to continue..";
	getchar();
	getchar();
	return 0;
}

int getListOfStudentsWithTheirPresenseCount()
{
	cout << "\n All Students with their Presense count !!";
	cout << "\n Please any key to continue..";
	getchar();
	getchar();
	return 0;
}

int checkListOfStudentsRegistered()
{
	cout << "\n - Check List of Student Registered by Username-- ";
	ifstream read;
	read.open("db.dat");

	if (read)
	{
		int recordFound = 0;
		string line;
		while (getline(read, line))
		{
			char name[100];
			strcpy(name, line.c_str());
			char onlyname[100];
			strncpy(onlyname, name, (strlen(name) - 4));
			cout << " \n " << onlyname;
		}
		read.close();
	}
	else
	{
		cout << "\n No Record found :(";
	}

	cout << "\n Please any key to continue..";
	getchar();
	getchar();
	return 0;
}

void registerstudent()
{
	cout << "\n ----- Student Registration Form ---- \n";

	getchar();
	student s;
	s.set_info_of_student();

	ofstream file;
	file.open("student.txt", ios::app);

	file.write((char *)&s, sizeof(s));

	file.close();
}

void check_hostel()
{

	ifstream file1;
	file1.open("hostel.txt", ios::in);

	hostel temp;
	file1.read((char *)&temp, sizeof(temp));

	while (!file1.eof())
	{
		cout << temp.getname() << "--> " << temp.check_vacancy() << endl;
		file1.read((char *)&temp, sizeof(temp));
	}
	file1.close();
}
void title();
int main()
{
	title();
	admin a;
	while (1)
	{
		system("cls");
		cout << "\n University Accomodation Handling System \n";
		cout << "*************\n\n";

		cout << "1. Hostel Student Login\n";
		cout << "2. Hostel Administrator Login\n";

		cout << "0. Exit\n";
		int choice;

		cout << "\n Enter you choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			studentLogin();
			break;
		case 2:

			a.admin_login();
			break;
		case 0:
			while (1)
			{
				system("cls");
				cout << "\n Are you sure, you want to exit? y | n \n";
				char ex;
				cin >> ex;
				if (ex == 'y' || ex == 'Y')
					exit(0);
				else if (ex == 'n' || ex == 'N')
				{
					break;
				}
				else
				{
					cout << "\n Invalid choice !!!";
					getchar();
				}
			}
			break;

		default:
			cout << "\n Invalid choice. Enter again ";
			getchar();
		}
	}
	return 0;
}

void title()
{
	printf("\n");
	printf("\t\t\t\t\t");
	printf("\n");
	printf("\t\t\t\t    ----------------------------------\n");
	printf("\t\t\t\t    | University Accomodation Handling |\n");
	printf("\t\t\t\t    ----------------------------------\n");
	printf("\n");
}