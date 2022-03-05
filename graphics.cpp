#include "graphics.h"

Screen::Screen(int width, int height)
{
	// set screen dimensions
	_width = width;
	_height = height;

	// set handle
	_hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	// prime the vector
	std::vector <int> primeVector1;
	std::vector <std::vector <int>> primeVector2;
	for (int i = 0; i < width; i++)
	{
		primeVector1.push_back(0);
	}
	for (int i = 0; i < height; i++)
	{
		primeVector2.push_back(primeVector1);
	}
	for (int i = 0; i < 3; i++)
	{
		_grid.push_back(primeVector2);
	}
}

void Screen::clear()
{
	// clear grid
	for (int y = 0; y < _height; y++)
	{
		for (int x = 0; x < _width; x++)
		{
			_grid[0][y][x] = _backgroundColor;
			_grid[1][y][x] = 0;
			_grid[2][y][x] = 0;
		}
	}
}

// error
int Screen::blit(std::vector <std::vector <int>> map, int grid, int x, int y, bool invert)
{
	int a;
	int b;
	int collide = -1;
	int originalValue;
	int constant;
	for (int i = 0; i < 3; i++)
	{
		a = 0;
		b = 0;

		originalValue = 0;

		constant = 1;

		if (invert == true)
		{
			b = map[0].size() - 1;
			constant = -1;
			originalValue = b;
		};

		for (int j = y; j < y + map.size(); j++)
		{
			for (int k = x; k < x + map[0].size(); k++)
			{
				if (k < _width && j < _height && k >= 0 && j >= 0)
				{
					if (_grid[i][j][k] == 0 && map[a][b] != 0)
					{
						if (grid == i)
						{
							_grid[i][j][k] = map[a][b];
						}
					}
					else
					{
						if (map[a][b] != 0)
						{
							collide = i;
						}
					}
				}
				b += constant;
			}
			a++;
			b = originalValue;
		}
	}

	return collide;
}


int Screen::display()
{
	_destCoord.X = 0;
	_destCoord.Y = 0;
	SetConsoleCursorPosition(_hStdout, _destCoord);

	std::vector <std::vector <int>> combinedGrid;
	int gridTemp;
	int color;
	std::string textLine;
	std::vector <int> primeVector1;
	for (int i = 0; i < _width; i++)
	{
		primeVector1.push_back(0);
	}
	for (int i = 0; i < _height; i++)
	{
		combinedGrid.push_back(primeVector1);
	}

	// combine 3 grids to 1
	for (int y = 0; y < _height; y++)
	{
		for (int x = 0; x < _width; x++)
		{
			gridTemp = 0;
			for (int i = 0; i < 3; i++)
			{
				if (_grid[i][y][x] != 0)
				{
					gridTemp = _grid[i][y][x];
				}
			}
			combinedGrid[y][x] = gridTemp;
		}
	}

	for (int y = 0; y < _height; y++)
	{
		color = combinedGrid[y][0];
		for (int x = 0; x < _width; x++)
		{
			if (color != combinedGrid[y][x])
			{
				SetConsoleTextAttribute(_hStdout, _COLORS[color]);
				std::cout << textLine;
				textLine = "";
				color = combinedGrid[y][x];
			};

			for (int a = 0; a < 2; a++)
			{
				if (combinedGrid[y][x] != 0)
				{
					textLine = textLine + char(219);
				}
				else
				{
					textLine = textLine + " ";
				}
			};
		};
		SetConsoleTextAttribute(_hStdout, _COLORS[color]);
		std::cout << textLine << "\n";
		textLine = "";
	};

	return 0;
}

void Screen::backgroundColorSetter(int backgroundcolor)
{
	_backgroundColor = backgroundcolor;
}