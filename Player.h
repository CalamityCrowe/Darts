
#include <iostream>
#include <ctime>

using std::cout;
using std::cin;
using std::string;

class Player sealed
{
private:
	//all these are private so they can't be accessed outside of the object
	string Name;
	int Darts_Thrown,Count,Chance,totalCount,Won;
	bool isTurn = false; bool start = false; bool isWinner = false;
	

protected:// although not used yet this is more for if inheritance is used down the line

public:
	//initialises the class
	Player(string N,int D,int C)
	{
		Name = N;
		Darts_Thrown = D;
		Chance = C;
		Count = 0;
		totalCount = 0;
		Won = 0;
	}


	//access modifiers : Get functions
	string getName()
	{
		return Name;
	}
	int getChance()
	{
		return Chance;
	}
	int getCount()
	{
		return Count;
	}
	int getThrown()
	{
		return Darts_Thrown;
	}
	int getTotal()
	{
		return totalCount;
	}
	int getWon()
	{
		return Won;
	}
	bool getTurn()
	{
		return isTurn;
	}


	//access modifiers : Set Functions
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
		Darts_Thrown = D;
	}
	void setStart(bool B) // sets the turn based on the value passed
	{
		isTurn = B;
		start = B;
	}
	void setTurn(bool T) // sets the turn based on the value passed
	{
		isTurn = T; 
	}
	void setWon()
	{
		Won++;
	}



	//reset the player without having to create a new instance
	void Reset(int D,int C)
	{
		Darts_Thrown = D;
		Chance = C;
		Count = 0;
		totalCount = 0;
	}

};

