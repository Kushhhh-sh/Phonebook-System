#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <bits/stdc++.h>
using namespace std;

class SearchContacts
{
private:
    string s;
    ifstream in;

public:
    SearchContacts(string token)
    {
        transform(token.begin(), token.end(), token.begin(), ::tolower);
        in.open("contact-list.txt");
        bool foundItem = false;

        cout << "\n\nSearch Results for " << token << ": \n\n";
        cout << "ContactName                 ContactNumber\n----------------------------------------------\n";

        while (getline(in, s))
        {
            string g = s;
            transform(g.begin(), g.end(), g.begin(), ::tolower);
            if (g.find(token) != string::npos)
            {
                foundItem = true;
                cout << s << endl;
            }
        }
        if (!foundItem)
            cout << "No Contacts Found Named: " << token << endl;
        getch();
    }

    ~SearchContacts()
    {
        in.close();
    }
};