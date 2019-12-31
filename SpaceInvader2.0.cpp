#include "pch.h"
#include <iostream>
#include "mygraphics.h"
#include <conio.h>
#include <windows.h>
#include <time.h>
using namespace std;

HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);        // Part of the Font Size Adjustement Function.

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);     // Part of the Font Color Function.

// Global Variable.
bool GameContinue = true;

// Font Size Adjustment.
void fontsize(int a, int b) {
	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
	lpConsoleCurrentFontEx->dwFontSize.X = a;     // Width(Pixel) of Font.
	lpConsoleCurrentFontEx->dwFontSize.Y = b;     // Height(Pixel) of Font.
	SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
}

//2-D Array that User Interacts With or Experiences. Parallel to the 2-D that works at back end.
char FrontEndWorld[25][80] = {
  "                                                                               ",
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
  "|                                                                             |",
  "|                                                                             |",
  "|                                                                             |",
  "|                                                                             |",
};

//2-D Array used to Initialize World that works at back end.
char World[25][80] = {
  "                                                                               ",
  "|                                                                             |",
  "|    aaa           sss              ccc               ooo               eee   |",
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
  "|    zzz           mmm              nnn               uuu               rrr   |",
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
void ShapeInitialize(int E1, int E2, int E3, int E4, int E5, int E6, int E7, int E8, int E9, int E10, int i, int j, int k, int Lives)
{
	HWND console = GetConsoleWindow();                          // Fixing console windwow dimension to avoid shapes being dispersed on different computers.
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);
	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 670, 380, TRUE);            // Width=670 , Height=380

	// Enemies.

	// Top Enemies.
	if (E4 != 0)
	{
		drawRectangle(430 + j, 15 + k, 457 + j, 30 + k, 255, 0, 0, 255, 0, 0);     // Enemy 4.              
	}
	if (E3 != 0)
	{
		drawRectangle(285 + j, 15 + k, 312 + j, 30 + k, 255, 0, 0, 255, 0, 0);     // Enemy 3.
	}
	if (E2 != 0)
	{
		drawRectangle(150 + j, 15 + k, 177 + j, 30 + k, 255, 0, 0, 255, 0, 0);     // Enemy 2.
	}
	if (E1 != 0)
	{
		drawRectangle(36 + j, 15 + k, 63 + j, 30 + k, 255, 0, 0, 255, 0, 0);       // Enemy 1.
	}
	if (E5 != 0)
	{
		drawRectangle(573 + j, 15 + k, 600 + j, 30 + k, 255, 0, 0, 255, 0, 0);       // Enemy 5.
	}

	// Bottom Enemies.

	if (E6 != 0)
	{
		drawRectangle(36 + j, 147 + k, 63 + j, 162 + k, 255, 0, 0, 255, 0, 0);     // Enemy 6.
	}
	if (E7 != 0)
	{
		drawRectangle(150 + j, 147 + k, 177 + j, 162 + k, 255, 0, 0, 255, 0, 0);     // Enemy 7.
	}
	if (E8 != 0)
	{
		drawRectangle(285 + j, 147 + k, 312 + j, 162 + k, 255, 0, 0, 255, 0, 0);     // Enemy 8.
	}
	if (E9 != 0)
	{
		drawRectangle(430 + j, 147 + k, 457 + j, 162 + k, 255, 0, 0, 255, 0, 0);     // Enemy 9.                
	}
	if (E10 != 0)
	{
		drawRectangle(573 + j, 147 + k, 600 + j, 162 + k, 255, 0, 0, 255, 0, 0);    // Enemy 10.
	}


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

// Enemy Shape Delete.
void EnemyShapeDelete(int E1, int E2, int E3, int E4, int E5, int E6, int E7, int E8, int E9, int E10, int j, int k)
{
	
	// Top Enemies.
	drawRectangle(430 + j, 15 + k, 457 + j, 30 + k, 0, 0, 0, 0, 0, 0);     // Enemy 4.              
	
	
	drawRectangle(285 + j, 15 + k, 312 + j, 30 + k, 0, 0, 0, 0, 0, 0);     // Enemy 3.
	

	drawRectangle(150 + j, 15 + k, 177 + j, 30 + k, 0, 0, 0, 0, 0, 0);     // Enemy 2.
	

	drawRectangle(36 + j, 15 + k, 63 + j, 30 + k, 0, 0, 0, 0, 0, 0);       // Enemy 1.
	
	
	drawRectangle(573 + j, 15 + k, 600 + j, 30 + k, 0, 0, 0, 0, 0, 0);       // Enemy 5.


	// Bottom Enemies.


	drawRectangle(36 + j, 147 + k, 63 + j, 162 + k, 0, 0, 0, 0, 0, 0);     // Enemy 6.
	
	
	drawRectangle(150 + j, 147 + k, 177 + j, 162 + k, 0, 0, 0, 0, 0, 0);     // Enemy 7.
	

	drawRectangle(285 + j, 147 + k, 312 + j, 162 + k, 0, 0, 0, 0, 0, 0);     // Enemy 8.

	
	drawRectangle(430 + j, 147 + k, 457 + j, 162 + k, 0, 0, 0, 0, 0, 0);     // Enemy 9.  


	drawRectangle(573 + j, 147 + k, 600 + j, 162 + k, 0, 0, 0, 0, 0, 0);    // Enemy 10.
	

}


