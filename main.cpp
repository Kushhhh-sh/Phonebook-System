#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

int main()
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
    return 0;
}