#include "Spaceship.h"
using namespace std;

//constructor
Spaceship::Spaceship(string mshipName, string mcaptainName, int mshieldStrength, int mnumPhasers, int mnumPhotons)
{
	shipName = mshipName;
	captainName = mcaptainName;
	shieldStrength = mshieldStrength;
	numPhasers = mnumPhasers;
	numPhotons = mnumPhotons;
}

	//accessor methods 
	string Spaceship::getshipName()
	{
		return Spaceship::shipName;
	}//end getShipName

	string Spaceship::getcaptianName()
	{
		return Spaceship::captainName;
	}//end getcaptianName

	int Spaceship::getshieldStrength()
	{
		return Spaceship::shieldStrength;
	}//end getshieldStrength

	int Spaceship::getnumPhasers()
	{
		return Spaceship::numPhasers;
	}//end getnumPhasers

	int Spaceship::getnumPhotons()
	{
		return Spaceship::numPhotons;
	}




