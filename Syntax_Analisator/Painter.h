#pragma once
#include <Windows.h>

enum WhatColor
{
	_KEYWORD = 9, // BLUE
	_VALUE,		  // GREEN
	_VARIABLE,	  // CYAN
	_ERROR,		  // RED
	_FUNCTION,	  // PURPLE
	_NEWTYPE,	  // YELLOW
	_DEFAULT	  // WHITE
};

class Painter
{
	WhatColor color = _DEFAULT;
	HANDLE hConsole;

public:
	Painter();
	void ChangeTextColor(WhatColor);
};