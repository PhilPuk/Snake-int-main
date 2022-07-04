#include<iostream>
#include<string>
#include<time.h>
#include<windows.h>
#include<conio.h>



int main()
{

	//SETUP
	srand((unsigned)time(NULL));
	bool lost = false;
	// Field Size
	const int sizeX = 15;
	const int sizeY = 20;

	const int TailAmount = sizeX * sizeY - 1;
	int TailX[TailAmount];
	int TailY[TailAmount];


	// Player position
	int posX = sizeX / 2;
	int posY = sizeY / 2;

	TailX[0] = posX;
	TailY[0] = posY;
	int PlayerLength = 1;

	char playerChar = '0';
	char playerTail = 'o';
	char playerInput = 'x';

	char FruitChar = 'x';
	bool FruitSpawned = true;
	int fX = rand() % sizeX - 1;
	int fY = rand() % sizeY - 1;
	if (fX <= 0)
		fX = 1;
	if (fY <= 0)
		fY = 1;
	// SETUP END

	// MAIN LOOP
	while (lost != true)
	{
		system("cls");

		if (FruitSpawned == true)
		{
			IGNORE;
		}
		else
		{
			fX = rand() % sizeX - 1;
			fY = rand() % sizeY - 1;
			if (fX <= 0)
				fX = 1;
			if (fY <= 0)
				fY = 1;
			FruitSpawned = true;
		}


		// DEV TOOL:
		
		// Print player position and fruit spawned bool and length
		std::cout << "X: " << posX << "  Y: " << posY << "\n";
		std::cout << "FruitSpawned: " << FruitSpawned << "\n";
		std::cout << "Length: " << PlayerLength << "\n\n";
	

		// Print field, player and fruit
		for (int i = 0; i < sizeX; i++)
		{
			std::cout << "#";
			for (int n = 0; n < sizeY; n++)
			{
				if (i == 0 || i == sizeX - 1)
					std::cout << "#";
				else if (i == posX && n == posY)
					std::cout << playerChar;
				else if (i == fX && n == fY)
					std::cout << FruitChar;
				else
				{
					bool print = false;
					for (int k = 0; k < PlayerLength; k++)
					{
						if (k > 1)
						{
							if (posX == TailX[k] && posY == TailY[k])
							{
								lost = true;
							}
						}
						if (i == TailX[k] && n == TailY[k])
						{
							std::cout << playerTail;
							print = true;
						}
					}
					if (!print)
						std::cout << " ";
				}
			}
			std::cout << "#\n";
		}
		if (lost == true)
			break;
		// Check tail collision
		//

		// Check fruit collision
		if (posX != fX)
			IGNORE;
		else if (posX == fX && posY == fY)
		{
			PlayerLength++;
			FruitSpawned = false;
		}
		//

		//Check wall collision (if true) go to opposite site of map
		if (posX >= sizeX - 1)
			posX = 0;
		else if (posX <= 0)
			posX = sizeX - 2;
		else if (posY >= sizeY)
			posY = 0;
		else if (posY <= 0)
			posY = sizeY - 2;
		//

		// Save last Input , save last position



		// Player Input
		if (_kbhit())
		{
			switch (playerInput = _getch())
			{
			case 'a':
				posY--;
				break;
			case 'd':
				posY++;
				break;
			case 'w':
				posX--;
				break;
			case 's':
				posX++;
				break;
			}
		}
		else
		{
			switch (playerInput)
			{
			case 'a':
				posY--;
				break;
			case 'd':
				posY++;
				break;
			case 'w':
				posX--;
				break;
			case 's':
				posX++;
				break;
			}
		}
		//

		// Set all tail positions to the next tail position
		for (int k = PlayerLength - 1; k > 0; k--)
		{
			TailX[k] = TailX[k - 1];
			TailY[k] = TailY[k - 1];
		}
		TailX[0] = posX;
		TailY[0] = posY;
		//
		Sleep(100);
	}
	std::cout << "\n\nYou've lost!\n\n";
	// MAIN LOOP END
}


