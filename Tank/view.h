#pragma once
#include <windows.h>
#include<conio.h>
#include<stdio.h>
class view {
	HWND myconsole = GetConsoleWindow();
	HDC mydc = GetDC(myconsole);
	COLORREF COLOR = RGB(255, 255, 255);
	COLORREF COLORCLS = RGB(0, 0, 0);
	int speed = 10;
	void TankLEFT();
	void TankUP();
	void TankRIGHT();
	void TankDOWN();
public:
	view(int color);
	int lastX = 0, lastY = 0;
	int score = 0;
	void changeColor(int color);
	char Color;
	int tankNum, counterFire;
	int size = 48;
	int shot = 16;
	int bord = 30;
	int Xfire, Yfire;
	int x = 0, y = 0, dir = 1, blood = 100, health = 1;
	bool e = true;
	int destructivePower = 40;
	int counterTimePower = 0;
	int shotDir;
	void Tank();
	void TankClean();
	void cleanFire();
	void distroyTank();
	void fire(int counter);
};
