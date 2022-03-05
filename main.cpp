#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "graphics.h"

class Dinosaur
{
public:
	// dinosaur map
	// map of dinosaur body
	std::vector <std::vector <int>> dinosaurBody = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 16, 1, 1, 1, 1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
		{1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
		{1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
		{1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
		{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};
	std::vector <std::vector <std::vector <int>>> dinosaurLegs
	{
		// map of dinosaur leg position 1
		{
			{0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}
		},
		// map of dinosaur leg position 2
		{
			{0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		},
		// map of dinosaur leg position 3
		{
			{0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}
		}
	};

	// dinosaur coordinates
	// coordinates of top left corner
	const int x = 40;
	int y = 66;

	// other
	int spriteIndex = 0;
	char status = 'n';
	short int jumpCounter = 0;
	bool up = true;

public:
	void resetDinosaur()
	{
		status = 'n';
		y = 66;
		up = true;
		jumpCounter = 0;
	};

	bool update(Screen& outputWindow, char keyboardInput)
	{
		animation();
		dinosaurAction(keyboardInput);
		blit(outputWindow);

		if (status == 'd')
		{
			return true;
		}
		else
		{
			return false;
		};
	};

	void dinosaurAction(char keyboardInput)
	{
		if (keyboardInput == ' ')
		{
			if (status == 'n' || status == 'r')
			{
				spriteIndex = 0;
				status = 'j';
			};
		};

		if (status == 'j')
		{
			dinosaurJump();
		}
		else if (status == 'r')
		{
			if (spriteIndex == 1)
			{
				spriteIndex = 2;
			}
			else
			{
				spriteIndex = 1;
			};
		};
	};

	void dinosaurJump()
	{
		if (up == true)
		{
			if (jumpCounter >= 3)
			{
				y -= 4;
			}
			else
			{
				y -= 12;
			};
			if (y == 26)
			{
				up = false;
			};
		}
		else
		{
			if (jumpCounter >= 6)
			{
				y += 13;
				if (y == 65)
				{
					y = 66;
					up = true;
					status = 'r';
					jumpCounter = 0;
				};
			};
		};
		jumpCounter++;
	};

	void animation()
	{
		if (status == 'n')  // n = nothing; meaning game has not started yet
		{
			spriteIndex = 0;  // index 0 mean idle or jump sprite
		};
	};

	void blit(Screen& outputWindow)
	{
		int a = 0;
		int b = 0;

		a = outputWindow.blit(dinosaurBody, 2, x, y, false);
		b = outputWindow.blit(dinosaurLegs[spriteIndex], 2, x, y + 18, false);

		if (a == 2 || b == 2)
		{
			std::cout << "\a";
			status = 'd';
		};
	};
};

class Cactus
{
private:
	std::vector <std::vector <std::vector <int>>> cactus = {
		{
			{0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0},
			{0, 2, 2, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 2, 2, 0},
			{2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2},
			{2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2},
			{2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2},
			{2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2},
			{2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2},
			{2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2},
			{2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2},
			{0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0},
			{0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0},
			{0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0},
			{0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0}
		}
	};

	const int y = 60;

public:
	int x = 220;

	void update(Screen& outputWindow)
	{
		cactusAction();
		blit(outputWindow);
	};

	void cactusAction()
	{
		x -= 12;
	};

	void blit(Screen& outputWindow)
	{
		outputWindow.blit(cactus[0], 2, x, y, false);
	};
};

char keyboardListener()
{
	if (_kbhit())
	{
		return _getch();
	}
	else
	{
		return -1;
	};
};

int main()
{
	// create a screen
	Screen screen(220, 88);
	screen.backgroundColorSetter(8);

	// create a dinosaur
	Dinosaur dinosaur;

	// create a cactus
	Cactus cactus;

	srand(time(NULL));
	char keyboardInput;

	while (true)
	{
		while (true)
		{
			keyboardInput = keyboardListener();
			screen.clear();
			dinosaur.update(screen, keyboardInput);

			screen.display();
			if (keyboardInput == ' ')
			{
				break;
			};
		};
		
		while (true)
		{
			screen.clear();
			if (cactus.x > -20)
			{
				cactus.update(screen);
			}
			else
			{
				if (rand() % 10 == 1)
				{
					cactus.x = 220;
				};
			};
			if (dinosaur.update(screen, keyboardListener()) == true)
			{
				screen.display();
				break;
			};
			screen.display();
		};

		system("pause>0");
		dinosaur.resetDinosaur();
		cactus.x = 220;
	};

	return 0;
};