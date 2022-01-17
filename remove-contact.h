#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <conio.h>
#include<bits/stdc++.h>
using namespace std;

class RemoveContact
{
private:
    string line;
    ifstream in;
    ofstream out;
    bool contactDeleted = false;
public:
    RemoveContact(string name)
    {
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        in.open("contact-list.txt");
        out.open("temp.txt");
        while(getline(in, line))
        {
            string g = line;
            transform(g.begin(), g.end(), g.begin(), ::tolower);
            if(g.find(name) == string::npos)
            {
                out << line << "\n";
            }
            else
            {
                contactDeleted = true;
                cout << "\nDeleted Contact: \n" << line;
                getch();
            }
        }
        if(!contactDeleted)
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