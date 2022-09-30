#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>
void setcolor(int fg, int bg)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}

void setcursor(bool visible)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console, &lpCursor);
}
void draw_ship(int x, int y)
{

    COORD c = {x, y};
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);
    printf(" <-0-> ");
   setcolor(0,0);
}
void erase_ship(int x, int y)
{
    COORD c = {x, y};
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);
    printf("               ");
    setcolor(2,4);
}
int main()
{
    char ch = ' ';
    int x = 38, y = 20;
    draw_ship(x, y);
    do
    {
        if (_kbhit())
        {
            ch = _getch();
            if (ch == 'a' && x > 0)
            {
                erase_ship(x, y);
                draw_ship(--x, y);
            }
            if (ch == 'd' && x < 100)
            {
                erase_ship(x, y);
                draw_ship(++x, y);
            }
            if (ch == 'w' && y > 0)
            {
                erase_ship(x, y);
                draw_ship(x, --y);
            }
            if (ch == 's' && y < 80)
            {
                erase_ship(x, y);
                draw_ship(x, ++y);
            }
            fflush(stdin);
        }
        Sleep(500);
    } while (ch != 'x');
    return 0;
}