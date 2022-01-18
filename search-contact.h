#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <bits/stdc++.h>
using namespace std;

void gotoSearch(short int x, short int y)
{
    COORD p = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

class SearchContacts
{
private:
    string s, token;
    ifstream in;

public:
    SearchContacts()
    {
        system("cls");
        cout << endl;
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        cout << "\t\t\t\t|                  PHONEBOOK MANAGEMENT SYSTEM                 |\n";
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        cout << "\t\t\t\t|             One Place To Manage All Your Contacts            |\n";
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        cout << "\t\t\t\t|                        SEARCH CONTACTS                       |\n";
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        cout << "\t\t\t\t|  Enter the Keyword you want to search:                       |\n";
        cout << "\t\t\t\t----------------------------------------------------------------\n";
        gotoSearch(73, 9);
        cin >> token;
        transform(token.begin(), token.end(), token.begin(), ::tolower);
        in.open("contact-list.txt");
        bool foundItem = false;

        cout << "\n\t\t\t\t   Search Results for " << token << ": \n\n";
        cout << "\t\t\t\t   ContactName                   ContactNumber\n\t\t\t\t   ----------------------------------------------\n";

        while (getline(in, s))
        {
            string g = s;
            transform(g.begin(), g.end(), g.begin(), ::tolower);
            if (g.find(token) != string::npos)
            {
                foundItem = true;
                cout << "\t\t\t\t   " << s << endl;
            }
        }
        if (!foundItem)
        {
            cout << "\t\t\t\t----------------------------------------------------------------\n";
            cout << "\t\t\t\t|  NO CONTACTS FOUND..!!                                       |\n";
            cout << "\t\t\t\t----------------------------------------------------------------\n";
        }
        getch();
    }

    ~SearchContacts()
    {
        in.close();
    }
};