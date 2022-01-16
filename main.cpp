#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "add-contact.h"
#include "display-contacts.h"
#include "search-contact.h"
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
        cout << "5. Display Contact list\n";
        cout << "0. Exit\n";
        cout << "\nYour Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            AddContact contact;
            contact.getDetails();
            contact.addContact();
        }
        else if(choice == 3)
        {
            string token;
            system("cls");
            cout << "Enter the Keyword you want to search: ";
            cin >> token;
            SearchContacts search(token);
        }
        else if(choice == 5)
        {
            DisplayContacts d;
        }
        else if(choice == 0)
        {
            system("cls");
            exit(1);
        }
    }
    return 0;
}