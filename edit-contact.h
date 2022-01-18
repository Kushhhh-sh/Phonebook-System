#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <bits/stdc++.h>
using namespace std;

void gotoEdit(short int x, short int y)
{
    COORD p = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

class EditContact
{
private:
    string n, name;
    long long int *mobileNo;
    int no_of_contacts;
    string line;
    ifstream in;
    ofstream out;
    bool contactEdited = false;

public:
    EditContact()
    {
        system("cls");
        cout << endl;
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        cout << "\t\t\t\t|                  PHONEBOOK MANAGEMENT SYSTEM                 |\n";
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        cout << "\t\t\t\t|             One Place To Manage All Your Contacts            |\n";
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        cout << "\t\t\t\t|                         EDIT CONTACTS                        |\n";
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        cout << "\t\t\t\t|  Enter the Name of the contact                               |\n";
        cout << "\t\t\t\t|  you want to edit:                                           |\n";
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        gotoEdit(53, 10);
        getline(cin >> ws, name);
        n = name;
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        in.open("contact-list.txt");
        out.open("temp.txt");
        while (getline(in, line))
        {
            string g = line;
            transform(g.begin(), g.end(), g.begin(), ::tolower);
            if (g.find(name) == string::npos)
            {
                out << line << "\n";
            }
            else
            {
                contactEdited = true;
                cout << "\t\t\t\t----------------------------------------------------------------\n";
                cout << "\t\t\t\t|  Enter the number of Phone Numbers:                          |\n";
                cout << "\t\t\t\t----------------------------------------------------------------\n";
                gotoEdit(70, 12);
                cin >> no_of_contacts;
                mobileNo = (long long int *)malloc(sizeof(long long int) * no_of_contacts);
                cout << "\t\t\t\t----------------------------------------------------------------\n";
                cout << "\t\t\t\t|  Enter the Contact Numbers (Separated By Spaces):            |\n";
                cout << "\t\t\t\t|                                                              |\n";
                cout << "\t\t\t\t|                                                              |\n";
                cout << "\t\t\t\t|                                                              |\n";
                cout << "\t\t\t\t|                                                              |\n";
                cout << "\t\t\t\t----------------------------------------------------------------\n";
                gotoEdit(35, 15);
                for (int i = 0; i < no_of_contacts; i++)
                    cin >> mobileNo[i];
                addEditedContact();
            }
        }
        if (!contactEdited)
        {
            cout << "\t\t\t\t----------------------------------------------------------------\n";
            cout << "\t\t\t\t|                                                              |\n";
            cout << "\t\t\t\t|  NO CONTACT FOUND                                            |\n";
            cout << "\t\t\t\t|  EDITING CONTACTS ABORTED..!!                                |\n";
            cout << "\t\t\t\t|                                                              |\n";
            cout << "\t\t\t\t----------------------------------------------------------------\n";
            getch();
        }
        else
        {
            system("cls");
            cout << endl;
            cout << "\t\t\t\t----------------------------------------------------------------\n";
            cout << "\t\t\t\t|                  PHONEBOOK MANAGEMENT SYSTEM                 |\n";
            cout << "\t\t\t\t----------------------------------------------------------------\n";
            cout << "\t\t\t\t|             One Place To Manage All Your Contacts            |\n";
            cout << "\t\t\t\t----------------------------------------------------------------\n";
            cout << "\t\t\t\t|                         EDIT CONTACTS                        |\n";
            cout << "\t\t\t\t----------------------------------------------------------------\n";
            cout << "\t\t\t\t|                                                              |\n";
            cout << "\t\t\t\t|  CONTACT EDITED SUCCESSFULLY..!!                             |\n";
            cout << "\t\t\t\t|                                                              |\n";
            cout << "\t\t\t\t----------------------------------------------------------------\n";
            getch();
        }
    }

    void addEditedContact()
    {
        // out.open("temp.txt", ios_base::app);
        out << n;

        for (int i = 0; i < (30 - n.length()); i++)
            out << " ";

        for (int i = 0; i < no_of_contacts; i++)
        {
            out << mobileNo[i] << " / ";
        }
        out << "\n";
    }

    ~EditContact()
    {
        out.close();
        in.close();
        remove("contact-list.txt");
        rename("temp.txt", "contact-list.txt");
    }
};