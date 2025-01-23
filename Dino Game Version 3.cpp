#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y) 
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void delay(unsigned int mseconds) 
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void title()
{
	gotoxy(33, 6);
	cout<<"�����������������";
	gotoxy(33, 7);
	cout<<"�               �";
	gotoxy(33, 8);
	cout<<"�   Dino Game   �";
	gotoxy(33, 9);
	cout<<"�               �";
	gotoxy(33, 10);
	cout<<"�����������������";
	gotoxy(33, 12);
	cout<<"by:";
	gotoxy(33, 13);
	cout<<"Arshahad Ali";
	gotoxy(33, 14);
	cout<<"Syed Asjad Ali";
	gotoxy(33, 15);
	cout<<"Abdul-Rehman Arshad";
	_getch();
}

void getup() 
{
    system("cls");
    gotoxy(10, 2);
    cout << "Press X to Exit, Press Space to Jump";
    gotoxy(62, 2);
    cout << "SCORE : ";
    gotoxy(1, 25);
    for (int x = 0; x < 79; x++)
    {
    	cout << "�";
    }
}

int t, speed = 40;
int k=1, j=0;

void ds(int jump = 0) 
{
    static int a = 1;
    
    if (jump == 0)
    {
        t = 0;
    }
    else if (jump == 3)
    {
    	++j;
    	if(j==2)
    	{
        t--;
        j=0;
    	}
    }
	else if(jump == 2)
    {
	}
    else
    {
    	++j;
    	if(j==2)
    	{
        t++;
        j=0;
    	}
    }
    gotoxy(2, 15 - t);
    cout << "                 ";
    gotoxy(2, 16 - t);
    cout << "         ��������";
    gotoxy(2, 17 - t);
    cout << "         ��������";
    gotoxy(2, 18 - t);
    cout << "         ��������";
    gotoxy(2, 19 - t);
    cout << " �      �������� ";
    gotoxy(2, 20 - t);
    cout << " ���  ���������� ";
    gotoxy(2, 21 - t);
    cout << " ������������  � ";
    gotoxy(2, 22 - t);
    cout << "   ���������     ";
    gotoxy(2, 23 - t);
    if (jump == 1 || jump == 2 || jump == 3) 
	{
        cout << "    ��� ��       ";
        gotoxy(2, 24 - t);
        cout << "    ��   ��      ";
    } 
	else if (a == 1) 
	{
        cout << "    ����  ���    ";
        gotoxy(2, 24 - t);
        cout << "      ��         ";
        
        if(k==3)
        {
        a = 2;	
		}
        ++k;
    } 
	else if (a == 2) 
	{
        cout << "     ��� ��      ";
        gotoxy(2, 24 - t);
        cout << "          ��     ";
        
        if(k==1)
        {
        a = 1;	
		}
        --k;
    }
    gotoxy(2, 25 - t);
    if (jump != 0) 
	{
        cout << "                ";
    } 
    
    gotoxy(2, 25);
    cout << "�����������������";
    
    delay(speed);
}

void obj() 
{
    static int x = 0, scr = 0;
    if ((x == 56 && t < 4) || (x==70 && t<8)) 
	{
        scr = 0;
        speed = 40;
        gotoxy(36, 8);
        cout << "Game Over";
        _getch();
        gotoxy(36, 8);
        cout << "         ";
    }
    gotoxy(74 - x, 18);
    cout << "  �  ";
    gotoxy(74 - x, 19);
    cout << "  �  ";
    gotoxy(74 - x, 20);
    cout << "� �  ";
    gotoxy(74 - x, 21);
    cout << "� � � ";
    gotoxy(74 - x, 22);
    cout << "����� ";
    gotoxy(74 - x, 23);
    cout << "  �    ";
    gotoxy(74 - x, 24);
    cout << "  �  ";
    x++;
    
    if (x == 73) 
	{
        x = 0;
        scr++;
        gotoxy(70, 2);
        cout << "     ";
        gotoxy(70, 2);
        cout << scr;
        if (speed > 20)
        {
            speed--;
        }
    }
}

int main() 
{
    system("mode con: lines=29 cols=82");
    char ch;
    int i;
    
    title();
    
    getup();
    
    while (true) 
	{
        while (!_kbhit()) 
		{
            ds();
            obj();
        }
        ch = _getch();
        if (ch == ' ') 
		{
            for (i = 0; i < 20; i++) 
			{
                ds(1);
                obj();
            }
            
    		for (i = 0; i < 5; i++) 
			{
                ds(2);
                obj();
            }
            
            for (i = 0; i < 20; i++) 
			{
                ds(3);
                obj();
            }
        } 
		else if (ch == 'x') 
		{
            return 0;
        }
    }
}
