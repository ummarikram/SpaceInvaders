#include <iostream>
#include "mygraphics.h"
#include <conio.h>
#include <time.h>
#define ROWS 25
#define COL 80
using namespace std;

bool GameContinue = true;

char World[ROWS][COL] = {
  "                                                                               ",
  "|                                                                             |",
  "|    WWW           WWW              WWW               WWW               WWW   |",
  "|                                                                             |",
  "|                                                                             |",
  "|                                                                             |",
  "|                                                                             |",
  "|           WWW             WWW              WWW              WWW             |",
  "|                                                                             |",
  "|                                                                             |",
  "|                                                                             |",
  "|                                                                             |",
  "|                                                                             |",
  "|    WWW           WWW              WWW               WWW               WWW   |",
  "|                                                                             |",
  "|                                                                             |",
  "|                                                                             |",
  "|                                                                             |",
  "|                                                                             |",
  "|                                                                             |",
  "|                                                                             |",
  "|                                                                             |",
  "|                                                                             |",
  "|                                                                             |",
  "|                                    ===                                      |",
};

struct Shapes
{
	// Shapes Initializer.
	void ShapeInitialize(int i, int Lives)
	{
		SetConsoleWindowDimensions(1280, 720);

		Maximize();

		// Player.
		if (Lives != 0)
		{
			drawRectangle(570 + i, 438, 607 + i, 446, 0, 0, 0, 0, 255, 0);     // Player Shape (Green Rectangle)
		}

		// Borders.
		drawLine(205, 1, 205, 445, 255);      //Left Border.

		drawLine(985, 1, 985, 445, 255);   // Right Border.

		// Lives.
		if (Lives == 3)
		{
			drawRectangle(870, 455, 890, 465, 0, 0, 0, 0, 255, 0);   // Green Rectangles To Represent Lives.

			drawRectangle(895, 455, 915, 465, 0, 0, 0, 0, 255, 0);

			drawRectangle(920, 455, 940, 465, 0, 0, 0, 0, 255, 0);
		}
		else if (Lives == 2)
		{
			drawRectangle(870, 455, 890, 465, 0, 0, 0, 0, 255, 0);

			drawRectangle(895, 455, 915, 465, 0, 0, 0, 0, 255, 0);

			drawRectangle(920, 455, 940, 465, 0, 0, 0, 0, 0, 0);     // Cleaning First Life.

		}
		else if (Lives == 1)
		{
			drawRectangle(870, 455, 890, 465, 0, 0, 0, 0, 255, 0);

			drawRectangle(895, 455, 915, 465, 0, 0, 0, 0, 0, 0);    // Cleaning Second Life.

		}
		else if (Lives == 0)
		{
			drawRectangle(870, 455, 890, 465, 0, 0, 0, 0, 255, 0);   // Cleaning Last life.

			GameContinue = 0;
		}
	}

	// Function to Clean Shapes.
	void CleaningShapes()
	{
		// Cleaning Borders.
		drawLine(205, 1, 205, 445, 0);      //Left Border.

		drawLine(985, 1, 985, 445, 0);   // Right Border.

		// Cleaning Lives.
		drawRectangle(870, 455, 890, 465, 0, 0, 0, 0, 0, 0);

		drawRectangle(895, 455, 915, 465, 0, 0, 0, 0, 0, 0);

		drawRectangle(920, 455, 940, 465, 0, 0, 0, 0, 0, 0);
	}
};

struct Messages
{
	//Output Message At the End of Game.
	void OutputMessage(int Score, int Lives, int EnemyCount)
	{
		if (Lives > 0 && EnemyCount == 0)      // If Player Wins
		{
			cout << "\n\n\n\t\t\tWell Played!\n\n";      // Message to Player At End.

			cout << "\n\n\n\t\t\t\t\t\tYour Score is : " << Score << "\n\n\n\n";   // Display Score At End.

		}
		else           // If Player Loses or Quits.
		{
			cout << "\n\n\n\n\t\t\tBetter Luck Next Time!\n\n";    // Message to Player At End.

			cout << "\n\n\n\n\t\t\t\t\t\tYour Score is : " << Score << "\n\n\n";      // Display Score At End.

		}
	}

