#include <iostream>
#include "Spaceship.h"
#include <vector>
#include <sstream>
#include <string>

using namespace std;


void takeDamage(int damage, string shipName, int shieldStrength)
{
	//bap logic 
	shieldStrength = shieldStrength - damage;

	if (shieldStrength <= 0)
	{
		//prints out status attack of Pointer  
		cout << ">>> " << shipName << " was hit with attack of " << damage << endl;

		cout << "SHIP HAS BEEN DESTORYED." << endl << endl;

	}
	else
	{

		//prints out status attack of Pointer  
		cout << ">>> " << shipName << " was hit with attack of " << damage << endl;


		//prints updated status of the new shield strength of ship1 
		cout << "Sheilds are now at " << shieldStrength << " percent" << endl << endl; 
	}
}//end takeDamage

int main()
{
	srand((unsigned)time(NULL));
	string line;
	ifstream shipsFile("Ships.txt");
	char deliminator = ' '; 
	int i = 0;

	vector<Spaceship*>  ships; //create a vector of pointers to object names ships
	Spaceship* p = NULL; //initializes ptr to NULL


	//checks to see if ships.txt is open 
	// if file is opened continue to getline from ships.txt
	if (shipsFile.is_open())
	{

		//whill get run function below as long as there is a next line
		while (getline(shipsFile, line))
		{

			//splits out the string using the deliminater ' ' for each variable in object
			string shipName = line.substr(0, line.find(' '));
			line.erase(0, shipName.length() + 1);

			string captainName = line.substr(0, line.find(' '));
			line.erase(0, captainName.length() + 1);

			string shieldStrength = line.substr(0, line.find(' '));
			line.erase(0, shieldStrength.length() + 1);

			string numPhasers = line.substr(0, line.find(' '));
			line.erase(0, numPhasers.length() + 1);

			string numPhotons = line.substr(0, line.find(' '));
 			line.erase(0, numPhotons.length() + 1);


			//create new Spaceship object and store its pointer in the 'ships' pointer vector 
			//ships.push_back(new Spaceship(shipName, captainName, stoi(shieldStrength), stoi(numPhasers), stoi(numPhotons)));
			Spaceship* s = new Spaceship(shipName, captainName, stoi(shieldStrength), stoi(numPhasers), stoi(numPhotons));
			ships.push_back(s); 

		}//end while
		for (vector<Spaceship*>::iterator it = ships.begin(); it != ships.end(); ++it)
		{
			string name = (*it)->getshipName();
			string captain = (*it)->getcaptianName();
			int sstrength = (*it)->getshieldStrength();
			int phaser = (*it)->getnumPhasers();
			int photon = (*it)->getnumPhotons();

			//prints the ships basic information information 
			cout << " Starship " << name << " is captained by " << captain << "."
				<< " It has sheild strength of " << sstrength << ", " << phaser << " phasers, and "
				<< photon << " photon torpedoes." << endl;

			//generates a random number to bap a ship with
			int damage = 0;	
			damage = (rand() % 100) + 1;

			//runs takeDamage Function
			takeDamage(damage, name, sstrength);
			delete* it; //frees pointers 

		}//end iterator 



	shipsFile.close();
	}//end if

	//prints error if file cannot be fouund
	else
	{
		cout << "unable to open file.";
	}//end else
}//end main


