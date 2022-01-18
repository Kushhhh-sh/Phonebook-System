#include <iostream>
#include <stdlib.h>
#include "add-contact.h"
#include "display-contacts.h"
#include "search-contact.h"
#include "remove-contact.h"
#include "edit-contact.h"
#include "move-cursor.h"
using namespace std;

int main()
{
    string token;
    while (1)
    {
        system("cls");
        int choice;

        cout << endl;
        cout << "\t\t\t\t------------------------------------------------------\n";
        cout << "\t\t\t\t|            PHONEBOOK MANAGEMENT SYSTEM             |\n";
        cout << "\t\t\t\t------------------------------------------------------\n";
        cout << "\t\t\t\t|       One Place To Manage All Your Contacts        |\n";
        cout << "\t\t\t\t------------------------------------------------------\n";
        cout << "\t\t\t\t|                                                    |\n";
        cout << "\t\t\t\t|  1. Add a New Contact                              |\n";
        cout << "\t\t\t\t|                                                    |\n";
        cout << "\t\t\t\t|  2. Delete an Existing Contact                     |\n";
        cout << "\t\t\t\t|                                                    |\n";
        cout << "\t\t\t\t|  3. Search a Contact                               |\n";
        cout << "\t\t\t\t|                                                    |\n";
        cout << "\t\t\t\t|  4. Edit an existing Contact                       |\n";
        cout << "\t\t\t\t|                                                    |\n";
        cout << "\t\t\t\t|  5. Display the Contact List                       |\n";
        cout << "\t\t\t\t|                                                    |\n";
        cout << "\t\t\t\t------------------------------------------------------\n";
        cout << "\t\t\t\t|  6. About                     0. Exit              |\n";
        cout << "\t\t\t\t------------------------------------------------------\n";
        cout << "\t\t\t\t|  Your Choice:                                      |\n";
        cout << "\t\t\t\t------------------------------------------------------\n";
        gotoxy(48, 20);
        cin >> choice;

        if (choice == 1)
        {
            AddContact contact;
            contact.getDetails();
            contact.addContact();
        }
        else if(choice == 2)
            RemoveContact remove;
        else if(choice == 3)            
            SearchContacts search;
        else if(choice == 4)           
            EditContact edit;
        else if(choice == 5)
            DisplayContacts d;
        else if(choice == 0)
        {
            system("cls");
            exit(1);
        }
    }
    return 0;
}