// Enemy Movements.
void EnemyMovement(char Enemy1, char Enemy2, char Enemy3, char Enemy4, char Enemy5, char Enemy6, char Enemy7, char Enemy8, char Enemy9, char Enemy10, char& direction, int Height, int Width, int& drop, double& j, double& k)
{
	for (int y = 0; y < Height - 1; y++)               // For loop through height of World Array.
	{
		if ((World[y][2] == Enemy1 && World[y][3] == Enemy1 && World[y][4] == Enemy1) || (World[y][2] == Enemy2 && World[y][3] == Enemy2 && World[y][4] == Enemy2) || (World[y][2] == Enemy3 && World[y][3] == Enemy3 && World[y][4] == Enemy3) || (World[y][2] == Enemy4 && World[y][3] == Enemy4 && World[y][4] == Enemy4) || (World[y][2] == Enemy5 && World[y][3] == Enemy5 && World[y][4] == Enemy5) || (World[y][2] == Enemy6 && World[y][3] == Enemy6 && World[y][4] == Enemy6) || (World[y][2] == Enemy7 && World[y][3] == Enemy7 && World[y][4] == Enemy7) || (World[y][2] == Enemy8 && World[y][3] == Enemy8 && World[y][4] == Enemy8) || (World[y][2] == Enemy9 && World[y][3] == Enemy9 && World[y][4] == Enemy9) || (World[y][2] == Enemy10 && World[y][3] == Enemy10 && World[y][4] == Enemy10))                    // Check if Enemy is present at left most corner.
		{
			direction = 'r';                       // Set Direction to Right

			drop = 1;                                   // Drop is true

			break;
		}
		if ((World[y][Width - 3] == Enemy1 && World[y][Width-4] == Enemy1 && World[y][Width-5] == Enemy1) || (World[y][Width - 3] == Enemy2 && World[y][Width - 4] == Enemy2 && World[y][Width - 5] == Enemy2) || (World[y][Width - 3] == Enemy3 && World[y][Width - 4] == Enemy3 && World[y][Width - 5] == Enemy3) || (World[y][Width - 3] == Enemy4 && World[y][Width - 4] == Enemy4 && World[y][Width - 5] == Enemy4) || (World[y][Width - 3] == Enemy5 && World[y][Width - 4] == Enemy5 && World[y][Width - 5] == Enemy5) || (World[y][Width - 3] == Enemy6 && World[y][Width - 4] == Enemy6 && World[y][Width - 5] == Enemy6) || (World[y][Width - 3] == Enemy7 && World[y][Width - 4] == Enemy7 && World[y][Width - 5] == Enemy7) || (World[y][Width - 3] == Enemy8 && World[y][Width - 4] == Enemy8 && World[y][Width - 5] == Enemy8) || (World[y][Width - 3] == Enemy9 && World[y][Width - 4] == Enemy9 && World[y][Width - 5] == Enemy9) || (World[y][Width - 3] == Enemy10 && World[y][Width - 4] == Enemy10 && World[y][Width - 5] == Enemy10))          // Check if Enemy is present at right most corner.
		{
			direction = 'l';                         // Set Direction to Left.

			drop = 1;                             // Drop is true.

			break;
		}
	}

	if (rand() % 13 == 3)                                // Random Moving Time for Enemy.
	{
		if (direction == 'l')                                       // if direction to move is set to left.
		{
			for (int x = 2; x <= Width - 3; x++)                       // Nested loop through all possible postion of enemy array.
			{
				for (int y = 0; y < Height; y++)
				{
					if (drop && ((World[y - 1][x + 1] == Enemy1 && World[y-1][x+2] == Enemy1 && World[y-1][x+3] == Enemy1) || (World[y - 1][x + 1] == Enemy2 && World[y - 1][x + 2] == Enemy2 && World[y - 1][x + 3] == Enemy2) || (World[y - 1][x + 1] == Enemy3 && World[y-1][x+2] == Enemy3 && World[y-1][x+3] == Enemy3) || (World[y - 1][x + 1] == Enemy4 && World[y - 1][x + 2] == Enemy4 && World[y - 1][x + 3] == Enemy4) || (World[y - 1][x + 1] == Enemy5 && World[y - 1][x + 2] == Enemy5 && World[y - 1][x + 3] == Enemy5) || (World[y - 1][x + 1] == Enemy6 && World[y - 1][x + 2] == Enemy6 && World[y - 1][x + 3] == Enemy6) || (World[y - 1][x + 1] == Enemy7 && World[y - 1][x + 2] == Enemy7 && World[y - 1][x + 3] == Enemy7) || (World[y - 1][x + 1] == Enemy8 && World[y - 1][x + 2] == Enemy8 && World[y - 1][x + 3] == Enemy8) || (World[y - 1][x + 1] == Enemy9 && World[y - 1][x + 2] == Enemy9 && World[y - 1][x + 3] == Enemy9) || (World[y - 1][x + 1] == Enemy10 && World[y - 1][x + 2] == Enemy10 && World[y - 1][x + 3] == Enemy10)))           // if drop is true and Enemy present at postion.
					{
						World[y][x] = World[y - 1][x + 1];                // Store Enemy One Block downwards diagonally Leftwards (/).

						World[y][x + 1] = World[y - 1][x + 2];

						World[y][x + 2] = World[y - 1][x + 3];

						World[y - 1][x + 1] = ' ';                               // Previous Positions of Enemy Erased.

						World[y - 1][x + 2] = ' ';

						World[y - 1][x + 3] = ' ';

				
						k = k + 1.2;             // Enemy Shape Vertical Control Variable.

						j = j - 1;           // Enemy Shape Horizontal Control Variable.


					}
					else if (!drop && ((World[y][x + 1] == Enemy1 && World[y][x+2] == Enemy1 && World[y][x+3] == Enemy1) || (World[y][x + 1] == Enemy2 && World[y][x + 2] == Enemy2 && World[y][x + 3] == Enemy2) || (World[y][x + 1] == Enemy3 && World[y][x + 2] == Enemy3 && World[y][x + 3] == Enemy3) || (World[y][x + 1] == Enemy4 && World[y][x + 2] == Enemy4 && World[y][x + 3] == Enemy4) || (World[y][x + 1] == Enemy5 && World[y][x + 2] == Enemy5 && World[y][x + 3] == Enemy5) || (World[y][x + 1] == Enemy6 && World[y][x + 2] == Enemy6 && World[y][x + 3] == Enemy6) || (World[y][x + 1] == Enemy7 && World[y][x + 2] == Enemy7 && World[y][x + 3] == Enemy7) || (World[y][x + 1] == Enemy8 && World[y][x + 2] == Enemy8 && World[y][x + 3] == Enemy8) || (World[y][x + 1] == Enemy9 && World[y][x + 2] == Enemy9 && World[y][x + 3] == Enemy9) || (World[y][x + 1] == Enemy10 && World[y][x + 2] == Enemy10 && World[y][x + 3] == Enemy10)))          // if drop not true and Enemy present at position
					{
						World[y][x + 2] = World[y][x + 3];            // Store Enemy One Block Leftwards.

						World[y][x + 1] = World[y][x + 2];

						World[y][x] = World[y][x + 1];                  

						World[y][x + 3] = ' ';                               // Previous Position of Enemy Erased.

						j = j - 0.80;               // Enemy Shape Horizontal Control Variable.
					}
				}
			}
		}
		else if (direction == 'r')                     // if direction to move is set to Right.
		{
			for (int x = Width - 3; x >= 2; x--)                          // Nested loop through all possible postions of enemy in array.
			{
				for (int y = 0; y < Height; y++)
				{
					if (drop && ((World[y - 1][x - 1] == Enemy1 && World[y-1][x-2] == Enemy1 && World[y-1][x-3] == Enemy1) || (World[y - 1][x - 1] == Enemy2 && World[y - 1][x - 2] == Enemy2 && World[y - 1][x - 3] == Enemy2) || (World[y - 1][x - 1] == Enemy3 && World[y - 1][x - 2] == Enemy3 && World[y - 1][x - 3] == Enemy3) || (World[y - 1][x - 1] == Enemy4 && World[y - 1][x - 2] == Enemy4 && World[y - 1][x - 3] == Enemy4) || (World[y - 1][x - 1] == Enemy5 && World[y - 1][x - 2] == Enemy5 && World[y - 1][x - 3] == Enemy5) || (World[y - 1][x - 1] == Enemy6 && World[y - 1][x - 2] == Enemy6 && World[y - 1][x - 3] == Enemy6) || (World[y - 1][x - 1] == Enemy7 && World[y - 1][x - 2] == Enemy7 && World[y - 1][x - 3] == Enemy7) || (World[y - 1][x - 1] == Enemy8 && World[y - 1][x - 2] == Enemy8 && World[y - 1][x - 3] == Enemy8) || (World[y - 1][x - 1] == Enemy9 && World[y - 1][x - 2] == Enemy9 && World[y - 1][x - 3] == Enemy9) || (World[y - 1][x - 1] == Enemy10 && World[y - 1][x - 2] == Enemy10 && World[y - 1][x - 3] == Enemy10)))               // if drop is true and Enemy present at postion.
					{
						World[y][x - 2] = World[y - 1][x - 3];          // Store Enemy One Block downwards diagonally Rightwards (\).

						World[y][x - 1] = World[y - 1][x - 2];

						World[y][x] = World[y - 1][x - 1];             

						World[y - 1][x - 1] = ' ';                              // Previous Positions of Enemy Erased.

						World[y - 1][x - 2] = ' ';

						World[y - 1][x - 3] = ' ';

					
						k = k + 1.2;                 // Enemy Shape Vertical Control Variable.

						j = j + 1;              // Enemy Shape Horizontal Control Variable.

					}
					else if (!drop && ((World[y][x - 1] == Enemy1 && World[y][x - 2] == Enemy1 && World[y][x-3] == Enemy1) || (World[y][x - 1] == Enemy2 && World[y][x - 2] == Enemy2 && World[y][x - 3] == Enemy2) || (World[y][x - 1] == Enemy3 && World[y][x - 2] == Enemy3 && World[y][x - 3] == Enemy3) || (World[y][x - 1] == Enemy4 && World[y][x - 2] == Enemy4 && World[y][x - 3] == Enemy4) || (World[y][x - 1] == Enemy5 && World[y][x - 2] == Enemy5 && World[y][x - 3] == Enemy5) || (World[y][x - 1] == Enemy6 && World[y][x - 2] == Enemy6 && World[y][x - 3] == Enemy6) || (World[y][x - 1] == Enemy7 && World[y][x - 2] == Enemy7 && World[y][x - 3] == Enemy7) || (World[y][x - 1] == Enemy8 && World[y][x - 2] == Enemy8 && World[y][x - 3] == Enemy8) || (World[y][x - 1] == Enemy9 && World[y][x - 2] == Enemy9 && World[y][x - 3] == Enemy9) || (World[y][x - 1] == Enemy10 && World[y][x - 2] == Enemy10 && World[y][x - 3] == Enemy10)))                          // if drop not true and Enemy present at position
					{
						World[y][x] = World[y][x - 1];                // Store Enemy One Block Rightwards.

						World[y][x - 2] = World[y][x - 3];

						World[y][x - 1] = World[y][x - 2];
						                                                 

						World[y][x - 3] = ' ';                                   // Previous Position of Enemy Erased.
						

						j = j + 0.80;                   // Enemy Shape Horizontal Control Variable.
					}
				}
			}
		}
		
	}
	for (int x = 2; x < Width-2; x++)                          // For loop to check if Enemy is at last stage to Player.
	{
		if (World[Height - 4][x] == Enemy1 || World[Height - 4][x] == Enemy2 || World[Height - 4][x] == Enemy3 || World[Height - 4][x] == Enemy4 || World[Height - 4][x] == Enemy5 || World[Height - 2][x] == Enemy6 || World[Height - 2][x] == Enemy7 || World[Height - 2][x] == Enemy8 || World[Height - 2][x] == Enemy9 || World[Height - 2][x] == Enemy10)                  // if Enemy parallel to player is true. 
		{
			GameContinue = 0;                       // Game Ends.
		}
	}

}

