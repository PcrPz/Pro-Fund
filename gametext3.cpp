#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>
#include <time.h>
#include <thread>
#include <mutex>
std::mutex mtx;
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
    setcolor(2, 0);
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
    setcolor(7, 0);
    gotoxy(sx, sy);
    printf("*");
}
void starremove(int sx, int sy)
{
    setcolor(0, 0);
    gotoxy(sx, sy);
    printf(" ");
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

// void starspawn(int totalround)
// {
//     srand(time(0));
//     for (s = 0; s < totalround; s++)
//     {
//         sx = 10 + rand() % 70;
//         sy = 2 + rand() % 5;
//         star(sx, sy);
//     }
// }
int s;
int sx, sy;
int totalround;
int direc;
int Shooting[6] = {1, 0, 0, 0, 0, 0};
int bulletx[6] = {0, 50, 50, 50, 50, 50};
int bullety[6] = {0, 28, 28, 28, 28, 28};
int checkcur[6] = {0, 0, 0, 0, 0, 0};
int i = 1, n = 1;
int nowstar = 0;
int starx[21] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int stary[21] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int numspawn = 20;
int checknum = 0;
int m;

void foundstar(int sx, int sy)
{
    starremove(sx, sy);
    bulletremove(sx, sy);
    std::thread q(Beep, 700, 500);
    q.detach();
}
void starspawn()
{
    srand(time(0));

    sx = 10 + rand() % 70;
    sy = 2 + rand() % 5;
    if (cursor(sx, sy) == '*' || bulletx[n] != sx)
    {
        sx = 10 + rand() % 70;
        sy = 2 + rand() % 5;
        star(sx, sy);
    }
    else
    {
        star(sx, sy);
    }
}

int main()
{
    char ch = ' ';
    int x = 50, y = 28;
    draw_ship(x, y);

    srand(time(0));
    for (s = 0; s < numspawn; s++)
    {
        starx[s] = 10 + rand() % 70;
        stary[s] = 2 + rand() % 5;
        star(starx[s], stary[s]);
        checknum++;
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
                else if (cursor(bulletx[n], bullety[n] - 1) == '*')
                {
                    foundstar(bulletx[n], bullety[n] - 1);
                    checknum = checknum - 1;
                    int oldstarx = bulletx[n], oldstary = bullety[n] - 1;

                    for (int j = 0; j < numspawn; j++)
                    {
                        if (starx[j] == oldstarx && stary[j] == oldstary)
                        {
                                starx[j] = 10 + rand() % 70;
                                stary[j] = 2 + rand() % 5;

                                for (int k = 0; k < numspawn; k++)
                                {
                                    for (int m = 0; m < 6; m++)
                                    {
                                        while ((starx[j] == bulletx[m] && stary[j] == bullety[m] - 1) || (starx[j] == starx[k] && stary[j] == stary[k]) && j != k)
                                        {
                                            starx[j] = 10 + rand() % 70;
                                            stary[j] = 2 + rand() % 5;
                                        }
                                        star(starx[j], stary[j]);
                                        break;
                                    }
                                    break;
                                }
                            break;
                        }
                    }
                    checknum++;

                    nowstar = nowstar + 1;
                    checkcur[n] = 1;
                    Shooting[n] = 0;
                    if (n == i - 1)
                    {
                        i = 1;
                    }
                }
                else if (checkcur[n] == 0 && bullety[n] != 0)
                {
                    bullet(bulletx[n], --bullety[n]);
                }
                checkcur[n] = 0;
            }
        }

        // mtx.lock();
        gotoxy(100, 5);
        printf("Score:%d  ", nowstar);
        // mtx.unlock();
        Sleep(100);
    } while (ch != 'x');
    return 0;
}