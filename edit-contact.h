#pragma once
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<conio.h>
#include<bits/stdc++.h>
using namespace std;

class EditContact
{
private:
    string n;
    long long int *mobileNo;
    int no_of_contacts;
    string line;
    ifstream in;
    ofstream out;
    bool contactEdited = false;
public:

    EditContact(string name)
    {
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
                cout << "\nEnter the new number of Phone Numbers for this contact: ";
                cin >> no_of_contacts;
                mobileNo = (long long int*) malloc(sizeof(long long int) * no_of_contacts);
                cout << "\nEnter the new Phone Numbers: \n";
                for(int i = 0; i < no_of_contacts; i++)
                    cin >> mobileNo[i];
                addEditedContact();
            }
        }
        if (!contactEdited)
        {
            cout << "\nNo Contact found named: " << name << endl;
            cout << "Editing Aborted..!!" << endl;
            getch();
        }
        else
        {
            cout << "\nContact Edited Successfully..!!" << endl;
            getch();
        }
    }

    void addEditedContact()
    {
        // out.open("temp.txt", ios_base::app);
        out << n;

        if (n.length() > 7)
            out << "\t\t    ";
        else
            out << "\t\t\t    ";

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