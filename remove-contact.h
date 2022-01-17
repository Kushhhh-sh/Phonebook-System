#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <conio.h>
#include <bits/stdc++.h>
using namespace std;

class RemoveContact
{
private:
    string line;
    string decision;
    ifstream in;
    ofstream out;
    bool contactDeleted = false;

public:
    RemoveContact(string name)
    {
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        in.open("contact-list.txt");
        out.open("temp.txt");
        while (getline(in, line))
        {
            string g = line;
            transform(g.begin(), g.end(), g.begin(), ::tolower);
            if (g.find(name) != string::npos)
            {
                cout << "Your are about to delete a contact named " << name << endl;
                cout << "Are you sure? (Yes/No) : ";
                cin >> decision;
                if (decision == "Yes")
                {
                    contactDeleted = true;
                    cout << "\nDeleted Contact: \n"
                         << line;
                    getch();
                }
                else
                {
                    contactDeleted = true;
                    out << line << "\n";
                    cout << "Deletion Aborted..!!" << endl;
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
            cout << "No Contact found named: " << name << endl;
            cout << "Deletion Aborted..!!" << endl;
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