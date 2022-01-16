#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "create-contact.h"
using namespace std;

int main()
{
    while (1)
    {
        system("cls");
        int choice;
        cout << "PHONEBOOK MANAGEMENT SYSTEM\n\n";
        cout << "Choose from the following operations: \n";
        cout << "1. Add a Contact\n";
        cout << "2. Remove a Contact\n";
        cout << "3. Search a Contact\n";
        cout << "4. Edit a Contact\n";
        cout << "\nYour Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            CreateContact contact;
            contact.getDetails();
            // bool isTrue = contact.confirmDetails();
            contact.addContact();
        }
    }
    return 0;
}