//Output Message At the End of Game.
void OutputMessage(int Score, int Lives, int EnemyCount)
{
	if (Lives > 0 && EnemyCount == 0)      // If Player Wins
	{
		cout << "         Well Played!        ";                 // Message to Player At End.

		cout << endl << endl << endl;
	
		cout << "                 Your Score is : " << Score;                    // Display Score At End.

		cout << endl << endl << endl << endl;
		
	}
	else           // If Player Loses or Quits.
	{
		cout << "         Better Luck Next Time!        ";                 // Message to Player At End.

		cout << endl << endl << endl;
		
		cout << "                 Your Score is : " << Score;                    // Display Score At End.

		cout << endl << endl << endl << endl;
		
	}
}

//Welcome Message Before Starting Game.
void Welcome(int& Difficulty)
{
	//Welcome Screen.
	fontsize(10, 18);   // Adjusting Font Size For Message Display.

	showConsoleCursor(false);

	cout << "                        WELCOME TO SPACE INVADERS! ";    // Welcome To the Game.

	cout << endl;

	delay(2000);    // Delay for 2000 milliseconds.

	cls();    // Clear Screen.s

	cout << "                        Choose Difficulty Level : ";

	cout << endl << endl;

	cout << "                        Press 1: Easy -----> For Beginners! ";     // Press 1 for Easy Difficulty.

	cout << endl << endl;
	
	cout << "                        Press 2: Medium -----> For Regular Players! ";       // Press 2 for Medium Difficulty.

	cout << endl << endl;
	
	cout << "                        Press 3: Hard -----> You Will Not Survive! ";    // Press 3 for Hard Difficulty.

	do     // Loop for Validation.
	{
		Difficulty = _getch();      // Gets key from User.

	} while (Difficulty != '1' && Difficulty != '2' && Difficulty != '3');      // Repeat until Valid Difficulty Selected.

	delay(400);   // Delay for 400 milliseconds.
}

