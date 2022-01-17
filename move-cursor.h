#ifdef _WIN32

#include <windows.h>

void gotoxy(short int x, short int y)
{
    COORD p = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

#else

#include <unistd.h>
#include <term.h>

void gotoxy(int x, int y)
{
    int err;
    if (!cur_term)
        if (setupterm(NULL, STDOUT_FILENO, &err) == ERR)
            return;
    putp(tparm(tigetstr("cup"), y, x, 0, 0, 0, 0, 0, 0, 0));
}

#endif