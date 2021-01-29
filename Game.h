#pragma once
#include <iostream>
#include <iomanip>
#include "Player.h"

using std::cout;
using std::cin;
using std::string;
using std::setprecision;

class Game sealed
{
private:

	//all these are private so they can't be accessed outside of the class

	int GAMES;

	bool Running;
	bool displayTurn;
	bool incrementTotal;
	int Rounds, currentRound, Turn;
	int totalGames;


	char Key;

	// functions in here can't be called outside of the class
	bool Bull(int Value)
	{
		if ((rand() % 100 + 1) <= Value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void displayStatsMessage(Player* P1, Player* P2)
	{
		cout << P1->getName() << " took " << P1->getTotalThrows() << " to get " << P1->getNumberOfBulls() << " Bullseyes\n\n";

		cout << P2->getName() << " took " << P2->getTotalThrows() << " to get " << P2->getNumberOfBulls() << " Bullseyes\n\n";

		cout << P1->getName() << " has won " << P1->getNumberOfWins() << " out of " << totalGames << " and has won approximatley " << setprecision(3) << (float)((float)P1->getNumberOfWins() / (float)totalGames) * 100 << "% of the games\n\n";
		cout << P2->getName() << " has won " << P2->getNumberOfWins() << " out of " << totalGames << " and has won approximatley " << setprecision(3) << (float)((float)P2->getNumberOfWins() / (float)totalGames) * 100 << "% of the games\n\n";
	}

	void Throw(Player* Current) // used for setting the current player darts thrown
	{
		Current->setDarts(Current->getThrown() + 1);

		Current->setCount(Bull(Current->getChanceOfBull()));
	}






protected: // not used the now but might use it later if something inherits off of this class

public:
	//initialies the variables
	Game(int V)
	{
		Running = true;
		displayTurn = true;
		incrementTotal = true;
		Key = '_';

		Rounds = V;
		currentRound = V;
		Turn = V;

		GAMES = V + 1;

		totalGames = V;
	}

	//function for calling the playing of the game
	void Playing(Player* P1, Player* P2)
	{
		cout << "How many rounds should they play?\n\n";

		cin >> Rounds;

		while (Running)
		{

#pragma region actually playing
			while (currentRound < Rounds)
			{
				displayTurn = true;
				if (P1->getThrown() >= 3) // swaps to the second player
				{
					P2->setTurn(true);
					P1->setDarts(0);
				}
				if (P2->getThrown() >= 3)// swaps to the first player
				{
					P1->setTurn(true);
					P2->setDarts(0);
				}
				while (displayTurn)
				{
					if (P1->getTurn() == true)
					{
						for (int i = 0; i < 3; i++)
						{
							Throw(P1);
						}
						P1->setTurn(false);
						Turn++;

						cout << "It is " << P1->getName() << "s Turn\n\n";

						cout << "Total Throws: " << P1->getTotalThrows() << "\nBulls Hit: " << P1->getNumberOfBulls() << "\n\n";
					}
					else
					{
						for (int i = 0; i < 3; i++)
						{
							Throw(P2);
						}
						P2->setTurn(false);
						Turn++;

						cout << "It is " << P2->getName() << "s Turn\n\n";

						cout << "Total Throws: " << P2->getTotalThrows() << "\nBulls Hit: " << P2->getNumberOfBulls() << "\n\n";
					}
					displayTurn = false;
				}

				if (Turn >= 2) //round increment
				{
					Turn = 0;
					currentRound++; //increments the current round so it's not stuck in an endless loop
				}

			}
#pragma endregion
#pragma region Display win

			/// <summary>
			///		
			///		this will do one of three things depending on the conditions
			/// 
			///		the first if statement will check if player one is the winner and will display their name in it
			/// 
			///		the second if statement will check if player two is the winner and will display their name in it
			/// 
			///		within both of these it will call the function displayStatsMessage() which displays the number of bulls, number of wins and the percentage of wins
			/// 
			///		the third statement will display that it was a draw and won't increment the win counter of either player but will still increment the totalGames counter
			/// 
			/// </summary>


			if (P1->getNumberOfBulls() > P2->getNumberOfBulls())
			{
				if (incrementTotal)
				{
					incrementTotal = false;
					totalGames++;
					P1->setWon();
				}

				cout << "The player " << P1->getName() << " has won the game\n\n";

				displayStatsMessage(P1, P2);

			}
			else if (P2->getNumberOfBulls() > P1->getNumberOfBulls())
			{
				if (incrementTotal)
				{
					incrementTotal = false;
					totalGames++;
					P2->setWon();
				}
				cout << "The player " << P2->getName() << " has won the game\n\n";

				displayStatsMessage(P1, P2);

			}
			else
			{
				if (incrementTotal)
				{
					incrementTotal = false;
					totalGames++;
				}
				cout << "The players scored the exact same which has resulted in a draw. no winner for this round\n\n";
			}
#pragma endregion
#pragma region reset/exitgame
			cout << "press r to reset the game or x to exit the game\n\n";

			cin >> Key;
			system("CLS");
			if (Key == 'r')
			{
				incrementTotal = true;
				P1->Reset(0, chanceValue(P1->getName()));// resets the players chance of hitting the bullseye along with other things
				P2->Reset(0, chanceValue(P2->getName()));

				cout << "How many rounds should they play?\n\n";
				cin >> Rounds;

				startFirst(P1, P2);

				currentRound = 0; // resets the current round

				Key = NULL; // clears the key pressed
			}
			if (Key == 'x')
			{
				exit(_CONSOLE); // exits the console
			}
#pragma endregion

		}
	}

	void startFirst(Player* P1, Player* P2)
	{
		cout << "Who should start first?\n\n j = joe        s = sid\n\n";

		cin >> Key;
		if (Key == 'j') // sets who starts the game and if the relevant key isn't pressed it will randomise it instead
		{
			P1->setTurn(true);
			P2->setTurn(false);
		}
		else if (Key == 's')
		{
			P1->setTurn(false);
			P2->setTurn(true);
		}
		else
		{
			turnOrder(P1, P2, rand() % 100);
		}
	}


	// allows the user to set what the chance of hitting a bull is
	int chanceValue(string N)
	{
		int CC;
		cout << "Enter " << N << " chance of hitting a bull\n";
		cin >> CC;
		if (CC > 100)
		{
			CC = 100;
		}
		else if (CC < 0)
		{
			CC = 0;
		}
		return CC;
	}

	//randomly decides the order if it's called
	void turnOrder(Player* P1, Player* P2, int Ord)
	{
		if (Ord % 2 == 1)// randomly selects who will go first based on the remainder
		{
			P1->setStart(true);
			P2->setStart(false);
			cout << "The Player " << P1->getName() << " Shall Start \n\n";
		}
		else
		{
			P1->setStart(false);
			P2->setStart(true);
			cout << "The Player " << P2->getName() << " Shall Start\n\n";
		}
	}

	void simulateMultipleGames(Player* P1, Player* P2)
	{
		int numberOfGames = 0;
		int currentGame = 0;

		cout << "How many games shall be simulated?";

		cin >> numberOfGames;

		P1->completeReset(0, chanceValue(P1->getName()));// resets the players chance of hitting the bullseye along with the number of wins
		P2->completeReset(0, chanceValue(P2->getName()));
		
		startFirst(P1, P2);

		while(currentGame < numberOfGames)
		{
			if(P1->getTurn() == true)
			{
			
			}
			else
			{
				
			}
		}

	}
};
