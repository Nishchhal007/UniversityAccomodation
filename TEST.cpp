#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <cstring>

using namespace std;

void Electrician(string);
void Plumber(string);
void Cleaner(string);
void Furniture(string hostel_name);
void check_hostel();
void AllotHostel(int);
int wardenView();

class student
{
    int reg_num;
    char name[32];
    char father_name[32];
    int room_no;
    char address[32];
    char hostel_name[32];
    char username[32];
    char password[32];
    int mess_bill;

public:
    student()
    {
        reg_num = -1;
        room_no = -1;
        mess_bill = 0;
        hostel_name[0] = 'N';
        hostel_name[1] = 'A';
        hostel_name[2] = '\0';
    }

    void set_info_of_student()
    {
        cout << "Enter name of student : " << endl;
        cin.getline(name, 32);
        cout << "Enter Registration Number : " << endl;
        cin >> reg_num;
        getchar();
        cout << "Enter Father's Name : " << endl;
        cin.getline(father_name, 32);
        cout << "Enter address of student : " << endl;
        cin.getline(address, 32);

        // Converting str to char array
        string str;
        str = get_name_of_student().substr(0, 3) + to_string(reg_num);
        strncpy(username, str.c_str(), sizeof(username));

        // Converting str to char array
        string str1;
        str1 = get_name_of_student().substr(0, 2) + get_father_name_of_student().substr(0, 2) + to_string(reg_num);
        strncpy(password, str1.c_str(), sizeof(password));
    }

    bool set_hostel()
    {
        if (strcmp(hostel_name, "NA") == 0)
        {
            check_hostel();
            cout << "Enter Hostel Name - ";
            cin >> hostel_name;
            return 1;
        }
        else
            return 0;
    }

    int get_reg_num()
    {
        return reg_num;
    }
    int get_room()
    {
        return room_no;
    }