	//Welcome Message Before Starting Game.
	void WelcomeMessage(int& Difficulty)
	{
		//Welcome Screen.
		SetConsoleStyle(10, 18);

		showConsoleCursor(false);          // Remove Cursor.

		cout << "\t\t\t\tWELCOME TO SPACE INVADERS!" << endl;    // Welcome To the Game.

		delay(2000);    // Delay for 2000 milliseconds.

		cls();    // Clear Screen

		cout << "\t\t\t\tChoose Difficulty Level : " << endl << endl;

		cout << "\t\t\t\tPress 1: Easy -----> For Beginners! " << endl << endl;     // Press 1 for Easy Difficulty.

		cout << "\t\t\t\tPress 2: Medium -----> For Regular Players! " << endl << endl;       // Press 2 for Medium Difficulty.

		cout << "\t\t\t\tPress 3: Hard -----> You Will Not Survive! ";    // Press 3 for Hard Difficulty.

		do     // Loop for Validation.
		{
			Difficulty = _getch();      // Gets key from User.

		} while (Difficulty != '1' && Difficulty != '2' && Difficulty != '3');      // Repeat until Valid Difficulty Selected.

		delay(400);   // Delay for 400 milliseconds.
	}
};

class Enemy
{
public:
	char SymbolEnemy = 'W';
	char EnemyLaser = '*';
	char direction = 'l';
	int EnemyCount = 14;
	int EnemyReady = 0;
	int EnemyDrop = 0;

	void EnemyMovement()
	{
		EnemyDrop = 0;    // Enemy Drop Control Variable.

		for (int y = 0; y < ROWS - 1; y++)      // For loop through height of World Array.
		{
			// Check if Enemy is present at left most corner.
			if ((World[y][2] == SymbolEnemy && World[y][3] == SymbolEnemy && World[y][4] == SymbolEnemy))
			{
				direction = 'r';     // Set Direction to Right

				EnemyDrop = 1;         // Drop is true

				break;
			}

			// Check if Enemy is present at right most corner.
			if ((World[y][COL - 3] == SymbolEnemy && World[y][COL - 4] == SymbolEnemy && World[y][COL - 5] == SymbolEnemy))
			{
				direction = 'l';             // Set Direction to Left.

				EnemyDrop = 1;             // Drop is true.

				break;
			}
		}

		if (rand() % 13 == 3)            // Random Moving Time for Enemy.
		{
			if (direction == 'l')                 // if direction to move is set to left.
			{
				for (int x = 2; x <= COL - 3; x++)         // Nested loop through all possible postion of enemy array.
				{
					for (int y = 0; y < ROWS; y++)
					{
						// if drop is true and Enemy present at postion.
						if (EnemyDrop && ((World[y - 1][x + 1] == SymbolEnemy && World[y - 1][x + 2] == SymbolEnemy && World[y - 1][x + 3] == SymbolEnemy)))
						{
							World[y][x] = World[y - 1][x + 1];       // Store Enemy One Block downwards diagonally Leftwards (/).

							World[y][x + 1] = World[y - 1][x + 2];

							World[y][x + 2] = World[y - 1][x + 3];

							World[y - 1][x + 1] = ' ';            // Previous Positions of Enemy Erased.

							World[y - 1][x + 2] = ' ';

							World[y - 1][x + 3] = ' ';

						}

						// if drop not true and Enemy present at position
						else if (!EnemyDrop && ((World[y][x + 1] == SymbolEnemy && World[y][x + 2] == SymbolEnemy && World[y][x + 3] == SymbolEnemy)))
						{
							World[y][x + 2] = World[y][x + 3];            // Store Enemy One Block Leftwards.

							World[y][x + 1] = World[y][x + 2];

							World[y][x] = World[y][x + 1];

							World[y][x + 3] = ' ';                // Previous Position of Enemy Erased.

						}
					}
				}
			}

			else if (direction == 'r')         // if direction to move is set to Right.
			{
				for (int x = COL - 3; x >= 2; x--)        // Nested loop through all possible postions of enemy in array.
				{
					for (int y = 0; y < ROWS; y++)
					{
						// if drop is true and Enemy present at postion.
						if (EnemyDrop && ((World[y - 1][x - 1] == SymbolEnemy && World[y - 1][x - 2] == SymbolEnemy && World[y - 1][x - 3] == SymbolEnemy)))
						{
							World[y][x - 2] = World[y - 1][x - 3];          // Store Enemy One Block downwards diagonally Rightwards (\).

							World[y][x - 1] = World[y - 1][x - 2];

							World[y][x] = World[y - 1][x - 1];

							World[y - 1][x - 1] = ' ';                 // Previous Positions of Enemy Erased.

							World[y - 1][x - 2] = ' ';

							World[y - 1][x - 3] = ' ';

						}

						// if drop not true and Enemy present at position
						else if (!EnemyDrop && ((World[y][x - 1] == SymbolEnemy && World[y][x - 2] == SymbolEnemy && World[y][x - 3] == SymbolEnemy)))
						{
							World[y][x] = World[y][x - 1];                // Store Enemy One Block Rightwards.

							World[y][x - 2] = World[y][x - 3];

							World[y][x - 1] = World[y][x - 2];

							World[y][x - 3] = ' ';                        // Previous Position of Enemy Erased.

						}
					}
				}
			}
		}

		for (int x = 2; x < COL - 2; x++)       // For loop to check if Enemy is at last stage to Player.
		{
			// if Enemy parallel to player is true. 
			if (World[ROWS - 1][x] == SymbolEnemy)
			{
				GameContinue = 0;             // Game Ends.
			}
		}
	}

