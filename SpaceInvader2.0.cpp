#include <iostream>
#include "mygraphics.h"
#include <conio.h>
#include <windows.h>
#include <time.h>
#define ROWS 25
#define COL 80
using namespace std;

// Global Variable.
bool GameContinue = true;

//2-D Array used to Initialize World that works at back end.
char World[ROWS][COL] = {
  "                                                                               ",
  "|                                                                             |",
  "|    OOO           OOO              OOO               OOO               OOO   |",
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
  "|    OOO           OOO              OOO               OOO               OOO   |",
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

// Shapes Initializer.
void ShapeInitialize(int i, int Lives)
{
	SetConsoleWindowDimensions(666, 380);

	// Player.
	if (Lives != 0)
	{
		drawRectangle(290 + i, 280, 327 + i, 288, 0, 0, 0, 0, 255, 0);     // Player Shape (Green Rectangle)
	}

	// Borders.
	drawLine(4, 1, 4, 300, 255);      //Left Border.

	drawLine(628, 1, 628, 300, 255);   // Right Border.

	// Lives.
	if (Lives == 3)
	{
		drawRectangle(525, 289, 545, 299, 0, 0, 0, 0, 255, 0);   // Green Rectangles To Represent Lives.

		drawRectangle(550, 289, 570, 299, 0, 0, 0, 0, 255, 0);

		drawRectangle(575, 289, 595, 299, 0, 0, 0, 0, 255, 0);
	}
	else if (Lives == 2)
	{
		drawRectangle(525, 289, 545, 299, 0, 0, 0, 0, 255, 0);

		drawRectangle(550, 289, 570, 299, 0, 0, 0, 0, 255, 0);

		drawRectangle(575, 289, 595, 299, 0, 0, 0, 0, 0, 0);        // Cleaning First Life.

	}
	else if (Lives == 1)
	{
		drawRectangle(525, 289, 545, 299, 0, 0, 0, 0, 255, 0);

		drawRectangle(550, 289, 570, 299, 0, 0, 0, 0, 0, 0);    // Cleaning Second Life.

	}
	else if (Lives == 0)
	{
		drawRectangle(525, 289, 545, 299, 0, 0, 0, 0, 0, 0);   // Cleaning Last life.
		GameContinue = 0;
	}
}

// Enemy Structure.
struct Enemy
{
	char Enemy1 = 'O';
	char EnemyLaser = '.';
	int EnemyCount = 10;
	int EnemyReady = 0;
	int EnemyDrop = 0;
};

// Player Structure.
struct Player
{
	char Player1 = '=';
	char PlayerLaser = '^';
	int Score = 0;
	int LReady = 1;
	int Lives = 3;
	int PlayerShapeControl = 0;
};

// Enemy Movements.
void EnemyMovement(Enemy& E, char& direction)
{
	for (int y = 0; y < ROWS - 1; y++)      // For loop through height of World Array.
	{
		// Check if Enemy is present at left most corner.
		if ((World[y][2] == E.Enemy1 && World[y][3] == E.Enemy1 && World[y][4] == E.Enemy1))
		{
			direction = 'r';     // Set Direction to Right

			E.EnemyDrop = 1;         // Drop is true

			break;
		}

		// Check if Enemy is present at right most corner.
		if ((World[y][COL - 3] == E.Enemy1 && World[y][COL - 4] == E.Enemy1 && World[y][COL - 5] == E.Enemy1))
		{
			direction = 'l';             // Set Direction to Left.

			E.EnemyDrop = 1;             // Drop is true.

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
					if (E.EnemyDrop && ((World[y - 1][x + 1] == E.Enemy1 && World[y - 1][x + 2] == E.Enemy1 && World[y - 1][x + 3] == E.Enemy1)))
					{
						World[y][x] = World[y - 1][x + 1];       // Store Enemy One Block downwards diagonally Leftwards (/).

						World[y][x + 1] = World[y - 1][x + 2];

						World[y][x + 2] = World[y - 1][x + 3];

						World[y - 1][x + 1] = ' ';            // Previous Positions of Enemy Erased.

						World[y - 1][x + 2] = ' ';

						World[y - 1][x + 3] = ' ';

					}

					// if drop not true and Enemy present at position
					else if (!E.EnemyDrop && ((World[y][x + 1] == E.Enemy1 && World[y][x + 2] == E.Enemy1 && World[y][x + 3] == E.Enemy1)))
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
					if (E.EnemyDrop && ((World[y - 1][x - 1] == E.Enemy1 && World[y - 1][x - 2] == E.Enemy1 && World[y - 1][x - 3] == E.Enemy1)))
					{
						World[y][x - 2] = World[y - 1][x - 3];          // Store Enemy One Block downwards diagonally Rightwards (\).

						World[y][x - 1] = World[y - 1][x - 2];

						World[y][x] = World[y - 1][x - 1];

						World[y - 1][x - 1] = ' ';                 // Previous Positions of Enemy Erased.

						World[y - 1][x - 2] = ' ';

						World[y - 1][x - 3] = ' ';

					}

					// if drop not true and Enemy present at position
					else if (!E.EnemyDrop && ((World[y][x - 1] == E.Enemy1 && World[y][x - 2] == E.Enemy1 && World[y][x - 3] == E.Enemy1)))
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
		if (World[ROWS - 1][x] == E.Enemy1)
		{
			GameContinue = 0;             // Game Ends.
		}
	}
}

//Output Message At the End of Game.
void OutputMessage(int Score, int Lives, int EnemyCount)
{
	if (Lives > 0 && EnemyCount == 0)      // If Player Wins
	{
		cout << "\n\n\n                            Well Played!        \n\n";      // Message to Player At End.

		cout << "\n\n\n                                       Your Score is : " << Score << "\n\n\n\n";   // Display Score At End.

	}
	else           // If Player Loses or Quits.
	{
		cout << "\n\n\n\n                Better Luck Next Time!        \n\n";    // Message to Player At End.

		cout << "\n\n\n\n                                       Your Score is : " << Score << "\n\n\n";      // Display Score At End.

	}
}

//Welcome Message Before Starting Game.
void Welcome(int& Difficulty)
{
	//Welcome Screen.
	fontsize(10, 18);   // Adjusting Font Size For Message Display.

	showConsoleCursor(false);

	cout << "                            WELCOME TO SPACE INVADERS! " << endl;    // Welcome To the Game.

	delay(2000);    // Delay for 2000 milliseconds.

	cls();    // Clear Screen

	cout << "                              Choose Difficulty Level : " << endl << endl;

	cout << "                        Press 1: Easy -----> For Beginners! " << endl << endl;     // Press 1 for Easy Difficulty.

	cout << "                        Press 2: Medium -----> For Regular Players! " << endl << endl;       // Press 2 for Medium Difficulty.

	cout << "                        Press 3: Hard -----> You Will Not Survive! ";    // Press 3 for Hard Difficulty.

	do     // Loop for Validation.
	{
		Difficulty = _getch();      // Gets key from User.

	} while (Difficulty != '1' && Difficulty != '2' && Difficulty != '3');      // Repeat until Valid Difficulty Selected.

	delay(400);   // Delay for 400 milliseconds.
}

//Displaying World After Every Change.
void DisplayWorld(int Score, int Lives)
{
	for (int y = 1; y < ROWS; y++)          // Loop to Display World|Array.
	{
		cout << World[y] << endl;
	}
	cout << "    SCORE : " << Score << "                                        LIVES: " << Lives;  // Score & Lives Display.
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
				World[y][x] = ' ';                // Enemy Laser Disappear.

				World[y + 1][x] = ' ';    // Player Laser Disappear.

				Beep(200, 3);     // Kill Sound.
			}

			// Checks if Enemy is Below Enemy Laser. If Enemy is Below, Enemy Laser Disappers, Else it Continues.
			else if (World[y][x] == E.EnemyLaser && (World[y + 1][x] != E.Enemy1))
			{
				World[y + 1][x] = E.EnemyLaser;     // Enemy Laser Continues.

				World[y][x] = ' ';    // Previous Position of Enemy Laser Disappers.

			}

			// If Enemy Below Enemy Laser.
			else if (World[y][x] == E.EnemyLaser && (World[y + 1][x] == E.Enemy1))
			{
				World[y][x] = ' ';  // Enemy Laser Disappears.

			}

			// Checks if Player is Below Enemy Laser, if True then Enemy Laser Disappear & Player Lives Decrease. 
			else if (World[y][x] == P.Player1 && World[y - 1][x] == E.EnemyLaser)   
			{
				World[y - 1][x] = ' ';   // Enemy Laser Disappear.

				P.Lives--;                 // Lives Count Decrease.

				Beep(800, 10);     // Kill Sound.

				if (P.Lives == 0)          // Checks if No lives Left, if True then Game Finished.
				{
					GameContinue = 0;        // Game Finished.

					break;               // Break Loop.
				}
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
				World[y][x] = ' ';            // Player Laser Disappear.

				World[y - 1][x] = ' ';        // Enemy Laser Disappear.

				Beep(200, 3);     // Kill Sound.

			}

			// Checks if Player is Below Enemy Laser, if True then Enemy Laser Disappear & Player Lives Decrease. 
			else if (World[y][x] == E.EnemyLaser && World[y + 1][x] == P.Player1)  
			{
				World[y][x] = ' ';         // Enemy Laser Disappears.

				P.Lives--;                 // Lives Count Decrease.

				Beep(800, 10);     // Kill Sound.

				if (P.Lives == 0)          // Checks if No lives Left, if True then Game Finished.
				{
					GameContinue = 0;        // Game Finished.

					break;               // Break Loop.
				}
			}

			// Checks if Enemy is Above Player Laser, if Enemy Present Above then Enemy is Killed and Player Laser Disappears.
			else if (World[y][x] == P.PlayerLaser && (World[y - 1][x] == E.Enemy1))
			{

				World[y][x] = ' ';          // Player Laser Disappers.

				World[y - 1][x] = ' ';         // Enemy is Killed.

				World[y - 1][x + 1] = ' ';

				World[y - 1][x + 2] = ' ';

				World[y - 1][x - 1] = ' ';

				World[y - 1][x - 2] = ' ';

				E.EnemyCount--;                      // Enemy Count Decreased.

				P.Score = P.Score + 20;               // Player Score Increased.

				Beep(800, 10);     // Kill Sound.

			}

			else if (Difficulty == '1')     // Easy Difficulty.
			{
				// Random Shooting Time for Enemy.
				if (((World[y][x] == E.Enemy1 && World[y][x + 1] == E.Enemy1 && World[y][x + 2] == E.Enemy1)) &&
					(rand() % 9) == 2 && (rand() % 9) == 3 && (rand() % 2) == 0 && World[y + 1][x] != P.PlayerLaser)           
				{
					for (int NewH = y + 1; NewH < ROWS; NewH++)        // Loop to Control Enemy Laser if Another Enemy is Below.
					{
						if (World[NewH][x] == E.Enemy1)           // Checks if Another Enemy is Below, if True Then Enemy Above Does Not Shoot Laser.
						{
							E.EnemyReady = 0;     // Enemy Above Ready is False.

							break;    // Loop Break.
						}

						E.EnemyReady = 1;      //For Enemy not Below, Enemy Above is Ready To Shoot.
					}

					if (E.EnemyReady)    // Enemy Above Ready is True.
					{
						World[y + 1][x + 1] = E.EnemyLaser;       // Enemy Shoots Downwards.

					}
				}
			}

			else if (Difficulty == '2')     // Medium Difficulty.
			{
				if (((World[y][x] == E.Enemy1 && World[y][x + 1] == E.Enemy1 && World[y][x + 2] == E.Enemy1)) &&
					(rand() % 9) == 2 && (rand() % 9) == 5 && World[y + 1][x] != P.PlayerLaser)           // Random Shooting Time for Enemy.
				{
					for (int NewH = y + 1; NewH < ROWS; NewH++)        // Loop to Control Enemy Laser if Another Enemy is Below.
					{
						if (World[NewH][x] == E.Enemy1)           // Checks if Another Enemy is Below, if True Then Enemy Above Does Not Shoot Laser.
						{
							E.EnemyReady = 0;     // Enemy Above Ready is False.

							break;    // Loop Break.
						}

						E.EnemyReady = 1;      //For Enemy not Below, Enemy Above is Ready To Shoot.
					}

					if (E.EnemyReady)    // Enemy Above Ready is True.
					{
						World[y + 1][x + 1] = E.EnemyLaser;       // Enemy Shoots Downwards.
					}
				}
			}

			else if (Difficulty == '3')     // Hard Difficulty.
			{
				if (((World[y][x] == E.Enemy1 && World[y][x + 1] == E.Enemy1 && World[y][x + 2] == E.Enemy1)) &&
					(rand() % 13) == 11 && World[y + 1][x] != P.PlayerLaser)           // Random Shooting Time for Enemy.
				{
					for (int NewH = y + 1; NewH < ROWS; NewH++)        // Loop to Control Enemy Laser if Another Enemy is Below.
					{
						if (World[NewH][x] == E.Enemy1)           // Checks if Another Enemy is Below, if True Then Enemy Above Does Not Shoot Laser.
						{
							E.EnemyReady = 0;     // Enemy Above Ready is False.

							break;    // Loop Break.
						}

						E.EnemyReady = 1;      //For Enemy not Below, Enemy Above is Ready To Shoot.
					}

					if (E.EnemyReady)    // Enemy Above Ready is True.
					{
						World[y + 1][x + 1] = E.EnemyLaser;       // Enemy Shoots Downwards.
					}
				}
			}

			if (World[y][x] == P.PlayerLaser && World[y - 1][x] != E.EnemyLaser && y > 0)   // if Enemy is Not Above Player Laser, Player Laser Continues.
			{
				World[y][x] = ' ';    // Previous Position of Player Laser Disappers.

				World[y - 1][x] = P.PlayerLaser;   // Player Laser Continues Upwards.

			}
		}
	}
}

