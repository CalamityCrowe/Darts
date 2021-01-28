#pragma once
#include <iostream>
#include "Player.h"

using std::cout;
using std::cin;
using std::string;

class Game sealed
{
private:
	int GAMES;

	bool running = true;
	bool displayTurn = true;
	bool incrementTotal = true;
	int rounds, CurrentRound, turn;
	int totalGames;

	char Key;

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

	void Throw(Player* Current)
	{
		Current->setDarts(Current->getThrown() + 1);

		Current->setCount(Bull(Current->getChance()));
	}



protected:

public:
	Game(int V)
	{
		running = true;
		displayTurn = true;
		incrementTotal = true;
		Key = '_';

		rounds = V;
		CurrentRound = V;
		turn = V;

		GAMES = V + 1;

		totalGames = V;
	}

	//function for calling the playing of the game
	void Playing(Player* P1, Player* P2)
	{
		cout << "How many rounds should they play?\n\n";

		cin >> rounds;

		while (running)
		{
			while (CurrentRound < rounds)
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
						turn++;

						cout << "It is " << P1->getName() << "s Turn\n\n";

						cout << "Total Throws: " << P1->getTotal() << "\nBulls Hit: " << P1->getCount() << "\n\n";
					}
					else
					{
						for (int i = 0; i < 3; i++)
						{
							Throw(P2);
						}
						P2->setTurn(false);
						turn++;

						cout << "It is " << P2->getName() << "s Turn\n\n";

						cout << "Total Throws: " << P2->getTotal() << "\nBulls Hit: " << P2->getCount() << "\n\n";
					}
					displayTurn = false;
				}

				if (turn >= 2) //round increment
				{
					turn = 0;
					CurrentRound++; //increments the current round so it's not stuck in an endless loop
				}

			}
			if (P1->getCount() > P2->getCount())
			{
				if (incrementTotal)
				{
					incrementTotal = false;
					totalGames++;
					P1->setWon();
				}

				cout << "The player " << P1->getName() << " has won the game\n\n";

				cout << P1->getName() << " took " << P1->getTotal() << " to get " << P1->getCount() << " Bullseyes\n\n";

				cout << P2->getName() << " took " << P2->getTotal() << " to get " << P2->getCount() << " Bullseyes\n\n";

				cout << P1->getName() << " has won " << P1->getWon() << " out of " << totalGames<< " and has won approximatley " << (float)((float)P1->getWon()/ (float)totalGames) * 100 << "% of the games\n\n";
				cout << P2->getName() << " has won " << P2->getWon() << " out of " << totalGames << " and has won approximatley " << (float)((float)P2->getWon() / (float)totalGames) * 100 << "% of the games\n\n";

			}
			else if (P2->getCount() > P1->getCount())
			{
				if (incrementTotal)
				{
					incrementTotal = false;
					totalGames++;
					P2->setWon();
				}
				cout << "The player " << P2->getName() << " has won the game\n\n";

				cout << P1->getName() << " took " << P1->getTotal() << " to get " << P1->getCount() << " Bullseyes\n\n";

				cout << P2->getName() << " took " << P2->getTotal() << " to get " << P2->getCount() << " Bullseyes\n\n";

				cout << P1->getName() << " has won " << P1->getWon() << " out of " << totalGames << " and has won approximatley " << (float)((float)P1->getWon() / (float)totalGames) * 100 << "% of the games\n\n";
				cout << P2->getName() << " has won " << P2->getWon() << " out of " << totalGames << " and has won approximatley " << (float)((float)P2->getWon() / (float)totalGames) * 100 << "% of the games\n\n";
			}

			cout << "press r to reset the game or x to exit the game\n\n";

			cin >> Key;
			system("CLS");
			if (Key == 'r')
			{
				incrementTotal = true;
				P1->Reset( 0, ChanceValue(P1->getName()));// resets the players chance of hitting the bullseye along with other things
				P2->Reset( 0, ChanceValue(P2->getName()));

				cout << "How many rounds should they play?\n\n";
				cin >> rounds;

				CurrentRound = 0;

				Key = NULL;
			}
			if (Key == 'x')
			{
				exit(_CONSOLE);
			}

		}
	} 

	// allows the user to set what the chance 
	int ChanceValue(string N)
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
};