	void Shooting(int& x, int& y)
	{
		for (int NewH = y + 1; NewH < ROWS; NewH++)        // Loop to Control Enemy Laser if Another Enemy is Below.
		{
			if (World[NewH][x] == SymbolEnemy)           // Checks if Another Enemy is Below, if True Then Enemy Above Does Not Shoot Laser.
			{
				EnemyReady = 0;     // Enemy Above Ready is False.

				break;    // Loop Break.
			}

			EnemyReady = 1;      //For Enemy not Below, Enemy Above is Ready To Shoot.
		}

		if (EnemyReady)    // Enemy Above Ready is True.
		{
			World[y + 1][x + 1] = EnemyLaser;       // Enemy Shoots Downwards.
		}
	}

	void LaserCancelled(int& x, int& y)
	{
		World[y][x] = ' ';                // Enemy Laser Disappear.

		World[y + 1][x] = ' ';    // Player Laser Disappear.

		Beep(200, 3);     // Kill Sound.
	}

	void MoveLaser(int& x, int& y)
	{
		World[y + 1][x] = EnemyLaser;     // Enemy Laser Continues.

		World[y][x] = ' ';    // Previous Position of Enemy Laser Disappers.
	}

	void GotHit(int& x, int& y)
	{
		World[y][x] = ' ';          // Player Laser Disappers.

		World[y - 1][x] = ' ';         // Enemy is Killed.

		World[y - 1][x + 1] = ' ';

		World[y - 1][x + 2] = ' ';

		World[y - 1][x - 1] = ' ';

		World[y - 1][x - 2] = ' ';

		EnemyCount--;                      // Enemy Count Decreased.
	}
};

class Player
{
public:
	char SymbolPlayer = '=';
	char PlayerLaser = '^';
	char Key = NULL;
	int Score = 0;
	int LReady = 1;
	int Lives = 3;
	int PlayerShapeControl = 0;

