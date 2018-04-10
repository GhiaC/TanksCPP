#include <windows.h>
#include <iostream>
#include <math.h>
#include "view.h"
void view::Tank()
{
	if (health == 0)
	{
		distroyTank();
		return;
	}
	if (dir == 1) TankLEFT();
	if (dir == 2) TankUP();
	if (dir == 3) TankRIGHT();
	if (dir == 4) TankDOWN();
}
view::view(int color)
{
	changeColor(color);
}
void view::changeColor(int color)
{
	Color = color;
	switch (color)
	{
	case 0: // ??? 
		COLOR = RGB(0, 255, 255);
		break;
	case 1: // user
		COLOR = RGB(255, 0, 255);
		break;
	case 2: //cls
		COLOR = RGB(0, 255, 50);
		break;
	case 3: // user
		COLOR = RGB(255, 0, 0);
		break;
	case 4: // user
		COLOR = RGB(255, 100, 0);
		break;
	case 5: // user
		COLOR = RGB(255, 0, 100);
		break;
	}
}
void view::TankLEFT()
{
	int yekSevom = (size / 3);
	TankClean();
	for (int i = 0; i < size; i++) // i =height // h= weight
	{
		for (int j = 0; j < size; j++)
		{
			if (j >= yekSevom && i < yekSevom) SetPixel(mydc, x + j, y + i, COLOR);
			else if (j < yekSevom && i < yekSevom) SetPixel(mydc, x + j, y + i, COLORCLS);

			if (i >= yekSevom && i < 2 * yekSevom && j < 2 * yekSevom) SetPixel(mydc, x + j, y + i, COLOR);
			else if (i >= yekSevom && i < 2 * yekSevom && j >= 2 * yekSevom) SetPixel(mydc, x + j, y + i, COLORCLS);

			if (j >= yekSevom && i >= 2 * yekSevom) SetPixel(mydc, x + j, y + i, COLOR);
			else if (j < yekSevom && i >= 2 * yekSevom) SetPixel(mydc, x + j, y + i, COLORCLS);
		}
	}
}
void view::TankUP()
{
	int yekSevom = (size / 3);
	TankClean();
	for (int i = 0; i < size; i++) // i =height // h= weight
	{
		for (int j = 0; j < size; j++)
		{
			if (j >= yekSevom && j < 2 * yekSevom && i < yekSevom) SetPixel(mydc, x + j, y + i, COLOR);
			else if (i < yekSevom) SetPixel(mydc, x + j, y + i, COLORCLS);

			if (i >= yekSevom && i < 2 * yekSevom) SetPixel(mydc, x + j, y + i, COLOR);

			if (j >= yekSevom && j < 2 * yekSevom && i >= 2 * yekSevom) SetPixel(mydc, x + j, y + i, COLORCLS);
			else if ((j < yekSevom || j >= 2 * yekSevom) && i >= 2 * yekSevom) SetPixel(mydc, x + j, y + i, COLOR);
		}
	}
}
void view::TankRIGHT()
{
	int yekSevom = (size / 3);
	TankClean();
	for (int i = 0; i < size; i++) // i =height // h= weight
	{
		for (int j = 0; j < size; j++)
		{
			if (j < 2 * yekSevom && i < yekSevom) SetPixel(mydc, x + j, y + i, COLOR);
			else if (j >= 2 * yekSevom && i < yekSevom) SetPixel(mydc, x + j, y + i, COLORCLS);

			if (i >= yekSevom && i < 2 * yekSevom && j >= yekSevom) SetPixel(mydc, x + j, y + i, COLOR);
			else if (i >= yekSevom && i < 2 * yekSevom && j < yekSevom) SetPixel(mydc, x + j, y + i, COLORCLS);

			if (j < 2 * yekSevom && i >= 2 * yekSevom) SetPixel(mydc, x + j, y + i, COLOR);
			else if (j >= 2 * yekSevom && i >= 2 * yekSevom) SetPixel(mydc, x + j, y + i, COLORCLS);
		}
	}
}
void view::TankDOWN()
{
	int yekSevom = (size / 3);
	TankClean();
	for (int i = 0; i < size; i++) // i =height // h= weight
	{
		for (int j = 0; j < size; j++)
		{
			if ((j < yekSevom || j >= 2 * yekSevom) && i < yekSevom) SetPixel(mydc, x + j, y + i, COLOR);
			else if (j >= yekSevom && j < 2 * yekSevom && i < yekSevom) SetPixel(mydc, x + j, y + i, COLORCLS);

			if (i >= yekSevom && i < 2 * yekSevom) SetPixel(mydc, x + j, y + i, COLOR);

			if (j >= yekSevom && j < 2 * yekSevom && i >= 2 * yekSevom) SetPixel(mydc, x + j, y + i, COLOR);
			else if (i >= 2 * yekSevom) SetPixel(mydc, x + j, y + i, COLORCLS);
		}
	}
}
void view::TankClean()
{
	if (dir == 1)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j <= speed; j++)
			{
				SetPixel(mydc, x + size + j, y + i, COLORCLS);
			}
		}
	}
	if (dir == 2)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j <= speed; j++)
			{
				SetPixel(mydc, x + i, y + size + j, COLORCLS);
			}
		}
	}
	if (dir == 3)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j <= speed; j++)
			{
				SetPixel(mydc, x - j, y + i, COLORCLS);
			}
		}
	}
	if (dir == 4)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j <= speed; j++)
			{
				SetPixel(mydc, x + i, y - j, COLORCLS);
			}
		}
	}
}
void view::fire(int counter)
{
	if (counter == 1 || counter == 0)
	{
		Xfire = x, Yfire = y;
		switch (shotDir)
		{
		case 1:
			Xfire -= shot;
			Yfire += (size / 2) - (shot / 2);
			break;
		case 2:
			Yfire -= shot;
			Xfire += (size / 2) - (shot / 2);
			break;
		case 3:
			Xfire += size;
			Yfire += (size / 2) - (shot / 2);
			break;
		case 4:
			Yfire += size;
			Xfire += (size / 2) - (shot / 2);
			break;
		}
	}
	if (counter == 0) return; // baraye controller::IntelligenceMove  // fahmidan mahale shelik tir
	e = false; // ejaze tir zadan nadarad
	if (shotDir == 1) Xfire -= shot;
	if (shotDir == 2) Yfire -= shot;
	if (shotDir == 3) Xfire += shot;
	if (shotDir == 4) Yfire += shot;

	for (int i = 0; i < shot; i++)
	{
		for (int j = 0; j < shot; j++)
		{
			if (counter != bord) // dar akharin harkat tir chap nashe
			{
				if (sqrt(pow((j - shot / 2), 2) + pow(i - shot / 2, 2)) <= 8) // formole hendesi dayere
				{
					SetPixel(mydc, Xfire + j, Yfire + i, COLOR);
				}
			}
			else if (counter == bord) //reset
			{
				e = true; // ejaze tir zadan darad
			}
			if (shotDir == 1) SetPixel(mydc, Xfire + shot + j, Yfire + i, COLORCLS);
			if (shotDir == 2) SetPixel(mydc, Xfire + j, Yfire + shot + i, COLORCLS);
			if (shotDir == 3) SetPixel(mydc, Xfire - shot + j, Yfire + i, COLORCLS);
			if (shotDir == 4) SetPixel(mydc, Xfire + j, Yfire - shot + i, COLORCLS);
		}
	}
}
void view::distroyTank() //pak kardane tank az roye map
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			SetPixel(mydc, x + j, y + i, COLORCLS);
		}
	}
	cleanFire(); // pak kardane tire tanke az bein rafte
	if (health > 0) blood = 100; // reset kardane salamti
}
void view::cleanFire()
{
	e = true; // ejaze tir zadan darad
	counterFire = 0;
	for (int i = 0; i < shot; i++)
	{
		for (int j = 0; j < shot; j++)
		{
			SetPixel(mydc, Xfire + j, Yfire + i, COLORCLS);
		}
	}
}