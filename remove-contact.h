#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <conio.h>
#include<windows.h>
#include <bits/stdc++.h>
using namespace std;

void gotoRemove(short int x, short int y)
{
    COORD p = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

class RemoveContact
{
private:
    string line;
    string name;
    string decision;
    ifstream in;
    ofstream out;
    bool contactDeleted = false;

public:
    RemoveContact()
    {
        system("cls");
        cout << endl;
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        cout << "\t\t\t\t|                  PHONEBOOK MANAGEMENT SYSTEM                 |\n";
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        cout << "\t\t\t\t|             One Place To Manage All Your Contacts            |\n";
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        cout << "\t\t\t\t|  Enter the name of the contact you                           |\n";
        cout << "\t\t\t\t|  want to delete:                                             |\n";
        cout << "\t\t\t\t----------------------------------------------------------------\n";        
       
        gotoRemove(51, 8);
        getline(cin >> ws, name);
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        in.open("contact-list.txt");
        out.open("temp.txt");
        while (getline(in, line))
        {
            string g = line;
            transform(g.begin(), g.end(), g.begin(), ::tolower);
            if (g.find(name) != string::npos)
            {
                cout << "\t\t\t\t----------------------------------------------------------------\n";
                cout << "\t\t\t\t|  You are about to Delete a contact                           |\n";
                cout << "\t\t\t\t|  Are You Sure? (Yes/No) :                                    |\n";
                cout << "\t\t\t\t----------------------------------------------------------------\n";
                gotoRemove(60, 11);
                cin >> decision;
                if (decision == "Yes")
                {
                    contactDeleted = true;
                    cout << "\t\t\t\t----------------------------------------------------------------\n";
                    cout << "\t\t\t\t|  CONTACT DELETED..!!                                         |\n";
                    cout << "\t\t\t\t----------------------------------------------------------------\n";
                    getch();
                }
                else
                {
                    contactDeleted = true;
                    out << line << "\n";
                    cout << "\t\t\t\t----------------------------------------------------------------\n";
                    cout << "\t\t\t\t|  CONTACT DELETION ABORTED..!!                                 |\n";
                    cout << "\t\t\t\t----------------------------------------------------------------\n";
                    getch();
                }
            }
            else
            {
                out << line << "\n";
            }
        }
        if (!contactDeleted)
        {
            cout << "\t\t\t\t----------------------------------------------------------------\n";
            cout << "\t\t\t\t|  No Contacts Found..!!                                       |\n";
            cout << "\t\t\t\t|  Deletion Aborted..!!                                        |\n";
            cout << "\t\t\t\t----------------------------------------------------------------\n";
            getch();
        }
    }
    ~RemoveContact()
    {
        in.close();
        out.close();
        remove("contact-list.txt");
        rename("temp.txt", "contact-list.txt");
    }
};