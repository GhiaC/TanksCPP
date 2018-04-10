#pragma once
#include "controller.h"
#include <cmath>
#include<time.h>
#include <algorithm> //sort 
#include<string>
#include<iostream>
#include <fstream>
#include <stdlib.h> // abs function
using namespace std;
void gotoxy(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
		);
}
bool accesVioCheck(int x, int y) // check kardane meghdare x y //az tole arraye map bishtar nabashad
{
	if (x < 1500 && y < 800 && x >= 0 && y >= 0) return true;
	return false;
}
void reverse(char s[])
{
	int i, j;
	char c;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
void MYitoa(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0)  /* record sign */
		n = -n;          /* make n positive */
	i = 0;
	do {       /* generate digits in reverse order */
		s[i++] = n % 10 + '0';   /* get next digit */
	} while ((n /= 10) > 0);     /* delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}
controller::controller(int saveNum)
{
	controller::t1 = new view(0);
	controller::t2 = new view(1);
	controller::t3 = new view(2);
	controller::tuser = new view(3);
	t1->tankNum = 1;
	t2->tankNum = 2;
	t3->tankNum = 3;
	tuser->tankNum = 4;

	string line, fileAddr; // line baraye khondane khat be khate file saveList//fileaddr address file save shodast
	int counter = 0, counter2 = 0;
	if (saveNum > 0)
	{
		ifstream saveList("saveList.txt");
		if (saveList.is_open()) // peyda kardane file save shode
		{
			while (getline(saveList, line))
			{
				if (saveNum == counter)
				{
					fileAddr = line; // address fili ke gharare bazi az roye on load beshe
					counter = 0;
					break;
				}
				else
				{
					counter++;
				}
			}
			saveList.close();
		}// end if open saveList
		int tempValue = 0;
		ifstream loadSave(fileAddr);
		if (loadSave.is_open())
		{
			while (getline(loadSave, line))
			{
				if (line == "startMap")
				{
					break;
				}
				else tempValue = stoi(line);
				counter++;
				if (counter < 14 && counter2 < 4)
				{
					switch (counter) // az inja be bad baraye set kardane data az roye file
					{
					case 1:
						if (counter2 == 0) t1->health = tempValue;
						else if (counter2 == 1) t2->health = tempValue;
						else if (counter2 == 2) t3->health = tempValue;
						else if (counter2 == 3) tuser->health = tempValue;
						break;
					case 2:
						if (counter2 == 0) t1->blood = tempValue;
						else if (counter2 == 1) t2->blood = tempValue;
						else if (counter2 == 2) t3->blood = tempValue;
						else if (counter2 == 3) tuser->blood = tempValue;
						break;
					case 3:
						if (counter2 == 0) t1->dir = tempValue;
						else if (counter2 == 1) t2->dir = tempValue;
						else if (counter2 == 2) t3->dir = tempValue;
						else if (counter2 == 3) tuser->dir = tempValue;
						break;
					case 4:
						if (counter2 == 0) t1->x = tempValue;
						else if (counter2 == 1) t2->x = tempValue;
						else if (counter2 == 2) t3->x = tempValue;
						else if (counter2 == 3) tuser->x = tempValue;
						break;
					case 5:
						if (counter2 == 0) t1->y = tempValue;
						else if (counter2 == 1) t2->y = tempValue;
						else if (counter2 == 2) t3->y = tempValue;
						else if (counter2 == 3)	tuser->y = tempValue;
						break;
					case 6:
						if (counter2 == 0) t1->Xfire = tempValue;
						else if (counter2 == 1) t2->Xfire = tempValue;
						else if (counter2 == 2) t3->Xfire = tempValue;
						else if (counter2 == 3) tuser->Xfire = tempValue;
						break;
					case 7:
						if (counter2 == 0) t1->Yfire = tempValue;
						else if (counter2 == 1) t2->Yfire = tempValue;
						else if (counter2 == 2) t3->Yfire = tempValue;
						else if (counter2 == 3) tuser->Yfire = tempValue;
						break;
					case 8:
						if (counter2 == 0) t1->destructivePower = tempValue;
						else if (counter2 == 1) t2->destructivePower = tempValue;
						else if (counter2 == 2) t3->destructivePower = tempValue;
						else if (counter2 == 3) tuser->destructivePower = tempValue;
					case 9:
						if (counter2 == 0) t1->counterTimePower = tempValue;
						else if (counter2 == 1) t2->counterTimePower = tempValue;
						else if (counter2 == 2) t3->counterTimePower = tempValue;
						else if (counter2 == 3) tuser->counterTimePower = tempValue;
						break;
					case 10:
						if (counter2 == 0) t1->shotDir = tempValue;
						else if (counter2 == 1) t2->shotDir = tempValue;
						else if (counter2 == 2) t3->shotDir = tempValue;
						else if (counter2 == 3) tuser->shotDir = tempValue;
						break;
					case 11:
						if (counter2 == 0)  t1->changeColor(tempValue);
						else if (counter2 == 1) t2->changeColor(tempValue);
						else if (counter2 == 2)  t3->changeColor(tempValue);
						else if (counter2 == 3)  tuser->changeColor(tempValue);
						break;
					case 12:
						if (counter2 == 0) t1->counterFire = tempValue;
						else if (counter2 == 1) t2->counterFire = tempValue;
						else if (counter2 == 2) t3->counterFire = tempValue;
						else if (counter2 == 3) tuser->counterFire = tempValue;
						break;
					case 13:
						if (counter2 == 0) t1->score = tempValue;
						else if (counter2 == 1) t2->score = tempValue;
						else if (counter2 == 2) t3->score = tempValue;
						else if (counter2 == 3) tuser->score = tempValue;
						if (counter2 < 4)
						{
							counter = 0;
							counter2++;
						}
						break;
					}//end switch

				}// end if counter <12
				else if (counter2 == 4)
				{
					if (counter == 0 && counter2 == 4) Xpower1 = tempValue;
					else if (counter == 1 && counter2 == 4) Ypower1 = tempValue;
					else if (counter == 2 && counter2 == 4) modePower1 = tempValue;
					else if (counter == 3 && counter2 == 4)
					{
						counter = 0;
						counter2++;
					}
				}
				else if (counter2 == 5)
				{
					if (counter == 0 && counter2 == 5) Xpower2 = tempValue;
					else if (counter == 1 && counter2 == 5) Ypower2 = tempValue;
					else if (counter == 2 && counter2 == 5) modePower2 = tempValue;
					else if (counter == 3 && counter2 == 5)
					{
						counter = 0;
						counter2++;
					}
				}
				else if (counter2 == 6)
				{
					LimitPowerShans = (bool)tempValue;
					counter2++;
				}
				else if (counter2 == 7)
				{
					LimitPowerGhodrat = (bool)tempValue;
				}
				else if (counter2 == 8)
				{
					level = tempValue;
				}
			}
			saveList.close();
		}
	} // end if(savenum>0)
	else if (saveNum == 0)
	{
		string line;
		int counter = 0;
		ifstream setting("setting.txt");
		if (setting.is_open()) // set kardane dataye save shode az roye setting
		{
			while (getline(setting, line))
			{
				counter++;
				switch (counter)
				{
				case 1:
					if (stoi(line) == 0)
					{
						escape = true;
					}
					else
					{
						escape = false;
					}
					break;
				case 6:
					tuser->changeColor(stoi(line));
					break;
				}
			}
			setting.close();
		}

		fileAddr = "";

		t1->x = 100;
		t1->y = 100;

		t2->x = 1300;
		t2->y = 100;

		t3->x = 100;
		t3->y = 600;

		tuser->x = 1300;
		tuser->y = 600;

		tuser->lastX = 1300;
		tuser->lastY = 600;

		t1->dir = 4;
		t2->dir = 4;
		t3->dir = 2;
		tuser->dir = 2;

		t1->tankNum = 1;
		t2->tankNum = 2;
		t3->tankNum = 3;
		tuser->tankNum = 4;

		tuser->health = 5;

	}
	wall(fileAddr); // chidane divar az roye file

	t1->Tank();
	t2->Tank();
	t3->Tank();
	tuser->Tank();
}
void controller::getPower(view *tank, int num) // gereftane ghodrate haye khas
{
	tank->score += 5;
	int modePower = 7;
	if (num == 7) modePower = modePower1;
	else if (num == 8) modePower = modePower2;
	if (tank->tankNum == 4) // tanke karbar bashad // faghat karbar ghodrat haye khas dashte bashad
	{
		switch (modePower)
		{
		case 1://shanse mojadad
			tuser->health++;
			LimitPowerShans = true;
			break;
		case 2:
			tuser->blood += 50;
			break;
		case 3:
			tuser->counterTimePower = 4000;// (60sec / sleep(15milisec) = 1 min)
			tuser->destructivePower *= 2;
			LimitPowerGhodrat = true;
			break;
		case 4:
			tuser->bord += 5;
			break;
		}
	}
	cleanPowerIcon(modePower);
}
void controller::iconPower() // baraye namayesh icon power
{
	int mode, randLocation, x, y;
	if (modePower1 != -1 && modePower2 != -1) // har 2 ghodrat dar safhe bashand
	{
		return;
	}
	if (tuser->counterTimePower > 0) // baraye tamam shodane zamane ghodrat
	{
		tuser->counterTimePower--;
		if (tuser->counterTimePower == 0)
		{
			tuser->destructivePower /= 2;
		}
	}
	COLORREF green = RGB(10, 160, 70);
	COLORREF white = RGB(255, 255, 255);
	COLORREF blue = RGB(50, 100, 200);
	COLORREF red = RGB(255, 0, 0);
	do
	{
		mode = rand() % 4; //0 salamati // 1 shanse mojadad // 2 ghodrat // 3 afzayesh bord
	} while ((mode == 1 && LimitPowerShans) || (mode == 2 && LimitPowerGhodrat));

	randLocation = rand() % 4;
	switch (randLocation) // entekhab jaye ghodrat az 4noghte be sorate random
	{
	case 0:
		x = 400;
		y = 300;
		break;
	case 1:
		x = 1100;
		y = 300;
		break;
	case 2:
		x = 400;
		y = 600;
		break;
	case 3:
		x = 1100;
		y = 300;
		break;
	}
	int power1or2;
	if (modePower1 == -1)
	{
		Xpower1 = x;
		Ypower1 = y;
		modePower1 = mode;
		power1or2 = 7; // baraye return kardan dar fucntion moveable
	}
	else if (modePower2 == -1)
	{
		Xpower2 = x;
		Ypower2 = y;
		modePower2 = mode;
		power1or2 = 8; // baraye return kardan dar fucntion moveable
	}
	else
	{
		return; // :|
	}
	for (int i = 0; i < tuser->shot; i++)
	{
		for (int j = 0; j < tuser->shot; j++)
		{
			if (mode == 0) //salamati // 1 shanse mojadad // 2 ghodrat // 3 afzayesh bord
			{
				map[x + i][y + j] = power1or2;
				if ((i >  tuser->shot / 2 - tuser->shot / 4 && i <  tuser->shot / 2 + tuser->shot / 5)
					|| (j >  tuser->shot / 2 - tuser->shot / 4 && j < tuser->shot / 2 + tuser->shot / 5)) SetPixel(mydc, x + i, y + j, red);
				else SetPixel(mydc, x + i, y + j, white);
			}
			if (mode == 2) // lozi  // ghodrate 2 barabar
			{
				map[x + i][y + j] = power1or2;
				if (i + j >= tuser->shot / 2 && i + j <= 3 * tuser->shot / 2 && i - j <= tuser->shot / 2 && j - i <= tuser->shot / 2) SetPixel(mydc, x + i, y + j, green);
			}
			if (mode == 1) // shanse mojadad
			{
				map[x + i][y + j] = power1or2;
				if ((i > tuser->shot / 2 - tuser->shot / 4 && i <  tuser->shot / 2 + tuser->shot / 5)
					|| (j >  tuser->shot / 2 - tuser->shot / 4 && j < tuser->shot / 2 + tuser->shot / 5)) SetPixel(mydc, x + i, y + j, green);

			}
			if (mode == 3) //afzayeshe bord
			{
				map[x + i][y + j] = power1or2;
				if (2 * j < -i + 2 * tuser->shot && 2 * j > i) SetPixel(mydc, x + i, y + j, blue);
			}

		}
	}
}
void controller::cleanPowerIcon(int num) // pak kardane ghodrat haye khas az roye safhe
{
	int x, y;
	if (num == 7)
	{
		x = Xpower1;
		y = Ypower1;
		modePower1 = -1;
	}
	else
	{
		x = Xpower2;
		y = Ypower2;
		modePower2 = -1;
	}
	for (int i = 0; i < tuser->shot; i++) // tuser->shot andaze har ghodrat 
	{
		for (int j = 0; j < tuser->shot; j++)
		{
			map[x + i][y + j] = 0;
			SetPixel(mydc, x + i, y + j, COLORCLS);
		}
	}
}
int controller::moveable(int x, int y, int tankNum, int mode) // fahmidan sheyei ke dar x y gharar darad
{
	int end;
	if (mode == 1){ end = tuser->shot; } // mode 1 baraye harkate shot // shot 2 -> tank  // andaze mohiti ke gharare check beshe 
	else { end = tuser->size; }

	for (int i = 0; i < end; i += 2)
	{
		for (int j = 0; j<end; j += 2)
		{
			for (int q = 0; q<tuser->size; q += 2)
			{
				for (int w = 0; w<tuser->size; w += 2)
				{
					if (tankNum != 1 && t1->health > 0 && x + i == t1->x + q  && y + j == t1->y + w) return 1; // tanke yek 
					if (tankNum != 2 && t2->health > 0 && x + i == t2->x + q && y + j == t2->y + w) return 2; // tanke 2
					if (tankNum != 3 && t3->health > 0 && x + i == t3->x + q && y + j == t3->y + w) return 3;
					if (tankNum != 4 && tuser->health > 0 && x + i == tuser->x + q && y + j == tuser->y + w) return 4; // tanke karbar
				}
			}
			if ((x < 1500 && y < 800 && x > 0 && y > 0))
			{
				if (map[i + x][j + y] == 1) // divare takhrib napazir
				{
					return 5;
				}
				if (map[i + x][j + y] == 2) // divare takhrib pazir
				{
					return 6;
				}
				if (map[i + x][j + y] == 7) // ghodrate emtiazi aval
				{
					return 7;
				}
				else if (map[i + x][j + y] == 8) // ghodrate emtiazi dovom
				{
					return 8;
				}
			}
		}
	}
	return 0; // just for warning
}
void controller::game(char harkat, int dir) // anjame frame be frame bazi 
{
	if (tuser->health > 0)
	{
		if (t1->health == 0 && t2->health == 0 && t3->health == 0)
		{
			if (level < 3)
			{
				level++;
				Sleep(2000);
				system("cls");
				wall("");

				modePower1 = -1;
				modePower2 = -1;

				t1->health = 1; // reset kardane bazi
				t2->health = 1;
				t3->health = 1;
				tuser->health = 5;

				t1->blood = 100;
				t2->blood = 100;
				t3->blood = 100;
				tuser->blood = 100;

				t1->x = 100;
				t1->y = 100;

				t2->x = 1300;
				t2->y = 100;

				t3->x = 100;
				t3->y = 600;

				tuser->x = 1300;
				tuser->y = 600;

				tuser->lastX = 1300;
				tuser->lastY = 600;

				t1->dir = 4;
				t2->dir = 4;
				t3->dir = 2;
				tuser->dir = 2;

				t1->Tank();
				t2->Tank();
				t3->Tank();
				tuser->Tank();
			}
			else if (level == 3)
			{
				showRank();
				gotoxy(20, 30);
				printf("YOU WIN !!!");
			}
		}
		if (t1->health > 0) IntelligenceMove(t1);
		if (t2->health > 0) IntelligenceMove(t2);
		if (t3->health > 0) IntelligenceMove(t3);

		if (harkat == 'f' && tuser->e)
		{
			tuser->shotDir = tuser->dir;
			tuser->counterFire = tuser->bord;
		}
		// harkat just move 4
		if (harkat = 'm') move(tuser, dir);
		if (tuser->counterFire > 0)
		{
			tuser->counterFire--;
			fire(tuser, (tuser->bord) - tuser->counterFire);
		}
		iconPower();
	}
	else if (tuser->health == 0)
	{
		showRank();
		printf("\nGAME OVER !!!");
		if (_getch())
		{
			exit(0);
		}
		// show new map 
	}
}
int controller::IntelligenceMove(view *tank)
{
	if (IntelligenceEscape(tank)) // agar tank dar hale farar nabod // tank dar hale farar nabashad function true return mikonad
	{
		if (tank->counterFire == 0) // tiri shelik shode bod
		{
			tank->fire(0); // faghat jaye xfire va yfire ra moshakhas mikonad
			if (tank->Yfire >= tuser->y && tank->Yfire <= tuser->y + tuser->size && tank->x >= tuser->x && tank->x - tuser->x <= tank->bord * tank->shot) // hadaf ghabele tir andazi bod
			{
				if (tank->dir != 1) move(tank, 1);
				tank->shotDir = tank->dir; // entekhab jahate tir
				tank->counterFire = tank->bord; //moshakhas kardane borde tir
			}
			else if (tank->Xfire >= tuser->x && tank->Xfire <= tuser->x + tuser->size  && tank->y >= tuser->y && tank->y - tuser->y <= tank->bord * tank->shot)
			{
				if (tank->dir != 2) move(tank, 2);
				tank->shotDir = tank->dir;
				tank->counterFire = tank->bord;
			}
			else if (tank->Yfire >= tuser->y && tank->Yfire <= tuser->y + tuser->size && tank->x <= tuser->x && tuser->x - tank->x <= tank->bord * tank->shot)
			{
				if (tank->dir != 3) move(tank, 3);
				tank->shotDir = tank->dir;
				tank->counterFire = tank->bord;
			}
			else if (tank->Xfire >= tuser->x && tank->Xfire <= tuser->x + tuser->size && tank->y <= tuser->y && tuser->y - tank->y <= tank->bord * tank->shot)
			{
				if (tank->dir != 4) move(tank, 4);
				tank->shotDir = tank->dir;
				tank->counterFire = tank->bord;
			}
		}
		if (tank->counterFire == 0)
		{
			tank->fire(0); // faghat jaye xfire va yfire ra moshakhas mikonad
			int differenceY = tuser->y - tank->y;
			int differenceX = tuser->x - tank->x;
			if (tank->Yfire >= tuser->y && tank->Yfire <= tuser->y + tuser->size && tank->x >= tuser->x && abs(differenceX) > tank->bord * tank->shot) // agar tank dar arstaye tank vali kharj az tir ras bod be samtesh bere
			{
				if (!move(tank, 1))
				{
					if (tank->dir == 4 && tank->y + tank->size < tuser->y) move(tank, 4);
					else if (tank->dir == 2 && tank->y > tuser->y)  move(tank, 2);
				}
			}
			else if (tank->Xfire >= tuser->x && tank->Xfire <= tuser->x + tuser->size  && tank->y >= tuser->y && abs(differenceY) > tank->bord * tank->shot)
			{
				if (!move(tank, 2))
				{
					if (tank->dir == 3 && tank->x < tuser->x) move(tank, 3);
					else if (tank->dir == 1 && tank->x > tuser->x + tank->size) move(tank, 1);
				}
			}
			else if (tank->Yfire >= tuser->y && tank->Yfire <= tuser->y + tuser->size && tank->x <= tuser->x && abs(differenceX) > tank->bord * tank->shot)
			{
				int temp = move(tank, 3);
				if (!temp)
				{
					if (tank->dir == 4 && tank->y + tank->size  < tuser->y) move(tank, 4);
					else if (tank->dir == 2 && tank->y> tuser->y) move(tank, 2);
				}
			}
			else if (tank->Xfire >= tuser->x && tank->Xfire <= tuser->x + tuser->size && tank->y <= tuser->y && abs(differenceY) > tank->bord * tank->shot)
			{
				if (!move(tank, 4))
				{
					if (tank->dir == 3 && tank->x + tank->size < tuser->x) move(tank, 3);
					else if (tank->dir == 1 && tank->x > tuser->size)	move(tank, 1);
				}
			}
			else if (abs(differenceX) < abs(differenceY))// && (ofour(tank) == 0))
			{
				if (tank->Xfire >= tuser->x + tuser->size)
				{
					if (!move(tank, 1))
					{
						if (tank->y + tank->size <= tuser->y) move(tank, 4);
						else if (tank->y > tuser->y) move(tank, 2);
					}
				}
				else if (tank->Xfire < tuser->x)
				{
					if (!move(tank, 3))
					{
						if (tank->y + tank->size < tuser->y) move(tank, 4);
						else if (tank->y > tuser->y) move(tank, 2);
					}
				}
				else if (tank->Yfire >= tuser->y + tuser->size)
				{
					if (!move(tank, 2))
					{
						if (tank->x + tank->size < tuser->x) move(tank, 3);
						else if (tank->x > tuser->x) move(tank, 1);
					}
				}
				else if (tank->y < tuser->y)
				{
					if (!move(tank, 4))
					{
						if (tank->x + tank->size < tuser->x) move(tank, 3);
						else if (tank->x > tuser->x) move(tank, 1);
					}
				}
			} // end y > x
			else if (abs(differenceX) > abs(differenceY))// && (ofour(tank) == 0))
			{
				if (tank->Yfire >= tuser->y + tuser->size)
				{
					if (!move(tank, 2))
					{
						if (tank->x + tank->size < tuser->x) move(tank, 3);
						else if (tank->x > tuser->x) move(tank, 1);
					}
				}
				else if (tank->Yfire < tuser->y)
				{
					if (!move(tank, 4))
					{
						if (tank->x + tank->size < tuser->x) move(tank, 3);
						else if (tank->x > tuser->x) move(tank, 1);
					}
				}
				else if (tank->x > tuser->x)
				{
					if (!move(tank, 1))
					{
						if (tank->y + tank->size < tuser->y) move(tank, 4);
						else if (tank->y > tuser->y) move(tank, 2);
					}
				}
				else if (tank->x < tuser->x)
				{
					if (!move(tank, 3))
					{
						if (tank->y + tank->size < tuser->y) move(tank, 4);
						else if (tank->y > tuser->y) move(tank, 2);
					}
				}
			} // end x > y
		}
	}// end if inteli
	if (tank->counterFire > 0) // tir zadane be tanke dige
	{
		tank->counterFire--;
		fire(tank, (tank->bord) - tank->counterFire);
	}
	return 1;
}
int controller::IntelligenceEscape(view *tank) // baraye farare tank az tir
{
	if (escape) return 1;
	if (!(tuser->e)) // tire tuser shelik shode ast
	{
		if (tuser->shotDir == 1 && tuser->Xfire - tank->x < 4 * tank->size  && tank->y + 2 * tank->size + tuser->shot > tuser->Yfire  && tank->y - 2 * tuser->size < tuser->Yfire) //tir nazdike tank ast ya na
		{
			if (tank->dir == 2) // agar be samte bala bod be harkat be samte bala edame bede
			{
				if (!move(tank, 2)) move(tank, 4); // agar natonest bala bere pain bere
			}
			else
			{
				if (!move(tank, 4))
				{
					move(tank, 2);
				}
			}
			return 0;
		}
		else if (tuser->shotDir == 2 && tuser->Yfire - tank->y < 4 * tank->size && tank->x + 2 * tank->size + tuser->shot > tuser->Xfire  && tank->x - 2 * tank->size < tuser->Xfire)
		{
			if (tank->dir == 1)
			{
				if (!move(tank, 1)) move(tank, 3);
			}
			else
			{
				if (!move(tank, 3))
				{
					move(tank, 1);
				}
			}
			return 0;
		}
		else if (tuser->shotDir == 3 && tank->x - tuser->Xfire < 4 * tank->size  && tank->y + 2 * tank->size + tuser->shot > tuser->Yfire  && tank->y - 2 * tuser->size < tuser->Yfire)
		{
			if (tank->dir == 2)
			{
				if (!move(tank, 2)) move(tank, 4);
			}
			else
			{
				if (!move(tank, 4))
				{
					move(tank, 2);
				}
			}
			return 0;
		}
		else if (tuser->shotDir == 4 && tank->y - tuser->Yfire < 4 * tank->size && tank->x + 2 * tank->size + tuser->shot > tuser->Xfire  && tank->x - 2 * tuser->size < tuser->Xfire)
		{
			if (tank->dir == 1)
			{
				if (!move(tank, 1)) move(tank, 3);
			}
			else
			{
				if (!move(tank, 3))
				{
					move(tank, 1);
				}
			}
			return 0;
		}
	}
	return 1;
}
int controller::move(view *tank, int dir) // baraye harkat dadane tanka // agar true return shavad tank be on samte rafte dar gheire in sorat tank sabet mande
{
	int moveA;
	bool is_moved = false;
	if (dir == 0) return 0;
	if (dir == 1) // 1 = left
	{
		moveA = moveable(tank->x - speed, tank->y, tank->tankNum, 2);
		if (moveA == 0)
		{
			tank->dir = dir;
			tank->x -= speed;
			is_moved = true;
		}
		else if (moveA >= 7)
		{
			getPower(tank, moveA);
		}
	}
	else if (dir == 2) // 2 = up
	{
		moveA = moveable(tank->x, tank->y - speed, tank->tankNum, 2);
		if (moveA == 0)
		{
			tank->dir = dir;
			tank->y -= speed;
			is_moved = true;
		}
		else if (moveA >= 7)
		{
			getPower(tank, moveA);
		}
	}
	else if (dir == 3) // 3 = right
	{
		moveA = moveable(tank->x + speed, tank->y, tank->tankNum, 2);
		if (moveA == 0) // mode 2 baraye fahmidane ejazeye harkate tank be an samt ast
		{
			tank->dir = dir;
			tank->x += speed;
			is_moved = true;
		}
		else if (moveA >= 7)
		{
			getPower(tank, moveA);
		}
	}
	else if (dir == 4) // 4 = down
	{
		moveA = moveable(tank->x, tank->y + speed, tank->tankNum, 2);
		if (moveA == 0)
		{
			tank->dir = dir;
			tank->y += speed;
			is_moved = true;
		}
		else if (moveA >= 7)
		{
			getPower(tank, moveA);
		}
	}
	if (is_moved)
	{
		tank->Tank(); // chap tank dar mahale jadid
	}
	return is_moved;
}
void controller::fire(view *tank, int counter) // shelike tir frame be frame
{
	int temp, temp2;
	if (counter == 1)
	{
		tank->fire(0); // pedya kardan jaye avalie tir // xfire va yfire
	}
	if (!accesVioCheck(tank->Xfire - tank->shot, tank->Yfire) || !accesVioCheck(tank->Xfire, tank->Yfire - tank->shot)
		|| !accesVioCheck(tank->Xfire + tank->shot, tank->Yfire) || !accesVioCheck(tank->Xfire, tank->Yfire + 2 * tank->shot)) return;// debug
	if (tank->shotDir == 1)
	{
		temp = moveable(tank->Xfire - tank->shot, tank->Yfire, tank->tankNum, 1); // 1 baraye emkan harkate tir
	}
	if (tank->shotDir == 2)
	{
		temp = moveable(tank->Xfire, tank->Yfire - tank->shot, tank->tankNum, 1);
	}
	if (tank->shotDir == 3)
	{
		temp = moveable(tank->Xfire + tank->shot, tank->Yfire, tank->tankNum, 1);
	}
	if (tank->shotDir == 4)
	{
		temp = moveable(tank->Xfire, tank->Yfire + 2 * tank->shot, tank->tankNum, 1);
	}
	if (temp > 0) // tir be yek shei barkhord karde
	{
		switch (temp)
		{
		case 1: // tanke aval
			if (tank->tankNum == 4)
			{
				if (t1->blood > tank->destructivePower)
				{
					t1->blood -= tank->destructivePower;
					t1->Tank();
					t1->score -= 10;
					tank->score += 20;
				}
				else
				{
					t1->blood = 0;
					t1->health--;
					t1->distroyTank();
					t1->score -= 10;
					tank->score += 20;
				}
			}
			else // tank pc be tank pc sheik karde bashe // hododan pak kardane buffer (temp)
			{
				t1->Tank();
				temp = 0;
			}
			break;
		case 2:
			if (tank->tankNum == 4)
			{
				if (t2->blood > tank->destructivePower)
				{
					t2->blood -= tank->destructivePower;
					t2->Tank();
					t1->score -= 10;
					tank->score += 20;
				}
				else
				{
					t2->health--;
					t2->blood = 0;
					t2->distroyTank(); // az bein bordane tank
					t2->score -= 10;
					tank->score += 20;
				}
			}
			else
			{
				t2->Tank();
				temp = 0;
			}
			break;
		case 3:
			if (tank->tankNum == 4)
			{
				if (t3->blood > tank->destructivePower)
				{
					t3->blood -= tank->destructivePower;
					t3->Tank();
					t3->score -= 10;
					tank->score += 20;
				}
				else
				{
					t3->health--;
					t3->distroyTank();
					t3->blood = 0;
					t3->score -= 10;
					tank->score += 20;
				}
			}
			else
			{
				t3->Tank();
				temp = 0;
			}
			break;
		case 4:
			if (tuser->blood > tank->destructivePower)
			{
				tuser->blood -= tank->destructivePower;
				tuser->Tank();
				tuser->score -= 10;
				tank->score += 20;
			}
			else
			{
				tuser->health--;
				tuser->blood = 0;
				tuser->distroyTank();
				safePosition();  // peyda kardane makane amn baraye tanke user
				tuser->Tank();
				tuser->score -= 10;
				tank->score += 20;
			}
			break;
		case 5: // tir be divare ghiere ghabele takhrib barkhord karde

			break;
		case 6: // tir be divare ghabeke takhrib barkhord karde
			for (int i = 0; i < tank->shot; i++) // khali kardan mahale tir
			{
				for (int j = 0; j < tank->shot; j++)
				{
					if (tank->shotDir == 1)
					{
						if (accesVioCheck(tank->Xfire - tank->shot + i, tank->Yfire + j))
						{
							map[tank->Xfire - tank->shot + i][tank->Yfire + j] = 0;
							SetPixel(mydc, tank->Xfire - tank->shot + i, tank->Yfire + j, COLORCLS);
						}
					}
					if (tank->shotDir == 2)
					{
						map[tank->Xfire + i][tank->Yfire - tank->shot + j] = 0;
						SetPixel(mydc, tank->Xfire + i, tank->Yfire - tank->shot + j, COLORCLS);
					}
					if (tank->shotDir == 3)
					{
						if (accesVioCheck(tank->Xfire + tank->shot + i, tank->Yfire + j))
						{
							map[tank->Xfire + tank->shot + i][tank->Yfire + j] = 0;
							SetPixel(mydc, tank->Xfire + tank->shot + i, tank->Yfire + j, COLORCLS);
						}
					}
					if (tank->shotDir == 4)
					{
						map[tank->Xfire + j][tank->Yfire + 2 * tank->shot + i] = 0;
						SetPixel(mydc, tank->Xfire + j, tank->Yfire + 2 * tank->shot + i, COLORCLS);
					}
				}
			}// end for (khali kardane jaye tir)
			break;
		case 7:
			if (tank->tankNum == 4)
			{
				getPower(tank, 7);
			}
			else
			{
				cleanPowerIcon(7);
			}
			break;
		case 8:
			if (tank->tankNum == 4)
			{
				getPower(tank, 8);
			}
			else
			{
				cleanPowerIcon(8);
			}
			break;
		}
		if (temp != 0)
		{
			showScore();//namayesh emtiaz haye jadid
			tank->cleanFire();// paksazi jaye tire barkhord karde
		}
	}
	if (tank->shotDir == 1) temp2 = is_shot(tank->Xfire - tank->shot, tank->Yfire, tank->tankNum, tank->shotDir); // tir be tire dg barkhord karde ya na
	if (tank->shotDir == 2) temp2 = is_shot(tank->Xfire, tank->Yfire - tank->shot, tank->tankNum, tank->shotDir);
	if (tank->shotDir == 3) temp2 = is_shot(tank->Xfire + tank->shot, tank->Yfire, tank->tankNum, tank->shotDir);
	if (tank->shotDir == 4) temp2 = is_shot(tank->Xfire, tank->Yfire + 2 * tank->shot, tank->tankNum, tank->shotDir);

	if (temp2 > 0) // tir be tire dg barkhord karde
	{
		switch (temp2)
		{
		case 1: // be tire tanke avale barkhord karde
			if (t1->e == false) // baraye debug // tozih darad
			{
				tank->cleanFire();
				t1->cleanFire();
			}
			else // baraye debug 
			{
				temp2 = 0;
			}
			break;
		case 2:
			if (t2->e == false)
			{
				tank->cleanFire();
				t2->cleanFire();
			}
			else
			{
				temp2 = 0;
			}
			break;
		case 3:
			if (t3->e == false)
			{
				tank->cleanFire();
				t3->cleanFire();
			}
			else
			{
				temp2 = 0;
			}
			break;
		case 4:
			if (tuser->e == false)
			{
				tank->cleanFire();
				tuser->cleanFire();
			}
			else
			{
				temp2 = 0;
			}
			break;
		}
	}
	if (counter > 0 && temp == 0 && temp2 == 0) tank->fire(counter); // agar tir be hich shei barkhord nakarde bashad be harkat edame midahad
}
int controller::ofour(view *tank) //tir raas // dar tar raas hast ya na
{
	if (tank->Yfire >= tuser->y && tank->Yfire <= tuser->y + tuser->size && tank->x > tuser->x && tank->x - tuser->x <= tank->bord * tank->shot) return 1;//left // samte chap *tank vorodi ast
	else if (tank->Xfire >= tuser->x && tank->Xfire <= tuser->x + tuser->size  && tank->y > tuser->y && tank->y - tuser->y <= tank->bord * tank->shot) return 2; // up // samte bala ast
	else if (tank->Yfire >= tuser->y && tank->Yfire <= tuser->y + tuser->size && tank->x < tuser->x && tuser->x - tank->x <= tank->bord * tank->shot) return 3;//right
	else if (tank->Xfire >= tuser->x && tank->Xfire <= tuser->x + tuser->size && tank->y <= tuser->y  && tuser->y - tank->y <= tank->bord * tank->shot) return 4;//down
	return 0;
}
int controller::is_shot(int x, int y, int tankNum, int dir)  //baraye barkhorde 2tir // mibine x y roye tir hast ya na
{
	if (dir == 1) // az samte chap tir biad
	{
		if (tankNum != 1 && !t1->e && t1->e == false && x <= t1->Xfire + t1->shot && x >= t1->x && y <= t1->Yfire + t1->shot && y >= t1->Yfire) return 1; // tire tanke 1 dar x y hast
		if (tankNum != 2 && !t2->e && t2->e == false && x <= t2->Xfire + t2->shot && x >= t2->x && y <= t2->Yfire + t2->shot && y >= t2->Yfire) return 2;
		if (tankNum != 3 && !t3->e && t3->e == false && x <= t3->Xfire + t3->shot && x >= t3->x && y <= t3->Yfire + t3->shot && y >= t3->Yfire) return 3;
		if (tankNum != 4 && !tuser->e && tuser->e == false && x <= tuser->Xfire + tuser->shot && x >= tuser->x && y <= tuser->Yfire + tuser->shot && y >= tuser->Yfire) return 4;
		return 0;// hich tiri dar x y nist
	}
	else if (dir == 2)
	{
		if (tankNum != 1 && !t1->e  && x >= t1->Xfire && x <= t1->Xfire + t1->shot && y <= t1->Yfire + t1->shot && y >= t1->Yfire) return 1;
		if (tankNum != 2 && !t2->e  && x >= t2->Xfire && x <= t2->Xfire + t2->shot && y <= t2->Yfire + t2->shot && y >= t2->Yfire) return 2;
		if (tankNum != 3 && !t3->e && x >= t3->Xfire && x <= t3->Xfire + t3->shot && y <= t3->Yfire + t3->shot && y >= t3->Yfire) return 3;
		if (tankNum != 4 && !tuser->e && x >= tuser->Xfire && x <= tuser->Xfire + tuser->shot && y <= tuser->Yfire + tuser->shot && y >= tuser->Yfire) return 4;
		return 0;
	}
	else if (dir == 3)
	{
		if (tankNum != 1 && !t1->e && x >= t1->Xfire && x <= t1->Xfire + t1->shot && y <= t1->Yfire + t1->shot && y >= t1->Yfire) return 1;
		if (tankNum != 2 && !t2->e && x >= t2->Xfire && x <= t2->Xfire + t2->shot && y <= t2->Yfire + t2->shot && y >= t2->Yfire) return 2;
		if (tankNum != 3 && !t3->e && x >= t3->Xfire && x <= t3->Xfire + t3->shot && y <= t3->Yfire + t3->shot&& y >= t3->Yfire) return 3;
		if (tankNum != 4 && !tuser->e && x >= tuser->Xfire && x <= tuser->Xfire + tuser->shot && y <= tuser->Yfire + tuser->shot && y >= tuser->Yfire) return 4;
		return 0;
	}
	else if (dir == 4)
	{
		if (tankNum != 1 && !t1->e && x >= t1->Xfire && x <= t1->Xfire + t1->shot && y >= t1->Yfire && y <= t1->Yfire + t1->shot) return 1;
		if (tankNum != 2 && !t2->e && x >= t2->Xfire && x <= t2->Xfire + t2->shot && y >= t2->Yfire && y <= t2->Yfire + t2->shot) return 2;
		if (tankNum != 3 && !t3->e && x >= t3->Xfire && x <= t3->Xfire + t3->shot && y >= t3->Yfire && y <= t3->Yfire + t3->shot) return 3;
		if (tankNum != 4 && !tuser->e && x >= tuser->Xfire && x <= tuser->Xfire + tuser->shot && y >= tuser->Yfire && y <= tuser->Yfire + tuser->shot) return 4;
		return 0;
	}
	else return 0; // just for warning
}
bool controller::safePosition() // peyda kardane jaye amn
{
	if (!(tuser->lastX == 100 && tuser->lastY == 600)) // jaye ghabli tank nabashad
	{
		tuser->x = 100;
		tuser->y = 600;
		if (ofour(t1) == 0 && ofour(t2) == 0 && ofour(t3) == 0) // mogheiat jadid dar tir ras nabod
		{
			tuser->lastX = 100;
			tuser->lastY = 600;
			return true;
		}
	}
	if (!(tuser->lastX == 1300 && tuser->lastY == 100))
	{
		tuser->x = 1300;
		tuser->y = 100;
		if (ofour(t1) == 0 && ofour(t2) == 0 && ofour(t3) == 0)
		{
			tuser->lastX = 1300;
			tuser->lastY = 100;
			return true;
		}
	}
	if (!(tuser->lastX == 100 && tuser->lastY == 100))
	{
		tuser->x = 100;
		tuser->y = 100;
		if (ofour(t1) == 0 && ofour(t2) == 0 && ofour(t3) == 0)
		{
			tuser->lastX = 100;
			tuser->lastY = 100;
			return true;
		}
	}
	if (!(tuser->lastX == 1300 && tuser->lastY == 600))
	{
		tuser->x = 1300;
		tuser->y = 600;
		if (ofour(t1) == 0 && ofour(t2) == 0 && ofour(t3) == 0)
		{
			tuser->lastX = 1300;
			tuser->lastY = 600;
			return true;
		}
	}
	return false;
}
void controller::showScore() // namayesh emtiaz bad az bord ya bakht
{
	gotoxy(0, 0);
	SetConsoleTextAttribute(hstdout, 15);
	printf("LEVEL %d ", level);
	SetConsoleTextAttribute(hstdout, 9);
	printf("|TANK1 B:%d,S=%d ", t1->blood, t1->score);
	SetConsoleTextAttribute(hstdout, 13);
	printf("|TANK2 B:%d,S=%d ", t2->blood, t2->score);
	SetConsoleTextAttribute(hstdout, 10);
	printf("|TANK3 B:%d,S=%d ", t3->blood, t3->score);
	SetConsoleTextAttribute(hstdout, 15);
	printf("|Your TANK L:%d B:%d,S=%d ", tuser->health, tuser->blood, tuser->score);
}
void controller::wall(std::string mapText) // chidane divar dar marahele mokhtalef
{
	COLORREF wallColor1 = RGB(250, 250, 250);
	COLORREF wallColor2 = RGB(150, 150, 150);
	for (int i = 0; i < 1500; i++)
	{
		if (level == 1)
		{
			map[i] = new int[800];
		}
		else
		{
			delete[] map[i]; // reset kardan
			map[i] = new int[800];
		}
		for (int j = 0; j < 30; j++) // hashiye chap o rast 
		{
			map[i][j] = 1;
			SetPixel(mydc, i, j, wallColor1);
			map[i][799 - j] = 1;
			SetPixel(mydc, i, 799 - j, wallColor1);
		}
		if (i < 30 || i > 1470) // divar bala o pain
		{
			for (int j = 0; j < 800; j++)
			{
				map[i][j] = 1;
				SetPixel(mydc, i, j, wallColor1);
			}
		}
	}
	std::string line;
	std::ifstream myMap;
	showScore();
	if (level == 1 && mapText == "")
	{
		myMap.open("mapLevel1.txt");
	}
	else if (level == 2 && mapText == "")
	{
		myMap.open("mapLevel2.txt");
	}
	else if (level == 3 && mapText == "")
	{
		myMap.open("mapLevel3.txt");
	}
	else if (mapText != "")
	{
		myMap.open(mapText);
	}
	int counter = 0, Xtemp;
	bool is_map = false;// khat be khat mire jelo vaghti be startMap mirese true mishe va map keshide mishe

	if (myMap.is_open())
	{
		while (std::getline(myMap, line))
		{
			if ((line == "startMap" && !is_map))
			{
				is_map = true;
				continue;
			}
			if (is_map)
			{
				counter++;
				if (counter == 1) Xtemp = stoi(line);
				else if (counter == 2)
				{
					if (Xtemp <1500 && Xtemp >0 && stoi(line) > 0 && stoi(line) < 800) map[Xtemp][stoi(line)] = 2;
					else
					{
						std::cout << Xtemp << std::endl << stoi(line);
						system("pause");
					}
					SetPixel(mydc, Xtemp, stoi(line), wallColor2);
					counter = 0;
				}
			}
		}
		myMap.close();
	}
}// end wall function
void controller::saveGame() // save kardane game ba filei be esme time
{
	char buffer[33];
	int t = time(NULL);
	MYitoa(t, buffer);
	ofstream saveList;
	string str(buffer);
	saveList.open("saveList.txt", std::ios_base::app);
	saveList << "saveGame\\" + str + ".txt" << endl;
	saveList.close();

	std::ofstream saveGame;
	saveGame.open("saveGame\\" + str + ".txt");
	saveGame << t1->health << endl << t1->blood << endl << t1->dir << endl << t1->x << endl << t1->y << endl
		<< t1->Xfire << endl << t1->Yfire << endl << t1->destructivePower << endl << t1->counterTimePower << endl <<
		t1->shotDir << endl << (int)t1->Color << endl << t1->counterFire << endl << t1->score << endl;
	saveGame << t2->health << endl << t2->blood << endl << t2->dir << endl << t2->x << endl << t2->y << endl
		<< t2->Xfire << endl << t2->Yfire << endl << t2->destructivePower << endl << t2->counterTimePower << endl <<
		t2->shotDir << endl << (int)t2->Color << endl << t2->counterFire << endl << t2->score << endl;
	saveGame << t3->health << endl << t3->blood << endl << t3->dir << endl << t3->x << endl << t3->y << endl
		<< t3->Xfire << endl << t3->Yfire << endl << t3->destructivePower << endl << t3->counterTimePower << endl <<
		t3->shotDir << endl << (int)t3->Color << endl << t3->counterFire << endl << t3->score << endl;
	saveGame << tuser->health << endl << tuser->blood << endl << tuser->dir << endl << tuser->x << endl << tuser->y << endl
		<< tuser->Xfire << endl << tuser->Yfire << endl << tuser->destructivePower << endl << tuser->counterTimePower << endl <<
		tuser->shotDir << endl << (int)tuser->Color << endl << tuser->counterFire << endl << tuser->score << endl;

	saveGame << Xpower1 << endl << Ypower1 << endl << modePower1 << endl;
	saveGame << Xpower2 << endl << Ypower2 << endl << modePower2 << endl;
	saveGame << LimitPowerShans << endl << LimitPowerGhodrat << endl;
	saveGame << level << endl;
	saveGame << "startMap\n";
	for (int i = 30; i < 1470; i++)
	{
		for (int j = 30; j < 770; j++)
		{
			if (map[i][j] == 2) saveGame << i << std::endl << j << std::endl;
		}
	}

	saveGame.close();

}
void controller::showRank()
{
	system("cls");
	int rank[4] = { t1->score, t2->score, t3->score, tuser->score };
	sort(begin(rank), end(rank));
	cout << "Score : \n";
	for (int i = 3; i >= 0; i--)
	{
		if (rank[i] == t1->score)
		{
			t1->score = -99999;
			SetConsoleTextAttribute(hstdout, 9);
			cout << 4 - i << " . Tank 1 : " << rank[i] << endl;
		}
		else if (rank[i] == t2->score)
		{
			t2->score = -99999;
			SetConsoleTextAttribute(hstdout, 13);
			cout << 4 - i << " . Tank 2 : " << rank[i] << endl;
		}
		else if (rank[i] == t3->score)
		{
			t3->score = -99999;
			SetConsoleTextAttribute(hstdout, 10);
			cout << 4 - i << " . Tank 3 : " << rank[i] << endl;
		}
		else if (rank[i] == tuser->score)
		{
			tuser->score = -99999;
			SetConsoleTextAttribute(hstdout, 15);
			cout << 4 - i << " . You : " << rank[i] << endl;
		}
	}
}
