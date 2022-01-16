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
    string token;
    ifstream stream;

public:
    SearchContacts(string token)
    {
        transform(token.begin(), token.end(), token.begin(), ::tolower);
        stream.open("contact-list.txt");
        bool foundItem = false;

        cout << "\n\nSearch Results for " << token << ": \n\n";

        while (getline(stream, s))
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
            cout << token << " not found" << endl;
        getch();
    }

    ~SearchContacts()
    {
        stream.close();
    }
};