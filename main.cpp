#include <bits/stdc++.h>
#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

void title();
void login_system();

class Hostel
{
private:
    string username;
    string password;
    string mode;

public:
    void login()
    {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        if (username == "admin" && password == "admin@123")
        {
            cout << "Admin Mode...." << endl;
            mode = "admin";
        }
        else
        {
            cout << "student mode..." << endl;
            mode = "student";
        }
    }

    void showMenu()
    {
        if (mode == "admin")
        {
            cout << "Welcome, Admin!" << endl;
            cout << "1. Add student record" << endl;
            cout << "2. View all student records" << endl;
            cout << "3. Log out" << endl;
            int choice;
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "Add student record selected." << endl;
                break;
            case 2:
                cout << "View all student records selected." << endl;
                break;
            case 3:
                cout << "Log out selected." << endl;
                break;
            default:
                cout << "Invalid option selected." << endl;
            }
        }
        else if (mode == "student")
        {
            cout << "Welcome, Student!" << endl;
            cout << "1. View hostel details" << endl;
            cout << "2. View mess menu" << endl;
            cout << "3. Log out" << endl;
            int choice;
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "View hostel details selected." << endl;
                break;
            case 2:
                cout << "View mess menu selected." << endl;
                break;
            case 3:
                cout << "Log out selected." << endl;
                break;
            default:
                cout << "Invalid option selected." << endl;
            }
        }
        else
        {
            cout << "Invalid mode entered." << endl;
        }
    }
};

int main()
{
    title();
    Hostel hs;
    hs.login();
    hs.showMenu();
    return 0;
}

class login
{
};

// int main()
// {
//     title();
//     login_system();

//     return 0;
// }

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

void login_system()
{
    cout << "Enter 1 for Admin Mode Login " << endl;
    cout << "Enter 2 for Student Mode Login " << endl;

    int choice;
    cin >> choice;
    if (choice == 1)
    {
        string uname, pass;

        cout << "Enter Username: ";
        cin >> uname;

        cout << "Enter Password: ";
        cin >> pass;
    }
}