#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <cstring>
#include"hostel.h"

using namespace std;


class student
{
	int roll_no;
	string name;
	string father_name;
	int room_no;
	string address;
	string hostel_name;
	string username;
	string password;
	int mess_bill;

public:
	void set_info_of_student()
	{
		cout << "Enter roll no of student" << endl;
		cin >> roll_no;
		cout << "Enter name of student" << endl;
		getline(cin, name);
		cout << "Enter name of father of the student" << endl;
		getline(cin, father_name);
		cout << "Enter room no of student" << endl;
		cin >> room_no;
		cout << "Enter address of student" << endl;
		getline(cin, address);
		cout << "Enter name of Hostel" << endl;
		getline(cin, hostel_name);
		cout << "Enter student user id!" << endl;
		getline(cin, username);
		cout << "Enter password:" << endl;
		getline(cin, password);
		mess_bill = 0;
	}

	int get_roll_no()
	{
		return roll_no;
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
		cout << "Roll no of student:" << roll_no << endl;
		cout << "Room no of student:" << room_no << endl;
		cout << "Name of the hostel:" << name << endl;
		cout << "Fathers name:      " << name << endl;
		cout << "Address of student:" << name << endl;
	}

	void apply_hostel()
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
	friend class hostel;
};

class admin
{
	string username;
	string password;
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
			if (residents[i].get_roll_no() == roll)
			{
				// residents[i].set_roll_no(-1);
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

int adminView();
int studentView();
int studentLogin();
int checkCredentials(string userName, string password);
int getAllStudentsbyRollNo();
int deleteAllStudents();
int deleteStudentbyRollno();
int checkListOfStudentsRegistered();
int checkPresenseCountbyRollno();
int getListOfStudentsWithTheirPresenseCount();
int registerStudent();
int adminLogin();
int registerStudent();
int markMyAttendance(string username);
int countMyAttendance(string username);
int delay();

int adminView()
{
	int goBack = 0;
	while (1)
	{
		system("cls");
		cout << "\n 1 Register a Student";
		// cout<<"\n 2 Delete All students name registered";
		cout << "\n 3 Delete student by rollno";
		cout << "\n 4 Check List of Student registered by userame";
		cout << "\n 5 Check presense count of any student by Roll No";
		cout << "\n 6 Get List of student with their attendance count";
		cout << "\n 0. Go Back <- \n";
		int choice;
		cout << "\n Enter you choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			registerStudent();
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

int studentLogin()
{
	system("cls");
	cout << "\n -------- Student Login ---------";
	studentView();

	return 0;
}

int adminLogin()
{
	system("cls");
	cout << "\n --------- Admin Login --------";
	string username;
	string password;
	cout << "\n Enter username : ";
	cin >> username;
	cout << "\n Enter password : ";
	cin >> password;

	if (username == "ujjwal" && password == "jain")
	{
		adminView();
		getchar();
		delay();
	}
	else
	{
		cout << "\n Error ! Invalid Credintials..";
		cout << "\n Press any key for main menu ";
		getchar();
		getchar();
	}
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
	int res = checkStudentCredentials(username, password);

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
		cout << "\n 1 Mark Attendance fo Today ";
		cout << "\n 2 Count my Attendance";
		cout << "\n 0. Go Back <- \n";
		int choice;
		cout << "\n Enter you choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			markMyAttendance(username);
			break;
		case 2:
			countMyAttendance(username);
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

int registerStudent()
{
	cout << "\n ----- Form to Register Student ---- \n";

	string name, username, password, rollno, address, father, mother;
	getchar();
	char names[50];
	cout << "\n Enter Name : ";
	cin.getline(names, 50);
	name = names;
	cout << "\n Enter Username : ";
	cin >> username;
	cout << "\n Enter password : ";
	cin >> password;
	cout << "\n Enter rollno : ";
	cin >> rollno;
	getchar();

	char add[100];
	cout << "\n Enter address : ";
	cin.getline(add, 100);
	cout << "\n Enter father : ";
	cin >> father;
	cout << "\n Enter mother : ";
	cin >> mother;
	ifstream read;
	read.open("db.dat");

	if (read)
	{
		int recordFound = 0;
		string line;
		while (getline(read, line))
		{
			if (line == username + ".dat")
			{
				recordFound = 1;
				break;
			}
		}
		if (recordFound == 1)
		{
			cout << "\n Username already Register. Please choose another username ";
			getchar();
			getchar();
			delay();
			read.close();
			return 0;
		}
	}
	read.close();

	ofstream out;
	out.open("db.dat", ios::app);
	out << username + ".dat"
		<< "\n";
	out.close();

	ofstream out1;
	string temp = username + ".dat";
	out1.open(temp.c_str());
	out1 << name << "\n";
	out1 << username << "\n";
	out1 << password << "\n";
	out1 << rollno << "\n";
	out1 << add << "\n";
	out1 << father << "\n";
	out1 << mother << "\n";
	out1.close();

	cout << "\n Student Registered Successfully !!";

	cout << "\n Please any key to continue..";
	getchar();
	getchar();
	return 0;
}

int main()
{
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
			adminLogin();
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
