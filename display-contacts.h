#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

class DisplayContacts
{
    ifstream in;

public:
    DisplayContacts()
    {
        system("cls");
        in.open("contact-list.txt");

        string s;
        while (getline(in, s))
            cout << s << endl;
        getch();
    }

    ~DisplayContacts()
    {
        in.close();
    }
};