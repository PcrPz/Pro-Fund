 #include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>
void setcolor(int fg,int bg)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void draw_ship(int x, int y)
{

    COORD c = {x, y};
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);
    printf(" <-::1::-> ");
    
}
void erase_ship(int x, int y)
{

    COORD c = {x, y};
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);
    printf("               ");

}
void setcursor(bool visible)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console, &lpCursor);
}

int main()
{
    char ch = ' ';
    int x = 38, y = 20;
    draw_ship(x, y);
    int direc;
    do
    {
        if (_kbhit())
        {
            setcursor(0);
            ch = _getch();
            if (ch == 'a' || ch == 'A' )
            {
                direc = 1;
            }
            if (ch == 'd' || ch == 'D' )
            {
                direc = 2;
            }
            if (ch == 's' || ch == 'S' )
            {
                direc = 3;
            }
            fflush(stdin);
        }
        if (direc != 0)
        {
            if (direc == 1 && x < 100)
            {
                erase_ship(x, y);
                draw_ship(--x, y);
                
                
            }
            if (direc == 2 && x < 100)
            {
                erase_ship(x, y);
                draw_ship(++x, y);
                
                
            }
            if (direc == 3 && x < 100)
            {erase_ship(x, y);
                draw_ship(x, y);
                setcolor(2,4);
                erase_ship(x, y);
            }
            Sleep(100);
        }

    } while (ch != 'x');
    return 0;
}