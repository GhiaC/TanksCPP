#pragma once
#include <windows.h>
#include<conio.h>
#include<stdio.h>
#include<string>
#include "view.h"
class controller{
	int speed = 10;
	HWND myconsole = GetConsoleWindow();
	HDC mydc = GetDC(myconsole);
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COLORREF COLORCLS = RGB(0, 0, 0);
	int move(view *tank, int dir);
	void fire(view *tank, int counter);
	int IntelligenceEscape(view *tank);
	int IntelligenceMove(view *tank);
	int ofour(view *tank);
	int **map = new int*[1500];
	int level = 1;
	void showScore();
	int Xpower1, Ypower1, modePower1 = -1;
	int Xpower2, Ypower2, modePower2 = -1;
	bool LimitPowerShans = false;
	bool LimitPowerGhodrat = false;
	bool escape = false;
	int moveable(int x, int y, int tankNum, int mode); // return number tank or wall(2 kind)
	int is_shot(int x, int y, int tankNum, int dir);
	void getPower(view *tank, int num);
	bool safePosition();
	void iconPower();
	void wall(std::string mapText);
	void cleanPowerIcon(int num);
	void showRank();
public:
	view *t1, *t2, *t3, *tuser;
	void saveGame();
	controller(int saveNum);
	void game(char harkat, int dir);
};