//Displaying World After Every Change.
void DisplayWorld(int Height, int Width, int Score, int Lives)
{
	for (int y = 1; y < Height; y++)          // Loop to Display World|Array.
	{
		cout << FrontEndWorld[y] << endl;
	}
	cout << "    SCORE : " << Score << "                                        LIVES: " << Lives;  // Score & Lives Display.
}

//Laser System For Enemies & Player.
void LaserControl(char Player, char PlayerLaser, char Enemy1, char Enemy2, char Enemy3, char Enemy4, char Enemy5, char Enemy6, char Enemy7, char Enemy8, char Enemy9, char Enemy10, char EnemyLaser, int& Score, int& Lives, bool& GameContinue, int& EnemyCount, int& EnemyReady, int& LaserReady, int Height, int Width, int& E1, int& E2, int& E3, int& E4, int& E5, int& E6, int& E7, int& E8, int& E9, int& E10, int& LifeDecrease, int Difficulty)
{
	for (int x = 0; x < Width; x++)                                   // Nested Loops to Display Enemy Laser.
	{
		for (int y = Height - 1; y > 0; y--)
		{
			if (World[y][x] == EnemyLaser && (World[y + 1][x] == PlayerLaser))     // Checks if Enemy Laser is Above Player Laser, if True then Both Laser Disappear.
			{
				World[y][x] = ' ';                // Enemy Laser Disappear.

				World[y + 1][x] = ' ';    // Player Laser Disappear.
			}

			if (FrontEndWorld[y][x] == EnemyLaser && (FrontEndWorld[y + 1][x] == PlayerLaser))     // Checks if Enemy Laser is Above Player Laser, if True then Both Laser Disappear.
			{
				FrontEndWorld[y][x] = ' ';                // Enemy Laser Disappear.

				FrontEndWorld[y + 1][x] = ' ';    // Player Laser Disappear.
			}


			else if (World[y][x] == EnemyLaser && (World[y + 1][x] != Enemy1 || World[y + 1][x] != Enemy2 || World[y + 1][x] != Enemy3 || World[y + 1][x] != Enemy4 || World[y + 1][x] != Enemy5 || World[y + 1][x] != Enemy6 || World[y + 1][x] != Enemy7 || World[y + 1][x] != Enemy8 || World[y + 1][x] != Enemy9 || World[y + 1][x] != Enemy10))     // Checks if Enemy is Below Enemy Laser. If Enemy is Below, Enemy Laser Disappers, Else it Continues.
			{
				World[y + 1][x] = EnemyLaser;     // Enemy Laser Continues.

				World[y][x] = ' ';    // Previous Position of Enemy Laser Disappers.

				FrontEndWorld[y + 1][x] = EnemyLaser;       // Enemy Laser Continues.

				FrontEndWorld[y][x] = ' ';        // Previous Position of Enemy Laser Disappers.
			}

			else if (World[y][x] == EnemyLaser && (World[y + 1][x] == Enemy1 || World[y + 1][x] == Enemy2 || World[y + 1][x] == Enemy3 || World[y + 1][x] == Enemy4 || World[y + 1][x] == Enemy5 || World[y + 1][x] == Enemy6 || World[y + 1][x] == Enemy7 || World[y + 1][x] == Enemy8 || World[y + 1][x] == Enemy9 || World[y + 1][x] == Enemy10))       // If Enemy Below Enemy Laser
			{
				World[y][x] = ' ';  // Enemy Laser Disappears.

				FrontEndWorld[y][x] = ' ';      // Enemy Laser Disappears.
			}

			else if (World[y][x] == Player && World[y - 1][x] == EnemyLaser)     // Checks if Player is Below Enemy Laser, if True then Enemy Laser Disappear & Player Lives Decrease. 
			{
				World[y - 1][x] = ' ';   // Enemy Laser Disappear.

				FrontEndWorld[y - 1][x] = ' ';        // Enemy Laser Disappear.

				Lives--;                 // Lives Count Decrease.

				LifeDecrease++;

				if (Lives == 0)          // Checks if No lives Left, if True then Game Finished.
				{
					GameContinue = 0;        // Game Finished.

					break;               // Break Loop.
				}
			}

		}
	}
	for (int x = 0; x < Width; x++)                            // Nested Loops to Control Player Laser & Enemy Laser.
	{
		for (int y = 0; y < Height; y++)
		{
			if (World[y][x] == PlayerLaser && World[y - 1][x] == EnemyLaser)  // Checks if Enemy Laser is Above Player Laser, if True then Both Laser Disappear.
			{
				World[y][x] = ' ';            // Player Laser Disappear.

				World[y - 1][x] = ' ';        // Enemy Laser Disappear.

				FrontEndWorld[y][x] = ' ';      // Player Laser Disappear.

				FrontEndWorld[y - 1][x] = ' ';       // Enemy Laser Disappear.
			}

			else if (World[y][x] == EnemyLaser && World[y + 1][x] == Player)  // Checks if Player is Below Enemy Laser, if True then Enemy Laser Disappear & Player Lives Decrease. 
			{

				World[y][x] = ' ';         // Enemy Laser Disappears.

				FrontEndWorld[y][x] = ' ';     // Enemy Laser Disappears.

				Lives--;                 // Lives Count Decrease.

				LifeDecrease++;

				if (Lives == 0)          // Checks if No lives Left, if True then Game Finished.
				{
					GameContinue = 0;        // Game Finished.

					break;               // Break Loop.
				}
			}

			else if (World[y][x] == PlayerLaser && (World[y - 1][x] == Enemy1 || World[y - 1][x] == Enemy2 || World[y - 1][x] == Enemy3 || World[y - 1][x] == Enemy4 || World[y - 1][x] == Enemy5 || World[y - 1][x] == Enemy6 || World[y - 1][x] == Enemy7 || World[y - 1][x] == Enemy8 || World[y - 1][x] == Enemy9 || World[y - 1][x] == Enemy10))    // Checks if Enemy is Above Player Laser, if Enemy Present Above then Enemy is Killed and Player Laser Disappears.
			{
				
				// Additional Enemy Alive|Dead Checks will be added here depending on their coordinates in the 2D World Array.

				if (World[y - 1][x] == Enemy1)          // Enemy 1 Position in Array.
				{
					E1 = 0;      // Enemy Dead.
				}
				else if (World[y - 1][x] == Enemy2)        // Enemy 2 Position in Array.
				{
					E2 = 0;           // Enemy Dead.
				}
				else if (World[y - 1][x] == Enemy3)        // Enemy 3 Position in Array.
				{
					E3 = 0;      // Enemy Dead.
				}
				else if (World[y - 1][x] == Enemy4)        // Enemy 4 Position in Array.
				{
					E4 = 0;       // Enemy Dead.
				}
				else if (World[y - 1][x] == Enemy5)      // Enemy 5 Position in Array.
				{
					E5 = 0;         // Enemy Dead.
				}
				else if (World[y - 1][x] == Enemy6)     // Enemy 6 Position in Array.
				{
					E6 = 0;       // Enemy Dead.
				}
				else if (World[y - 1][x] == Enemy7)      // Enemy 7 Position in Array.
				{
					E7 = 0;        // Enemy Dead.
				}
				else if (World[y - 1][x] == Enemy8)       // Enemy 8 Position in Array.
				{
					E8 = 0;             // Enemy Dead.
				}
				else if (World[y - 1][x] == Enemy9)      // Enemy 9 Position in Array.
				{
					E9 = 0;          // Enemy Dead.
				}
				else if (World[y - 1][x] == Enemy10)      // Enemy 10 Position in Array.
				{

					E10 = 0;          // Enemy Dead.
				}

				World[y][x] = ' ';          // Player Laser Disappers.

				FrontEndWorld[y][x] = ' ';

				World[y - 1][x] = ' ';         // Enemy is Killed.

				World[y - 1][x + 1] = ' ';

				World[y - 1][x + 2] = ' ';

				World[y - 1][x - 1] = ' ';

				World[y - 1][x - 2] = ' ';

				EnemyCount--;                      // Enemy Count Decreased.

				Score = Score + 20;               // Player Score Increased.

				Beep(800, 10);     // Kill Sound.

			}

			if (Difficulty == '1')     // Easy Difficulty.
			{
				if (((World[y][x] == Enemy1 && World[y][x + 1] == Enemy1 && World[y][x + 2] == Enemy1) || (World[y][x] == Enemy2 && World[y][x + 1] == Enemy2 && World[y][x + 2] == Enemy2) || (World[y][x] == Enemy3 && World[y][x + 1] == Enemy3 && World[y][x + 2] == Enemy3) || (World[y][x] == Enemy4 && World[y][x + 1] == Enemy4 && World[y][x + 2] == Enemy4) || (World[y][x] == Enemy5 && World[y][x + 1] == Enemy5 && World[y][x + 2] == Enemy5) || (World[y][x] == Enemy6 && World[y][x + 1] == Enemy6 && World[y][x + 2] == Enemy6) || (World[y][x] == Enemy7 && World[y][x + 1] == Enemy7 && World[y][x + 2] == Enemy7) || (World[y][x] == Enemy8 && World[y][x + 1] == Enemy8 && World[y][x + 2] == Enemy8) || (World[y][x] == Enemy9 && World[y][x + 1] == Enemy9 && World[y][x + 2] == Enemy9) || (World[y][x] == Enemy10 && World[y][x + 1] == Enemy10 && World[y][x + 2] == Enemy10)) && (rand() % 9) == 2 && (rand() % 9) == 3 && (rand() % 9) == 3 && World[y + 1][x] != PlayerLaser)           // Random Shooting Time for Enemy.
				{
					for (int NewH = y + 1; NewH < Height; NewH++)        // Loop to Control Enemy Laser if Another Enemy is Below.
					{
						if (World[NewH][x] == Enemy1 || World[NewH][x] == Enemy2 || World[NewH][x] == Enemy3 || World[NewH][x] == Enemy4 || World[NewH][x] == Enemy5 || World[NewH][x] == Enemy6 || World[NewH][x] == Enemy7 || World[NewH][x] == Enemy8 || World[NewH][x] == Enemy9 || World[NewH][x] == Enemy10)           // Checks if Another Enemy is Below, if True Then Enemy Above Does Not Shoot Laser.
						{
							EnemyReady = 0;     // Enemy Above Ready is False.

							break;    // Loop Break.
						}
						EnemyReady = 1;      //For Enemy not Below, Enemy Above is Ready To Shoot.
					}
					if (EnemyReady)    // Enemy Above Ready is True.
					{
						World[y + 1][x + 1] = EnemyLaser;       // Enemy Shoots Downwards.

						FrontEndWorld[y + 1][x + 1] = EnemyLaser;   // Enemy Shoots Downwards.
					}
				}
			}


			if (Difficulty == '2')     // Medium Difficulty.
			{
				if (((World[y][x] == Enemy1 && World[y][x + 1] == Enemy1 && World[y][x + 2] == Enemy1) || (World[y][x] == Enemy2 && World[y][x + 1] == Enemy2 && World[y][x + 2] == Enemy2) || (World[y][x] == Enemy3 && World[y][x + 1] == Enemy3 && World[y][x + 2] == Enemy3) || (World[y][x] == Enemy4 && World[y][x + 1] == Enemy4 && World[y][x + 2] == Enemy4) || (World[y][x] == Enemy5 && World[y][x + 1] == Enemy5 && World[y][x + 2] == Enemy5) || (World[y][x] == Enemy6 && World[y][x + 1] == Enemy6 && World[y][x + 2] == Enemy6) || (World[y][x] == Enemy7 && World[y][x + 1] == Enemy7 && World[y][x + 2] == Enemy7) || (World[y][x] == Enemy8 && World[y][x + 1] == Enemy8 && World[y][x + 2] == Enemy8) || (World[y][x] == Enemy9 && World[y][x + 1] == Enemy9 && World[y][x + 2] == Enemy9) || (World[y][x] == Enemy10 && World[y][x + 1] == Enemy10 && World[y][x + 2] == Enemy10)) && (rand() % 9) == 2 && (rand() % 9) == 5 && World[y + 1][x] != PlayerLaser)           // Random Shooting Time for Enemy.
				{
					for (int NewH = y + 1; NewH < Height; NewH++)        // Loop to Control Enemy Laser if Another Enemy is Below.
					{
						if (World[NewH][x] == Enemy1 || World[NewH][x] == Enemy2 || World[NewH][x] == Enemy3 || World[NewH][x] == Enemy4 || World[NewH][x] == Enemy5 || World[NewH][x] == Enemy6 || World[NewH][x] == Enemy7 || World[NewH][x] == Enemy8 || World[NewH][x] == Enemy9 || World[NewH][x] == Enemy10)           // Checks if Another Enemy is Below, if True Then Enemy Above Does Not Shoot Laser.
						{
							EnemyReady = 0;     // Enemy Above Ready is False.

							break;    // Loop Break.
						}
						EnemyReady = 1;      //For Enemy not Below, Enemy Above is Ready To Shoot.
					}
					if (EnemyReady)    // Enemy Above Ready is True.
					{
						World[y + 1][x + 1] = EnemyLaser;       // Enemy Shoots Downwards.

						FrontEndWorld[y + 1][x + 1] = EnemyLaser;   // Enemy Shoots Downwards.
					}
				}
			}

			if (Difficulty == '3')     // Hard Difficulty.
			{
				if (((World[y][x] == Enemy1 && World[y][x + 1] == Enemy1 && World[y][x + 2] == Enemy1) || (World[y][x] == Enemy2 && World[y][x + 1] == Enemy2 && World[y][x + 2] == Enemy2) || (World[y][x] == Enemy3 && World[y][x + 1] == Enemy3 && World[y][x + 2] == Enemy3) || (World[y][x] == Enemy4 && World[y][x + 1] == Enemy4 && World[y][x + 2] == Enemy4) || (World[y][x] == Enemy5 && World[y][x + 1] == Enemy5 && World[y][x + 2] == Enemy5) || (World[y][x] == Enemy6 && World[y][x + 1] == Enemy6 && World[y][x + 2] == Enemy6) || (World[y][x] == Enemy7 && World[y][x + 1] == Enemy7 && World[y][x + 2] == Enemy7) || (World[y][x] == Enemy8 && World[y][x + 1] == Enemy8 && World[y][x + 2] == Enemy8) || (World[y][x] == Enemy9 && World[y][x + 1] == Enemy9 && World[y][x + 2] == Enemy9) || (World[y][x] == Enemy10 && World[y][x + 1] == Enemy10 && World[y][x + 2] == Enemy10)) && (rand() % 9) == 7 && World[y + 1][x] != PlayerLaser)           // Random Shooting Time for Enemy.
				{
					for (int NewH = y + 1; NewH < Height; NewH++)        // Loop to Control Enemy Laser if Another Enemy is Below.
					{
						if (World[NewH][x] == Enemy1 || World[NewH][x] == Enemy2 || World[NewH][x] == Enemy3 || World[NewH][x] == Enemy4 || World[NewH][x] == Enemy5 || World[NewH][x] == Enemy6 || World[NewH][x] == Enemy7 || World[NewH][x] == Enemy8 || World[NewH][x] == Enemy9 || World[NewH][x] == Enemy10)           // Checks if Another Enemy is Below, if True Then Enemy Above Does Not Shoot Laser.
						{
							EnemyReady = 0;     // Enemy Above Ready is False.

							break;    // Loop Break.
						}
						EnemyReady = 1;      //For Enemy not Below, Enemy Above is Ready To Shoot.
					}
					if (EnemyReady)    // Enemy Above Ready is True.
					{
						World[y + 1][x + 1] = EnemyLaser;       // Enemy Shoots Downwards.

						FrontEndWorld[y + 1][x + 1] = EnemyLaser;   // Enemy Shoots Downwards.
					}
				}
			}




			else if (World[y][x] == PlayerLaser && World[y - 1][x] != EnemyLaser && y > 0)   // if Enemy is Not Above Player Laser, Player Laser Continues.
			{
				World[y][x] = ' ';    // Previous Position of Player Laser Disappers.

				World[y - 1][x] = PlayerLaser;   // Player Laser Continues Upwards.

				FrontEndWorld[y][x] = ' ';    // Previous Position of Player Laser Disappers.

				FrontEndWorld[y - 1][x] = PlayerLaser;    // Player Laser Continues Upwards.
			}
		}
	}


}

