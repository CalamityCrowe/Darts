#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
	srand(time(0));

	
	
	
	Game CurrentGame(0);
	Player P1("Joe", 0, CurrentGame.chanceValue("Joe")); // name, darts thrown, chance of hitting bull
	Player P2("Sid", 0, CurrentGame.chanceValue("Sid"));

	CurrentGame.turnOrder(&P1, &P2, rand() % 100); // decides the turn order

	CurrentGame.Playing(&P1, &P2);

	
}


