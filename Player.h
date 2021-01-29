
#include <iostream>
#include <ctime>

using std::cout;
using std::cin;
using std::string;

class Player sealed
{
private:
	//all these are private so they can't be accessed outside of the class
	string Name;
	int dartsThrown,Count,Chance,totalCount,Won;
	bool isTurn = false; bool Start = false; bool isWinner = false;
	

protected:// although not used yet this is more for if inheritance is used down the line

public:
	//initialises the class
	Player(string N,int D,int C)
	{
		Name = N;
		dartsThrown = D;
		Chance = C;
		Count = 0;
		totalCount = 0;
		Won = 0;
	}


	#pragma region Access modifiers: Get functions
	
	string getName()
	{
		return Name;
	}
	int getChanceOfBull()
	{
		return Chance;
	}
	int getNumberOfBulls()
	{
		return Count;
	}
	int getThrown() // used in a if statement to swap the players turns
	{
		return dartsThrown;
	}
	int getTotalThrows()
	{
		return totalCount;
	}
	int getNumberOfWins()
	{
		return Won;
	}
	bool getTurn()
	{
		return isTurn;
	}
#pragma endregion

	#pragma region Access modifiers: Set functions
	
	void setCount(bool T)// increments the count based on the value passed and increments the totalCount
	{
		if(T)
		{
			Count++;
		}
		totalCount++;
	}
	void setDarts(int D) // sets how many darts have been thrown
	{
		dartsThrown = D;
	}
	void setStart(bool B) // sets the turn based on the value passed
	{
		isTurn = B;
		Start = B;
	}
	void setTurn(bool T) // sets the turn based on the value passed
	{
		isTurn = T; 
	}
	void setWon()
	{
		Won++;
	}
#pragma endregion


	//reset the player without having to create a new instance
	void Reset(int D,int C)
	{
		dartsThrown = D;
		Chance = C;
		Count = D;
		totalCount = D;
	}
	void completeReset(int D,int C)
	{
		dartsThrown = D;
		Chance = C;
		Count = D;
		totalCount = D;
		Won = D;
	}

};

