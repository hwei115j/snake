#include "sna.h"
#include <conio.h>
#include <windows.h>

void os_clean()
{
	int x, y;
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	x = y = 0;
	static HANDLE hConsole = 0;
	static int InstanceCount = 0;
	COORD coord;
	if (!InstanceCount) {
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		InstanceCount = 1;
	}
	coord.X = x, coord.Y = y;
	SetConsoleCursorPosition(hConsole, coord);

    CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
    SetConsoleCursorInfo(hout, &cursor_info);
}

int os_keyboard()
{
    static int n = UP;

    if (_kbhit())
    {
        _getch();
        switch (_getch())
        {
            case UP:
                n = UP;
                break;
            case DOWN:
                n = DOWN;
                break;
            case LEFT:
                n = LEFT;
                break;
            case RIGHT:
                n = RIGHT;
                break;
        }
    }

    return n;
}

void os_sleep(int n)
{
    Sleep(n);
}
