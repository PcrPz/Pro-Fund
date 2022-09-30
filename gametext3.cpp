#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>
#include <time.h>
#include <thread>
#include <mutex>
void setcolor(int fg, int bg)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void gotoxy(int x, int y)
{
    COORD c = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x, int y)
{
    setcolor(0, 3);
    gotoxy(x, y);
    printf(" <-::1::-> ");
}
void erase_ship(int x, int y)
{
    setcolor(7, 0);
    gotoxy(x, y);
    printf("               ");
}
void bullet(int bulletx, int bullety)
{
    setcolor(0, 2);
    gotoxy(bulletx, bullety);
    printf("$");
}
void bulletremove(int bulletx, int bullety)
{
    setcolor(7, 0);
    gotoxy(bulletx, bullety);
    printf(" ");
}
void setcursor(bool visible)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console, &lpCursor);
}
void star(int sx, int sy)
{
    setcolor(2, 0);
    gotoxy(sx, sy);
    printf("*");
}
char cursor(int x, int y)
{
    HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
    char buf[2];
    COORD c = {x, y};
    DWORD num_read;
    if (
        !ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))

        return '\0';
    else
        return buf[0];
}

int main()
{
    char ch = ' ';
    int x = 50, y = 28;
    draw_ship(x, y);
    int direc;
    int Shooting[6] = {1, 0, 0, 0, 0, 0};
    int bulletx[6] = {0, 50, 50, 50, 50, 50};
    int bullety[6] = {0, 28, 28, 28, 28, 28};
    int i = 1, n = 1;
    int sx, sy;
    int s;
    srand(time(NULL));
    for (s = 0; s < 20; s++)
    {
        sx = 10 + rand() % 70;
        sy = 2 + rand() % 5;
        star(sx, sy);
    }
    do
    { //เช็คปุ่ม
        if (_kbhit())
        {
            setcursor(0);
            ch = _getch();
            if (ch == 'a' || ch == 'A')
            {
                direc = 1;
            }
            if (ch == 'd' || ch == 'D')
            {
                direc = 2;
            }
            if (ch == 's' || ch == 'S')
            {
                direc = 3;
            }

            if (ch == ' ' && Shooting[i] != 1 && Shooting[i - 1] == 1)
            {
                Shooting[i] = 1;
                bulletx[i] = x + 5;
                bullety[i] = y - 1;
                i++;
            }
            fflush(stdin);
        }
        if (i == 6)
        {
            i = 1;
        } //ทิศทาง
        if (direc != 0)
        {
            if (direc == 1 && x > 0)
            {
                erase_ship(x, y);
                draw_ship(--x, y);
            }
            if (direc == 2 && x < 108)
            {

                erase_ship(x, y);
                draw_ship(++x, y);
            }
            if (direc == 3)
            {
                draw_ship(x, y);
            }
        }
        if (n == 6)
        {
            n = 1;
        }
        for (n = 1; n < 6; n++)
        {
            if (Shooting[n] == 1)
            {
                bulletremove(bulletx[n], bullety[n]);
                if (bullety[n] == 0)
                {
                    Shooting[n] = 0;
                    if (n == i - 1)
                    {
                        i = 1;
                    }
                }

                else
                {

                        bullet(bulletx[n], --bullety[n]);
                }

                Sleep(10);
            }
        }

        Sleep(100);
    } while (ch != 'x');
    return 0;
}