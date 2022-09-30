

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>
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
   setcolor(2,4);
    gotoxy(x, y);
    printf(" <-::1::-> ");
}
void erase_ship(int x, int y)
{
 setcolor(7,0);
    gotoxy(x, y);
    printf("               ");
}
void bullet(int bulletx, int bullety)
{
 setcolor(2,4);
    gotoxy(bulletx, bullety);
    printf("I");
}
void bulletremove(int bulletx, int bullety)
{ setcolor(7,0);
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

int main()
{
    char ch = ' ';
    int x = 50, y = 28;
    draw_ship(x, y);
    int direc;
    int Shooting[5]=0,0,0,0,0;
    int bulletx[5]=50,50,50,50,50;
    int bullety[5]=28,28,28,28,28;
    int i=0,int n=0;
    do
    { //เช็คปุ่ม
    if (i>=5)
    {
       i=0;
    }
    
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
          
            if (ch == ' ' && Shooting[i] != 1 && Shooting [i-1] !=1)
            {
                Shooting[i] = 1;
                bulletx[i] = x + 5;
                bullety[i] = y - 1;
                i++;
            }
            fflush(stdin);
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
        while(n<5){
            if (Shooting[n] == 1)
            {
                bulletremove(bulletx[i], bullety[n]);
                if (bullety[n] == 0)
                {
                    Shooting[n] = 0;
                }
                else
                {
                    bullet(bulletx[n], --bullety[n]);
                }
                Sleep(20);
            }
            n++;}
            Sleep(100);
    } 
     while (ch != 'x');
    return 0;
}