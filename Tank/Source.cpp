#pragma once
#include <iostream>
#include <windows.h>
#include <fstream>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include "controller.h"
void gotoxy(int column, int line);
HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;
int leftKey, upKey, rightKey, downKey;
int direc=2;
void runGame();
void showMenu();
void showScoreFromFile(string addr);
void showSetting();
void ShowConsoleCursor(bool showFlag);
void showSavedGame();
void deleteLineFile(int deleteline);
void saveSetting();
void setKeyFromSetting();
int mapNum, minY = 0, maxY = 3;
int in_menu = 0;
int x = 0, y = 0;
int settingArr[6];
bool pauseGame = false; // baraye pause kardane game
int main()
{
	ShowConsoleCursor(false);
	runGame();
	return 0;
}
void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}
void showSavedGame() // namayesh bazi haye save shode
{
	string line;
	gotoxy(3, 5);
	int counter = 0;
	ifstream saveList("saveList.txt");
	if (saveList.is_open()) // peyda kardane file save shode
	{
		while (getline(saveList, line))
		{
			gotoxy(3, 7 + counter);
			counter++;
			showScoreFromFile(line);
		}
		gotoxy(3, 7 + counter);
		counter++;
		cout << "BACK";
		counter++;
		saveList.close();
	}
	minY = 7;
	maxY += counter + 2;
	in_menu = 2; // curser daron menu savedGame ast
}
void setKeyFromSetting()
{
	string line;
	int counter = 0;
	ifstream setting("setting.txt");
	if (setting.is_open()) // peyda kardane file save shode
	{
		while (getline(setting, line))
		{
			counter++;
			switch (counter)
			{
			case 2:
				leftKey = stoi(line);
				break;
			case 3:
				upKey = stoi(line);
				break;
			case 4:
				rightKey = stoi(line);
				break;
			case 5:
				downKey = stoi(line);
				break;
			}
		}
		setting.close();
	}

}
void showScoreFromFile(string addr) // namayesh emtiaz ha az roye file
{
	string line;
	int counter = 0;
	ifstream score(addr);
	if (score.is_open()) // peyda kardane file save shode
	{
		while (getline(score, line))
		{
			int value = stoi(line);
			counter++;
			if (counter == 13)
			{
				SetConsoleTextAttribute(hstdout, 9);
				cout << "Tank 1 : score= " << value;
			}
			else if (counter == 26)
			{
				SetConsoleTextAttribute(hstdout, 13);
				cout << " | Tank 2 : score= " << value;
			}
			else if (counter == 39)
			{
				SetConsoleTextAttribute(hstdout, 10);
				cout << " | Tank 3 : score= " << value;
			}
			else if (counter == 52)
			{
				SetConsoleTextAttribute(hstdout, 15);
				cout << " | Your Tank : score= " << value;
			}
			if (counter >= 52) break;
		}
		score.close();
	}
}
void deleteLineFile(int deleteline) // pak kardane yek khat az file
{
	string line;
	ifstream sup;
	sup.open("saveList.txt");
	ofstream temp;
	temp.open("temp.txt");
	int counterLine = 0;
	while (getline(sup, line))
	{
		if (counterLine != deleteline)
		{
			temp << line << endl;
		}
		else
		{
			remove(line.c_str());
		}
		counterLine++;
	}
	temp.close();
	sup.close();
	remove("saveList.txt");
	rename("temp.txt", "saveList.txt");
}
void showMenu() // namayeshe menu 
{
	system("cls");
	maxY = 3;
	minY = 0;
	in_menu = 1;
	cout << ">";
	gotoxy(2, 0);
	cout << "NEW GAME";
	gotoxy(2, 1);
	cout << "SAVED GAME";
	gotoxy(2, 2);
	cout << "SETTING";
	gotoxy(2, 3);
	cout << "EXIT";
	x = 0; y = 0;
	gotoxy(x, y);
	bool ok = true;
	while (ok)
	{
		int ch = _getch();
		if (ch == 13) // enter
		{
			if (y < 4) // curser roye 4gozine aval bashad
			{
				switch (y)
				{
				case 0:
					mapNum = 0;
					ok = false;
					pauseGame = false;
					runGame();
					break;
				case 1:
					gotoxy(0, y);
					cout << " ";
					showSavedGame();
					y = minY;
					gotoxy(0, minY);
					cout << '>';
					break;
				case 2:
					showSetting();
					gotoxy(0, y);
					cout << " ";
					y = minY;
					gotoxy(0, y);
					cout << '>';
					break;
				case 3:
					exit(0);
					break;
				}//end switch(y)
			}// end if ( y <4 )
			else if (in_menu == 2 && y > 6 && y < maxY) // curser daron menu saveGame bashad
			{
				mapNum = y - minY;
				ok = false;
				pauseGame = true;
				runGame();
				break;
			}
			else if (in_menu == 3 && y > 6 && y < maxY) // curser daroe menu setting bashad
			{
				if (minY < y && y < maxY - 1) // curser roye taghire kilid haye bala pain chap o rast bashad
				{
					gotoxy(20, y);
					cout << "Press Key";
					int ch = _getch();
					if (ch == 224) { // if the first value is esc
						ch=_getch(); // skip 
					}
					settingArr[y - minY] = ch;
					gotoxy(20, y);
					cout << "Key Seted";
				}
				else if (minY == y) // curser roye escsspe bashad va enter bezanad
				{
					gotoxy(10, y);
					if (settingArr[0] == 1)
					{
						cout << "disable  ";
						settingArr[0] = 0;
					}
					else
					{
						cout << "enable  ";
						settingArr[0] = 1;
					}
				}
				else if (y == maxY - 1) // click color dar setting
				{
					gotoxy(9, y);
					settingArr[5] = rand() % 6;
					switch (settingArr[5])
					{
					case 0:
						cout << "RGB(0, 255, 255)  ";
						break;
					case 1:
						cout << "RGB(255, 0, 255)  ";
						break;
					case 2:
						cout << "RGB(0, 255, 50)  ";
						break;
					case 3:
						cout << "RGB(255, 0, 0)   ";
						break;
					case 4:
						cout << "RGB(255, 100, 0)  ";
						break;
					case 5:
						cout << "RGB(255, 0, 100)   ";
						break;
					}
				}
			}
			else if (y == maxY && in_menu == 2) // back zadan dar menu saved game
			{
				showMenu();
			}
			else if (y = maxY && in_menu == 3) // back&save dar setting
			{
				saveSetting();
				showMenu();
			}
		}
		else if (ch == 83 && in_menu == 2 && y < maxY)// key delete // faghat darone savegame
		{
			deleteLineFile(y - minY);
			showMenu();
			showSavedGame();
		}
		else if (ch == 80) // pain
		{
			if (y < maxY)
			{
				gotoxy(0, y);
				cout << " ";
				y++;
				gotoxy(0, y);
				cout << '>';
			}
		}
		else if (ch == 72) // bala
		{
			if (y > minY)
			{
				gotoxy(0, y);
				cout << " ";
				y--;
				gotoxy(0, y);
				cout << '>';
			}
		}//end key down
	}
}
void runGame()
{
	system("cls");
	if (in_menu == 0) showMenu();
	else {
		maxY = 3;
		minY = 0;
		in_menu = 0;
		setKeyFromSetting();
	}
	controller * controll = new controller(mapNum);
	bool ok = true;
	while (ok)
	{
		if (_kbhit())
		{
			int ch = _getch();
			if (ch == 's')
			{
				controll->saveGame();
			}
			else if (ch == 'q' || ch == 'Q')
			{
				pauseGame = true;
				system("cls");
				showMenu();
				ok = false;
			}
			else if ((ch == 't' || ch == 'T'))
			{
				if (!pauseGame) pauseGame = true;
				else pauseGame = false;
			}
			else if (ch == 32 && !pauseGame) //space key
			{
				controll->game('f', 0); // f = fire
			}
			else if (ch == (char)rightKey && !pauseGame)
			{
				direc = 3;
				//controll->game('m', 3); // move to right
			}
			else if (ch == (char)downKey && !pauseGame)
			{
				direc = 4;
				//controll->game('m', 4); // move down
			}
			else if (ch == (char)leftKey && !pauseGame)
			{
				direc = 1;
				//controll->game('m', 1); // move left
			}
			else if (ch == (char)upKey && !pauseGame)
			{
				direc = 2;
				//controll->game('m', 2); // move to up
			}
		}
		if(!pauseGame) controll->game('m', direc);
		//else if (!pauseGame) controll->game('n', 0); // n =none // bi harkat
		Sleep(15);
	}
}
void showSetting() // namayesh setting va taghire curser darone setting
{
	string line;
	int counter = 0;
	ifstream setting("setting.txt");
	if (setting.is_open()) // peyda kardane file save shode
	{
		while (getline(setting, line))
		{
			gotoxy(3, 7 + counter);
			settingArr[counter] = stoi(line);
			counter++;
			switch (counter)
			{
			case 1:
				cout << "Escape ";
				if (stoi(line) == 1)
				{
					cout << "enable";
				}
				else
				{
					cout << "disable";
				}
				break;
			case 2:
				cout << "Set left Key";
				break;
			case 3:
				cout << "Set Up Key ";
				break;
			case 4:
				cout << "Set right Key";
				break;
			case 5:
				cout << "Set down Key ";
				break;
			case 6:
				cout << "COLOR ";
				switch (stoi(line))
				{
				case 0:
					cout << "RGB(0, 255, 255)  ";
					break;
				case 1:
					cout << "RGB(255, 0, 255)  ";
					break;
				case 2:
					cout << "RGB(0, 255, 50)  ";
					break;
				case 3:
					cout << "RGB(255, 0, 0)   ";
					break;
				case 4:
					cout << "RGB(255, 100, 0)  ";
					break;
				case 5:
					cout << "RGB(255, 0, 100)   ";
					break;
				}
				break;
			}
		}
		counter++;
		gotoxy(3, 6 + counter);
		cout << "BACK&SAVE";
		counter++;
		setting.close();
	}
	minY = 7;
	maxY += counter + 2;
	in_menu = 3; // curser daron menu savedGame ast
}
void saveSetting() // zakhre kardane setting bad az back zadan
{
	ofstream setting;
	setting.open("setting.txt");
	for (int i = 0; i < 6; i++)
	{
		setting << settingArr[i] << endl;
	}
	setting.close();
}