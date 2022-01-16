#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

class SearchContacts
{
private:
    string s;
    string token;
    ifstream stream;

public:
    SearchContacts()
    {
        system("cls");
        cout << "Enter the Keyword you want to search: ";
        cin >> token;
        stream.open("contact-list.txt");
        bool foundItem = false;

        cout << "\n\nSearch Results for " << token << ": \n\n";

        while (getline(stream, s))
        {
            if (s.find(token) != string::npos)
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

// void Keyword(, string token)
// {
//     string line;
// }