	void PlayerMovement()
	{
		LReady++;        // Player Laser Shooting  Control Variable.

		Key = NULL;

		if (_kbhit() != 0)
		{
			Key = _getch();

		}

		if (Key == 'a' || Key == 'A')        // In Case of Player Moving Leftwards. 
		{
			for (int x = 2; x < COL - 2; x++)         // Loop through Positive X-Axis.
			{
				// Checks Current Position of Player.
				if (World[ROWS - 1][x] == SymbolPlayer && World[ROWS - 1][x + 1] == SymbolPlayer && World[ROWS - 1][x + 2] == SymbolPlayer)
				{
					World[ROWS - 1][x - 1] = SymbolPlayer;               // Store Player in Previous Positions.

					World[ROWS - 1][x] = SymbolPlayer;

					World[ROWS - 1][x + 1] = SymbolPlayer;

					World[ROWS - 1][x + 2] = ' ';        // Makes Current Position Blank.

					PlayerShapeControl = PlayerShapeControl - 10;        // Variable i controls Player Shape Movement.

					break;
				}
			}
		}

		if (Key == 'd' || Key == 'D')           //In Case of Player Moving Rightwards.
		{
			for (int x = COL - 5; x > 0; x--)       // Loop through Negative X-Axis.
			{
				// Checks Current Position of Player.
				if (World[ROWS - 1][x] == SymbolPlayer && World[ROWS - 1][x - 1] == SymbolPlayer && World[ROWS - 1][x - 2] == SymbolPlayer)
				{
					World[ROWS - 1][x - 1] = SymbolPlayer;      // Store Player in Forward Positions.

					World[ROWS - 1][x] = SymbolPlayer;

					World[ROWS - 1][x + 1] = SymbolPlayer;

					World[ROWS - 1][x - 2] = ' ';                // Makes Current Position Blank.

					PlayerShapeControl = PlayerShapeControl + 10;        // Variable i controls Player Shape Movement.

					break;
				}
			}
		}

		if (Key == ' ' && LReady > 3)        // In Case of Player Shooting Laser.
		{
			for (int x = 0; x < COL; x++)  // Loop for X Postion of Player As Y Postion is Fixed.
			{
				if (World[ROWS - 1][x] == SymbolPlayer && World[ROWS - 1][x + 1] == SymbolPlayer)     // Check Current Positon of Player.
				{
					World[ROWS - 2][x + 1] = PlayerLaser;     // Place Player Laser One Postion Above Current Position of Player.

					LReady = 0;              // Laser Ready set to 0 to Avoid Multiple Shooting by Player.

					Beep(500, 2);   // Shoot Sound. Part of the Time.h Library.

					break;
				}
			}
		}

		if (Key == 'q' || Key == 'Q')    // Manual Exit.
		{
			GameContinue = 0;      // Game Ends.
		}
	}

	void GotHit(int& x, int& y)
	{
		World[y - 1][x] = ' ';   // Enemy Laser Disappear.

		Lives--;                 // Lives Count Decrease.

		Beep(800, 10);     // Kill Sound.

		if (Lives == 0)          // Checks if No lives Left, if True then Game Finished.
		{
			GameContinue = 0;        // Game Finished.
		}
	}

	void LaserCancelled(int& x, int& y)
	{
		World[y][x] = ' ';            // Player Laser Disappear.

		World[y - 1][x] = ' ';        // Enemy Laser Disappear.

		Beep(200, 3);     // Kill Sound.
	}

	void MoveLaser(int& x, int& y)
	{
		World[y][x] = ' ';    // Previous Position of Player Laser Disappers.

		World[y - 1][x] = PlayerLaser;   // Player Laser Continues Upwards.
	}
};

void DisplayWorld(int Score)
{
	for (int y = 1; y < ROWS; y++)          // Loop to Display World|Array.
	{
		gotoxy(20, y);
		cout << World[y] << endl;
	}

	cout << "\t\t\t\tSCORE : " << Score << "\t\t\t\t\tLIVES: ";  // Score & Lives Display.
}