// Player Movement Depending on Key Pressed. 
void PlayerMovement(Player& P, char& Key)
{
	Key = getKey();        // Get Key from User.

	if (Key == 'a' || Key == 'A')        // In Case of Player Moving Leftwards. 
	{
		for (int x = 2; x < COL - 2; x++)         // Loop through Positive X-Axis.
		{
			// Checks Current Position of Player.
			if (World[ROWS - 1][x] == P.Player1 && World[ROWS - 1][x + 1] == P.Player1 && World[ROWS - 1][x + 2] == P.Player1)        
			{
				World[ROWS - 1][x - 1] = P.Player1;               // Store Player in Previous Positions.

				World[ROWS - 1][x] = P.Player1;

				World[ROWS - 1][x + 1] = P.Player1;

				World[ROWS - 1][x + 2] = ' ';        // Makes Current Position Blank.

				P.PlayerShapeControl = P.PlayerShapeControl - 8;        // Variable i controls Player Shape Movement.

				break;
			}
		}
	}

	if (Key == 'd' || Key == 'D')           //In Case of Player Moving Rightwards.
	{
		for (int x = COL - 4; x > 0; x--)       // Loop through Negative X-Axis.
		{
			// Checks Current Position of Player.
			if (World[ROWS - 1][x] == P.Player1 && World[ROWS - 1][x - 1] == P.Player1 && World[ROWS - 1][x - 2] == P.Player1)    
			{
				World[ROWS - 1][x - 1] = P.Player1;      // Store Player in Forward Positions.

				World[ROWS - 1][x] = P.Player1;

				World[ROWS - 1][x + 1] = P.Player1;

				World[ROWS - 1][x - 2] = ' ';                // Makes Current Position Blank.

				P.PlayerShapeControl = P.PlayerShapeControl + 8;        // Variable i controls Player Shape Movement.

				break;
			}
		}
	}

	if (Key == ' ' && P.LReady > 3)        // In Case of Player Shooting Laser.
	{
		for (int x = 0; x < COL; x++)  // Loop for X Postion of Player As Y Postion is Fixed.
		{
			if (World[ROWS - 1][x] == P.Player1 && World[ROWS - 1][x + 1] == P.Player1)     // Check Current Positon of Player.
			{
				World[ROWS - 2][x + 1] = P.PlayerLaser;     // Place Player Laser One Postion Above Current Position of Player.

				P.LReady = 0;              // Laser Ready set to 0 to Avoid Multiple Shooting by Player.

				Beep(500, 2);   // Shoot Sound. Part of the Time.h Library.

				break;
			}
		}
	}

	if (Key == 'q' || Key == 'Q')    // Manual Exit.
	{
		system("cls");   // Clear Screen.

		cout << endl << endl << "                           Manual Exit   ";       // Exit Message.

		delay(1000);

		GameContinue = 0;      // Game Ends.

	}
}

