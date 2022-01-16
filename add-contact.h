#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include<cstring>
using namespace std;

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
        cout << "Enter the Name of the contact: ";
        getline(cin >> ws, contactName);
        cout << "How many Phone numbers would you like to save under Contact name " << contactName << "? : ";
        cin >> no_of_contacts;
        mobileNumber = (long long int *)malloc(sizeof(long long int) * no_of_contacts);
        cout << "Enter the Contact Numbers: \n";
        for (int i = 0; i < no_of_contacts; i++)
            cin >> mobileNumber[i];
    }

    bool confirmDetails()
    {
        string decision;
        cout << "You have Entered: " << contactName << " - ";
        for (int i = 0; i < no_of_contacts; i++)
        {
            cout << mobileNumber[i] << " / ";
        }
        cout << "\nAre you sure? (Yes/No): ";
        cin >> decision;
        if (decision == "Yes")
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void addContact()
    {
        system("cls");
        bool isTrue = confirmDetails();
        if (isTrue)
        {
            ofstream out;
            out.open("contact-list.txt", ios_base::app);
            out << contactName;
            
            if(contactName.length() > 7)
                out << "\t\t\t\t\t";
            else
                out << "\t\t\t\t\t\t";

            for(int i = 0; i < no_of_contacts; i++)
            {
                out << mobileNumber[i] << " / ";
            }
            out << "\n";
            out.close();
        }
        else    
            cout << "Error";
    }
};