//Laser System For Enemies & Player.
void LaserControl(Player& P, Enemy& E, int Difficulty)
{
	for (int x = 0; x < COL; x++)                                   // Nested Loops to Display Enemy Laser.
	{
		for (int y = ROWS - 1; y > 0; y--)
		{
			// Checks if Enemy Laser is Above Player Laser, if True then Both Laser Disappear.
			if (World[y][x] == E.EnemyLaser && (World[y + 1][x] == P.PlayerLaser))
			{
				E.LaserCancelled(x, y);
			}

			// Checks if Enemy is Below Enemy Laser. If Enemy is Below, Enemy Laser Disappers, Else it Continues.
			else if (World[y][x] == E.EnemyLaser && (World[y + 1][x] != E.SymbolEnemy))
			{
				E.MoveLaser(x, y);
			}

			// If Enemy Below Enemy Laser.
			else if (World[y][x] == E.EnemyLaser && (World[y + 1][x] == E.SymbolEnemy))
			{
				World[y][x] = ' ';  // Enemy Laser Disappears.
			}

			// Checks if Player is Below Enemy Laser, if True then Enemy Laser Disappear & Player Lives Decrease. 
			else if (World[y][x] == P.SymbolPlayer && World[y - 1][x] == E.EnemyLaser)
			{
				P.GotHit(x, y);
			}
		}
	}

	for (int x = 0; x < COL; x++)                            // Nested Loops to Control Player Laser & Enemy Laser.
	{
		for (int y = 0; y < ROWS; y++)
		{
			// Checks if Enemy Laser is Above Player Laser, if True then Both Laser Disappear.
			if (World[y][x] == P.PlayerLaser && World[y - 1][x] == E.EnemyLaser)
			{
				P.LaserCancelled(x, y);
			}

			// Checks if Enemy is Above Player Laser, if Enemy Present Above then Enemy is Killed and Player Laser Disappears.
			else if (World[y][x] == P.PlayerLaser && (World[y - 1][x] == E.SymbolEnemy))
			{
				E.GotHit(x, y);

				P.Score = P.Score + 20;               // Player Score Increased.

				Beep(800, 10);     // Kill Sound.
			}

			else if (Difficulty == '1')     // Easy Difficulty.
			{
				// Random Shooting Time for Enemy.
				if (((World[y][x] == E.SymbolEnemy && World[y][x + 1] == E.SymbolEnemy && World[y][x + 2] == E.SymbolEnemy)) &&
					(rand() % 9) == 2 && (rand() % 9) == 3 && (rand() % 2) == 0 && World[y + 1][x] != P.PlayerLaser)
				{
					E.Shooting(x, y);
				}
			}

			else if (Difficulty == '2')     // Medium Difficulty.
			{
				if (((World[y][x] == E.SymbolEnemy && World[y][x + 1] == E.SymbolEnemy && World[y][x + 2] == E.SymbolEnemy)) &&
					(rand() % 9) == 2 && (rand() % 9) == 5 && World[y + 1][x] != P.PlayerLaser)           // Random Shooting Time for Enemy.
				{
					E.Shooting(x, y);
				}
			}

			else if (Difficulty == '3')     // Hard Difficulty.
			{
				if (((World[y][x] == E.SymbolEnemy && World[y][x + 1] == E.SymbolEnemy && World[y][x + 2] == E.SymbolEnemy)) &&
					(rand() % 13) == 11 && World[y + 1][x] != P.PlayerLaser)           // Random Shooting Time for Enemy.
				{
					E.Shooting(x, y);
				}
			}

			if (World[y][x] == P.PlayerLaser && World[y - 1][x] != E.EnemyLaser && y > 0)   // if Enemy is Not Above Player Laser, Player Laser Continues.
			{
				P.MoveLaser(x, y);
			}
		}
	}
}

// Main Function.
int main()
{
	int Difficulty = 0;

	Messages M; Shapes S; Enemy E; Player P;

	M.WelcomeMessage(Difficulty);

	delay(1000);    // Wait 1000 milliseconds.

	cls();   // Clear Screen.

	// Major Loop To Control Game, Terminates When Either All Enemies are Killed OR Player Lives are 0 OR Enemies Reach Player.
	while (E.EnemyCount > 0 && GameContinue)
	{
		system("cls");  // Clear Screen.

		DisplayWorld(P.Score);      // Display 2D World|Array.

		S.ShapeInitialize(P.PlayerShapeControl, P.Lives);  // Shapes Display.

		LaserControl(P, E, Difficulty);    // Laser Mechanics.

		E.EnemyMovement(); // Enemy Movement Mechanics.

		P.PlayerMovement();     // Player Movement Mechanics.

		delay(50);    // Wait 50 milliseconds.

	}

	delay(500);    // Wait 500 milliseconds.

	S.CleaningShapes();   // Clean Shapes.

	system("cls");   // Clear Screen.

	M.OutputMessage(P.Score, P.Lives, E.EnemyCount);   // Display Output Message.

	delay(3000);

	return 0;
}