    string get_name_of_student()
    {
        string str(name);
        return str;
    }
    string get_father_name_of_student()
    {
        string str(father_name);
        return str;
    }
    string get_user_id()
    {
        string str(username);
        return str;
    }
    string get_hostel()
    {
        string str(hostel_name);
        return str;
    }
    string get_password()
    {
        string str(password);
        return str;
    }
    string get_address()
    {
        string str(address);
        return str;
    }
    void print_info()
    {
        cout << "Name of student: " << name << endl;
        cout << "Registration number of student: " << reg_num << endl;
        cout << "Fathers name: " << father_name << endl;
        cout << "Name of the hostel: " << hostel_name << endl;
        cout << "Room no of student: " << room_no << endl;
        cout << "Address of student: " << address << endl;
    }
    void get_CIS_id()
    {
        cout << "USER ID - " << username << endl;

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
    char Electrician[32];
    char Plumber[32];
    char Cleaner[32];

public:
    hostel_info()
    {
    }
    string get_electrician()
    {
        string str(Electrician);
        return str;
    }
    string get_plumber()
    {
        string str(Plumber);
        return str;
    }
    string get_cleaner()
    {
        string str(Cleaner);
        return str;
    }

    void set_services_info()
    {
        cout << "Enter Electrician's Contact - ";
        cin >> Electrician;
        cout << "Enter Plumber's Contact - ";
        cin >> Plumber;
        cout << "Enter Cleaner's Contact - ";
        cin >> Cleaner;
    }
    void get_services_info()
    {
        cout << "\nServices Info"
             << endl;
        cout << "Electrician's Contact - " << get_electrician() << endl;

        cout << "Plumber's Contact - " << get_plumber() << endl;

        cout << "Cleaner's Contact - " << get_cleaner() << endl;
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
    int residents[2];

public:
    room()
    {
        setcapacity();
    }

    int get_vacancy()
    {
        return capacity - occupancy;
    }

    void setcapacity(int x = 2)
    {
        capacity = x;
        occupancy = 0;
    }

    void addstudent(int s)
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
};

class warden
{
    char uname[32];
    char password[32];

public:
    void set_warden()
    {
        cout << "Enter warden username - ";
        cin >> uname;
        cout << "Enter Password - ";
        cin >> password;
    }
    string get_warden_uname()
    {
        string str(uname);
        return str;
    }
    string get_warden_password()
    {
        string str(password);
        return str;
    }
    bool warden_login()
    {
        string u;
        string p;
        cout << "\n Enter username : ";
        cin >> u;
        cout << "\n Enter password : ";
        cin >> p;

        if (uname == u && password == p)
        {
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

class hostel
{
    char hostel_name[32];

    room room_list[10];

public:
    inventory stock;
    hostel_info info;
    warden w;

    void set_hostel_info()
    {
        cout << "Enter Hostel Name - ";
        cin >> hostel_name;
        w.set_warden();
        info.set_services_info();
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
        string str(hostel_name);
        return str;
    }

    void print_hostel_info()
    {
        cout << "Name of Hostel: " << getname() << endl;
        cout << "Username of the warden : " << w.get_warden_uname() << endl;
        cout << "Password : " << w.get_warden_password() << endl;
        info.get_services_info();
    }
    int give_room(int r)
    {
        int i;
        for (i = 0; i < 10; i++)
        {
            if (room_list[i].get_vacancy() > 0)
            {
                room_list[i].addstudent(r);
                break;
            }
        }
        return i + 1;
    }
    friend class warden;
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

void HostelList()
{
    ifstream file1;
    file1.open("hostel.txt", ios::in);

    hostel temp;
    file1.read((char *)&temp, sizeof(temp));

    while (!file1.eof())
    {

        temp.print_hostel_info();

        file1.read((char *)&temp, sizeof(temp));
        cout << "\n\n"
             << endl;
    }
    file1.close();
}

int adminView();
int studentView();
int studentLogin();
void registerstudent();

void AddHostel()
{
    hostel h;
    h.set_hostel_info();

    ofstream file;
    file.open("hostel.txt", ios::app);

    file.write((char *)&h, sizeof(h));

    file.close();
}

void ListofStudent()
{
    ifstream file1;
    file1.open("student.txt", ios::in);

    student temp;
    file1.read((char *)&temp, sizeof(temp));

    while (!file1.eof())
    {

        temp.print_info();
        temp.get_CIS_id();

        file1.read((char *)&temp, sizeof(temp));
        cout << "\n\n"
             << endl;
    }
    cout << "\n\n"
         << endl;
    file1.close();
}

int adminView()
{
    int goBack = 0;

    while (1)
    {
        system("cls");
        cout << "\n 1 Register a Student";
        cout << "\n 2 Add Hostel";
        cout << "\n 3 List of Hostels";
        cout << "\n 4 Allot hostel to a Student";
        cout << "\n 6 Student's List";
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
            AddHostel();
            break;
        case 4:
            cout << "Enter Registration number of the Student - ";
            int k;
            cin >> k;
            AllotHostel(k);
            break;
        case 3:
            check_hostel();
            getchar();
            getchar();
            break;
        case 5:
            //			checkPresenseCountbyRollno();
            break;
        case 6:
            ListofStudent();
            getchar();
            getchar();
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

void AllotRoom()
{
}

int wardenView()
{
    int goBack = 0;

    bool flag = 0;
    int res = 0;
    string n;
    cout << "Enter warden's Hostel Name : ";
    cin >> n;
    // getline(cin, n);

    fstream file1;
    file1.open("hostel.txt", ios::in | ios::out);

    hostel h;
    int i = 0;
    file1.read((char *)&h, sizeof(h));

    while (!file1.eof())
    {

        if (h.getname().compare(n) == 0)
        {
            res = h.w.warden_login();

            if (res)
            {
                break;
            }
            else
            {
                return 0;
            }

            // if (s.set_hostel())
            // {
            //     cout << "Successfully Alloted\n";
            //     file1.seekp(sizeof(s) * i);
            //     file1.write((char *)&s, sizeof(s));
            //     break;
            // }
            // else
            //     cout << "Already Alloted\n";
        }
        file1.read((char *)&h, sizeof(h));
        i++;
    }
    // file1.close();

    if (res == 0)
    {
        cout << "Invalid Hostel" << endl;
        return 0;
    }

    while (1)
    {
        system("cls");
        cout << "\n 1 Allot Room to a Student";
        cout << "\n 2 Check Room Vacancy";
        cout << "\n 3 Student's List";
        cout << "\n 4 Provide Room Amenities";
        cout << "\n 5 Mess Bill";
        cout << "\n 6 Fine Section";
        cout << "\n 0. Go Back <- \n";
        int choice;
        cout << "\n Enter you choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int num;
            cout << "Enter Registration Number : ";
            cin >> num;
            ifstream file2;
            file2.open("student.txt", ios::in | ios::out);

            student temp;
            file2.read((char *)&temp, sizeof(temp));

            while (!file2.eof())
            {
                if (temp.get_reg_num() == num)
                {
                    if (n.compare(temp.get_hostel()) == 0)
                    {
                        if (temp.get_room() == -1)
                        {
                            cout << "Allotment in process" << endl;
                            int x = h.give_room(num);
                        }
                    }
                }

                file2.read((char *)&temp, sizeof(temp));
            }
            // file2.close();
            AllotRoom();
            break;
        case 2:
            // AddRoom();
            break;
        case 3:
            ListofStudent();
            getchar();
            getchar();
            break;
        case 4:
            cout << "Enter Current Month Mess Bill - ";
            // MessBill();
            break;
        case 5:
            cout << "Enter Current Month Mess Bill - ";
            // MessBill();
            break;
        case 6:
            // FineManagement();
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

    admin(string uname, string pass)
    {
        username = uname;
        password = pass;
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

void ListofStudentinHostel()
{
    bool flag = 0;
    string n;
    cout << "Enter warden's Hostel Name : ";
    cin >> n;

    fstream file1;
    file1.open("hostel.txt", ios::in | ios::out);

    hostel h;
    int i = 0;
    file1.read((char *)&h, sizeof(h));

    while (!file1.eof())
    {

        if (h.getname().compare(n) == 0)
        {
            // h.s.get_name_of_student();
        }
        file1.read((char *)&h, sizeof(h));
        i++;
    }
    file1.close();
}

int studentLogin()
{
    system("cls");
    cout << "\n -------- Student Login ---------";
    studentView();

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

        if ((temp.get_user_id().compare(username) == 0) && (temp.get_password().compare(password) == 0))
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

void registerstudent()
{
    cout << "\n ----- Student Registration Form ---- \n";

    getchar();
    student s;
    s.set_info_of_student();
    cout << endl;
    s.print_info();
    s.get_CIS_id();
    getchar();
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
        cout << "\n\n"
             << temp.getname() << "--> " << temp.check_vacancy() << endl;
        temp.print_hostel_info();
        file1.read((char *)&temp, sizeof(temp));
    }
    file1.close();
}

void AllotHostel(int reg)
{
    fstream file1;
    file1.open("student.txt", ios::in | ios::out);

    student s;
    int i = 0;
    file1.read((char *)&s, sizeof(s));

    while (!file1.eof())
    {

        if (s.get_reg_num() == reg)
        {
            if (s.set_hostel())
            {
                cout << "Successfully Alloted\n";
                file1.seekp(sizeof(s) * i);
                file1.write((char *)&s, sizeof(s));
                break;
            }
            else
                cout << "Already Alloted\n";
        }

        //		temp.print_hostel_info();
        file1.read((char *)&s, sizeof(s));
        i++;
    }
    file1.close();
}

bool check_warden_credentials()
{
    bool flag = 0;
    string n;
    cout << "Enter warden's Hostel Name : ";
    cin >> n;
    // getline(cin, n);

    fstream file1;
    file1.open("hostel.txt", ios::in | ios::out);

    hostel h;
    int i = 0;
    file1.read((char *)&h, sizeof(h));

    while (!file1.eof())
    {

        if (h.getname().compare(n) == 0)
        {
            int res = h.w.warden_login();

            if (res)
            {
                wardenView();
            }
            else
            {
                return 0;
            }

            // if (s.set_hostel())
            // {
            //     cout << "Successfully Alloted\n";
            //     file1.seekp(sizeof(s) * i);
            //     file1.write((char *)&s, sizeof(s));
            //     break;
            // }
            // else
            //     cout << "Already Alloted\n";
        }
        file1.read((char *)&h, sizeof(h));
        i++;
    }
    file1.close();
}

void title();
int main()
{
    admin a;
    warden wd;
    while (1)
    {
        system("cls");
        title();

        cout << "1. Hostel Student Login\n";
        cout << "2. Hostel Admin Login\n";
        cout << "3. Hostel Warden Login\n";
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
        case 3:
            check_warden_credentials();
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
