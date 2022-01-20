#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#ifndef _SPACESHIP
#define _SPACESHIP

using namespace std;
class Spaceship
{
private:
	
	string shipName;
	string captainName;
	int shieldStrength;
	int numPhasers;
	int numPhotons;

public:

	Spaceship(string shipName, string captainName, int shieldStrength, int numPhasers, int numPhotons); 

	string getshipName();
	string getcaptianName();
	int getshieldStrength();
	int getnumPhasers();
	int getnumPhotons();

};//end class

#endif // !SPACESHIP