// Player Movement Depending on Key Pressed. 
void PlayerMovement(char Player, char PlayerLaser, char& Key, int& LaserReady, int Height, int Width, int& i, int Lives)
{

	Key = getKey();        // Get Key from User.

	if (Key == 'a' || Key == 'A')        // In Case of Player Moving Leftwards. 
	{
		for (int x = 2; x < Width - 2; x++)         // Loop through Positive X-Axis.
		{
			if (World[Height - 1][x] == Player && World[Height - 1][x+1] == Player && World[Height - 1][x + 2] == Player)        // Checks Current Position of Player.
			{
				World[Height - 1][x - 1] = Player;               // Store Player in Previous Positions.

				World[Height - 1][x] = Player;

				World[Height - 1][x + 1] = Player;

				World[Height - 1][x + 2] = ' ';        // Makes Current Position Blank.

				i = i - 8;        // Variable i controls Player Shape Movement.

				break;
			}
		}

	}

	if (Key == 'd' || Key == 'D')           //In Case of Player Moving Rightwards.
	{
		for (int x = Width - 4; x > 0; x--)       // Loop through Negative X-Axis.
		{
			if (World[Height - 1][x] == Player && World[Height - 1][x - 1] == Player && World[Height - 1][x - 2] == Player)    // Checks Current Position of Player.
			{
				World[Height - 1][x-1] = Player;      // Store Player in Forward Positions.

				World[Height - 1][x] = Player;

				World[Height - 1][x + 1] = Player;

				World[Height - 1][x - 2] = ' ';                // Makes Current Position Blank.

				i = i + 8;        // Variable i controls Player Shape Movement.

				break;
			}
		}

	}

	if (Key == ' ' && LaserReady > 3)        // In Case of Player Shooting Laser.
	{
		for (int x = 0; x < Width; x++)  // Loop for X Postion of Player As Y Postion is Fixed.
		{
			if (World[Height - 1][x] == Player && World[Height - 1][x + 1] == Player)     // Check Current Positon of Player.
			{
				World[Height - 2][x + 1] = PlayerLaser;     // Place Player Laser One Postion Above Current Position of Player.

				LaserReady = 0;              // Laser Ready set to 0 to Avoid Multiple Shooting by Player.

				Beep(500, 10);   // Shoot Sound. Part of the Time.h Library.

				break;
			}
		}
	}

	if (Key == 'q' || Key == 'Q')    // Manual Exit.
	{
		cls();   // Clear Screen.

		cout << "                           Manual Exit   ";       // Exit Message.

		GameContinue = 0;      // Game Ends.

	}
}

