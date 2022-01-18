#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

class DisplayContacts
{
    ifstream in;

public:
    DisplayContacts()
    {
        system("cls");
        in.open("contact-list.txt");
        cout << endl;
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        cout << "\t\t\t\t|                  PHONEBOOK MANAGEMENT SYSTEM                 |\n";
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        cout << "\t\t\t\t|             One Place To Manage All Your Contacts            |\n";
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        cout << "\t\t\t\t|                       YOUR CONTACT LIST                      |\n";
        cout << "\t\t\t\t----------------------------------------------------------------\n\n";
        string s;
        while (getline(in, s))
            cout << "\t\t\t\t   " << s << endl;
        getch();
    }

    ~DisplayContacts()
    {
        in.close();
    }
};