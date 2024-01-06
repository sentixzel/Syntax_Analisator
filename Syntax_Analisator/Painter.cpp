#include "Painter.h"

Painter::Painter()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Painter::ChangeTextColor(WhatColor col)
{
	color = col;
	SetConsoleTextAttribute(hConsole, color);
}