// Main Function.
int main()
{
	char Player = '=', PlayerLaser = '^', Enemy1 = 'a', Enemy2 = 's', Enemy3 = 'c', Enemy4 = 'o', Enemy5 = 'e', Enemy6 = 'z', Enemy7 = 'm', Enemy8 = 'n', Enemy9 = 'u', Enemy10 = 'r', EnemyLaser = '.', Key = NULL, direction = 'l';           // Local Variables Initialized.

	int Score = 0, LReady = 1, EReady = 0, EnemyCount = 10, Lives = 3, Height = 25, Width = 80, PlayerShapeControl = 0, LifeDecrease = 0, Difficulty = 0;

	double EnemyShapeControlY = 0, EnemyShapeControlX = 0;         // Enemy Shape Control Variable.

	int E1 = 1, E2 = 1, E3 = 1, E4 = 1, E5 = 1, E6 = 1, E7 = 1, E8 = 1, E9 = 1, E10 = 1;               // Enemy Alive|Dead Variables.

	SetConsoleTextAttribute(hConsole, 11);   // Sets Text Color to Light Blue (11).

	Welcome(Difficulty);                      // Welcome Message.

	showConsoleCursor(false);          // Remove Cursor.

	delay(1000);    // Wait 1000 milliseconds.

	cls();   // Clear Screen.

	fontsize(8, 12);  // Adjusting Font Size For Game.

	while (EnemyCount > 0 && GameContinue)        // Major Loop To Control Game, Terminates When Either All Enemies are Killed OR Player Lives (Controlled By Global Variable GameContinue) are 0.
	{
		int EnemyDrop = 0;    // Enemy Drop Control Variable.

		system("cls");  // Clear Screen.

		LReady = LReady + 1;        // Player Laser Shooting  Control Variable.

		DisplayWorld(Height, Width, Score, Lives);      // Display 2D World|Array.

		EnemyShapeDelete(E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, EnemyShapeControlX, EnemyShapeControlY);     // Enemy Shape Delete.

		ShapeInitialize(E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, PlayerShapeControl, EnemyShapeControlX, EnemyShapeControlY, Lives);  // Shapes Display.

		LaserControl(Player, PlayerLaser, Enemy1, Enemy2, Enemy3, Enemy4, Enemy5, Enemy6, Enemy7, Enemy8, Enemy9, Enemy10, EnemyLaser, Score, Lives, GameContinue, EnemyCount, EReady, LReady, Height, Width, E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, LifeDecrease, Difficulty);    // Laser Mechanics.

		EnemyMovement(Enemy1, Enemy2, Enemy3, Enemy4, Enemy5, Enemy6, Enemy7, Enemy8, Enemy9, Enemy10, direction, Height, Width, EnemyDrop, EnemyShapeControlX, EnemyShapeControlY); // Enemy Movement Mechanics.

		PlayerMovement(Player, PlayerLaser, Key, LReady, Height, Width, PlayerShapeControl, Lives);     // Player Movement Mechanics.

		delay(50);    // Wait 50 milliseconds.

	}

	delay(500);    // Wait 500 milliseconds.

	// Cleaning Borders.
	drawLine(4, 1, 4, 300, 0);      //Left Border.

	drawLine(628, 1, 628, 300, 0);   // Right Border.

	// Green Rectangles To Represent Lives.
	drawRectangle(525, 289, 545, 299, 0, 0, 0, 0, 0, 0);   // Cleaning Lives.

	drawRectangle(550, 289, 570, 299, 0, 0, 0, 0, 0, 0);

	drawRectangle(575, 289, 595, 299, 0, 0, 0, 0, 0, 0);
	
	system("cls");   // Clear Screen.

	cls();   // Clear Screen.

	fontsize(10, 18);   // Adjusting Font Size For Output Message Display.

	OutputMessage(Score, Lives, EnemyCount);   // Display Output Message.

	system("pause");   // Program Terminate.
}


