#pragma once
#include <iostream>
#include <vector>
#include <windows.h>

class Screen
{
private:
	int _width;
	int _height;
	int _backgroundColor;
	std::vector <std::vector <std::vector <int>>> _grid;
	const int _COLORS[17] = {0x07, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10};
	HANDLE _hStdout;
	COORD _destCoord;

public:
	Screen(int width, int height);
	void clear();
	int blit(std::vector <std::vector <int>> map, int grid, int x, int y, bool invert);
	int display();
	void backgroundColorSetter(int backgroundColor);
};