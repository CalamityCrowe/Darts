#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
	srand(time(0));

	void TurnOrder(Player*, Player*, int);
	
	
	Game CurrentGame(0);
	Player P1("Joe", 0, CurrentGame.ChanceValue("Joe")); // name, darts thrown, chance of hitting bull
	Player P2("Sid", 0, CurrentGame.ChanceValue("Sid"));

	TurnOrder(&P1, &P2, rand() % 100); // decides the turn order

	CurrentGame.Playing(&P1, &P2);

	
}


void TurnOrder(Player* P1, Player* P2, int Ord)
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