// Function to Clean Shapes.
void CleaningShapes()
{
	// Cleaning Borders.
	drawLine(4, 1, 4, 300, 0);      //Left Border.

	drawLine(628, 1, 628, 300, 0);   // Right Border.

	// Green Rectangles To Represent Lives.
	drawRectangle(525, 289, 545, 299, 0, 0, 0, 0, 0, 0);   // Cleaning Lives.

	drawRectangle(550, 289, 570, 299, 0, 0, 0, 0, 0, 0);

	drawRectangle(575, 289, 595, 299, 0, 0, 0, 0, 0, 0);
}

// Main Function.
int main()
{
	char Key = NULL, direction = 'l';        // Local Variables Initialized.

	int Difficulty = 0;

	Enemy E;   // User-defined Enemy Structure.

	Player P;   // User-defined Player Structure.

	SetConsoleTextAttribute(hConsole, 11);   // Sets Text Color to Light Blue (11).

	Welcome(Difficulty);                      // Welcome Message.

	showConsoleCursor(false);          // Remove Cursor.

	delay(1000);    // Wait 1000 milliseconds.

	cls();   // Clear Screen.

	fontsize(8, 12);  // Adjusting Font Size For Game.

	SetConsoleTextAttribute(hConsole, 55);  // Set Console Background to Blue & Text Color to White.

	// Major Loop To Control Game, Terminates When Either All Enemies are Killed OR Player Lives are 0 OR Enemies Reach Player.
	while (E.EnemyCount > 0 && GameContinue)        
	{
		E.EnemyDrop = 0;    // Enemy Drop Control Variable.

		system("cls");  // Clear Screen.

		P.LReady = P.LReady + 1;        // Player Laser Shooting  Control Variable.

		DisplayWorld(P.Score, P.Lives);      // Display 2D World|Array.

		ShapeInitialize(P.PlayerShapeControl, P.Lives);  // Shapes Display.

		LaserControl(P, E, Difficulty);    // Laser Mechanics.

		EnemyMovement(E, direction); // Enemy Movement Mechanics.

		PlayerMovement(P, Key);     // Player Movement Mechanics.

		delay(50);    // Wait 50 milliseconds.

	}

	delay(500);    // Wait 500 milliseconds.

	CleaningShapes();   // Clean Shapes.

	system("cls");   // Clear Screen.

	fontsize(10, 18);   // Adjusting Font Size For Output Message Display.

	OutputMessage(P.Score, P.Lives, E.EnemyCount);   // Display Output Message.

	system("pause");   // Program Terminate.
}


