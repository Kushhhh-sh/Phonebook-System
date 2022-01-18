#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <conio.h>
#include <cstring>
#include <windows.h>
using namespace std;

void gotoAdd(short int x, short int y)
{
    COORD p = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

class AddContact
{
private:
    string contactName;
    long long int *mobileNumber;
    int no_of_contacts;

public:
    void getDetails()
    {
        system("cls");
        cout << endl;
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        cout << "\t\t\t\t|                  PHONEBOOK MANAGEMENT SYSTEM                 |\n";
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        cout << "\t\t\t\t|             One Place To Manage All Your Contacts            |\n";
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        cout << "\t\t\t\t|                         ADD CONTACTS                         |\n";
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        cout << "\t\t\t\t|  Enter the Name of the contact:                              |\n";
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        gotoAdd(66, 9);
        getline(cin >> ws, contactName);
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        cout << "\t\t\t\t|  Enter the number of Phone Numbers:                          |\n";
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        gotoAdd(70, 11);
        cin >> no_of_contacts;
        mobileNumber = (long long int *)malloc(sizeof(long long int) * no_of_contacts);
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        cout << "\t\t\t\t|  Enter the Contact Numbers (Separated By Spaces):            |\n";
        cout << "\t\t\t\t|                                                              |\n";
        cout << "\t\t\t\t|                                                              |\n";
        cout << "\t\t\t\t|                                                              |\n";
        cout << "\t\t\t\t|                                                              |\n";
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        gotoAdd(35, 14);
        for (int i = 0; i < no_of_contacts; i++)
            cin >> mobileNumber[i];
    }

    void addContact()
    {
        system("cls");

        ofstream out;
        out.open("contact-list.txt", ios_base::app);
        out << contactName;
        for(int i = 0; i < (30 - contactName.length()); i++)
            out << " ";

        for (int i = 0; i < no_of_contacts; i++)
        {
            out << mobileNumber[i] << " / ";
        }
        out << "\n";
        out.close();

        system("cls");
        cout << endl;
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        cout << "\t\t\t\t|                  PHONEBOOK MANAGEMENT SYSTEM                 |\n";
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        cout << "\t\t\t\t|             One Place To Manage All Your Contacts            |\n";
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        cout << "\t\t\t\t|                         ADD CONTACTS                         |\n";
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        cout << "\t\t\t\t|                                                              |\n";
        cout << "\t\t\t\t|  CONTACT ADDED SUCCESSFULLY..!!                              |\n";
        cout << "\t\t\t\t|                                                              |\n";
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        getch();
    }
};