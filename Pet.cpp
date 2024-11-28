#include "Pet.h"
#include "sleepyPet.h"
#include "excitedPet.h"
#include "moodyPet.h"
#include <iostream>
#include <fstream>


void printMen() {
	cout << "-> Select from the following actions below to interact with your pet: " << endl;
	cout << " 1 - Feed " << endl;
	cout << " 2 - Play " << endl;
	cout << " 3 - Train " << endl;
	cout << " 4 - Sleep " << endl;
	cout << " 5 - Time skip (1 hour) " << endl;
	cout << " NOTE: entering any other number will stop the game." << endl;
	cout << " ----------------------- " << endl;
}

template<typename TheType>
TheType setter(TheType userPet, string name, int hung, int love, int str, int slp) {
	userPet.setName(name); userPet.setHunger(hung); userPet.setAffection(love); userPet.setStrength(str); userPet.setEnergy(slp);
	return userPet;
}

template<typename TheType>
TheType printFunctions(TheType userPet) {
	TheType editedPet;
	int userAction = 0;
	while (userAction <= 5) {
		printMen();
		cin >> userAction;
		switch (userAction) {
		case 1:
			userPet.petFeed();
			break;
		case 2:
			userPet.petPlay();
			break;
		case 3:
			userPet.petTrain();
			break;
		case 4:
			userPet.petSleep();
			break;
		case 5:
			userPet.nextHour();
			break;
		default:
			cout << "-> Interactions saved." << endl;
			break;
		}
	}
	editedPet = setter(userPet, userPet.getName(), userPet.getHunger(), userPet.getAffection(), userPet.getStrength(), userPet.getEnergy());
	return editedPet;
}

int main() {
	int userIn = 0;
	while (userIn != 3) {
			cout << "----------------------" << endl;
			cout << "Welcome to Tamagotchi!" << endl;
			cout << "     | MAIN MENU |      " << endl;
			cout << " 1 - New Pet " << endl;
			cout << " 2 - Load Pet " << endl;
			cout << " 3 - Exit Game " << endl;
			cout << "----------------------" << endl;
			cout << "     O           O    " << endl;
			cout << "    ---    ^    ---   " << endl;
			cout << "     HHHHHHHHHHHHH    " << endl;
			cout << "----------------------" << endl;
			cout << "-> Enter your choice: " << endl;
			cout << endl;

			cin >> userIn;
			if (cin.fail()) {
				cout << "-> Error: INVALID INPUT." << endl;
				break;
			}
			else {
				// --------------------- EXIT ---------------------
				if (userIn == 3)
					cout << "-> Thank you for playing! " << endl;

				// -------------------- CREATE --------------------
				else if (userIn == 1) { // CREATE PET
					ofstream fout("createdPet.txt");

					string petName;
					cout << "-> Choose a name for your pet: " << endl;
					cin >> petName;

					int userChoice = 0;
					cout << "-> Choose the pet personality ( 1 - Sleepy | 2 - Excited | 3 - Moody )" << endl;
					cin >> userChoice;

					if (userChoice == 1) { // SLEEPY
						sleepyPet userPet; 
						userPet = setter(userPet, petName, 100, 20, 50, 90);
						userPet = printFunctions(userPet);
						fout << "1 " << userPet.getName() << " " << userPet.getHunger() << " " << userPet.getAffection() << " " << userPet.getStrength() << " " << userPet.getEnergy();
						userPet.print();
					}
					else if (userChoice == 2) { // EXCITED
						excitedPet userPet; 
						userPet = setter(userPet, petName, 100, 50, 35, 100);
						userPet = printFunctions(userPet);
						fout << "2 " << userPet.getName() << " " << userPet.getHunger() << " " << userPet.getAffection() << " " << userPet.getStrength() << " " << userPet.getEnergy();
						userPet.print();
					}
					else if (userChoice == 3) { // MOODY
						moodyPet userPet; 
						userPet = setter(userPet, petName, 100, 40, 20, 50);
						userPet = printFunctions(userPet);
						fout << "3 " << userPet.getName() << " " << userPet.getHunger() << " " << userPet.getAffection() << " " << userPet.getStrength() << " " << userPet.getEnergy();
						userPet.print();
					}
					else {
						cout << "->>> Invalid choice. Restarting. <<<-" << endl;
					}

					fout.close();
				}

				// ------------------- LOAD ----------------------
				else if (userIn == 2) { // LOAD PET
					string nameRead = "";
					int petType, hungerRead, affectionRead, strengthRead, energyRead = 0;

					string filename;
					cin >> filename;
					ifstream fin(filename);
					if (!fin.is_open()) {
						cout << "-> File not found!" << endl;
					}
					else { // if file is open, read values
						ofstream fout("loadedPetSave.txt");

						while (!fin.eof()) {
							fin >> petType;
							fin >> nameRead;
							fin >> hungerRead;
							fin >> affectionRead;
							fin >> strengthRead;
							fin >> energyRead;
						}
						
						if (petType == 1) {
							sleepyPet userPet; 
							userPet = setter(userPet, nameRead, hungerRead, affectionRead, strengthRead, energyRead);
							userPet.print();
							userPet = printFunctions(userPet);
							fout << petType << " " << userPet.getName() << " " << userPet.getHunger() << " " << userPet.getAffection() << " " << userPet.getStrength() << " " << userPet.getEnergy();
							userPet.print();
						}
						if (petType == 2) {
							excitedPet userPet; 
							userPet = setter(userPet, nameRead, hungerRead, affectionRead, strengthRead, energyRead);
							userPet.print();
							userPet = printFunctions(userPet);
							fout << petType << " " << userPet.getName() << " " << userPet.getHunger() << " " << userPet.getAffection() << " " << userPet.getStrength() << " " << userPet.getEnergy();
							userPet.print();
						}
						if (petType == 3) {
							moodyPet userPet; 
							userPet = setter(userPet, nameRead, hungerRead, affectionRead, strengthRead, energyRead);
							userPet.print();
							userPet = printFunctions(userPet);
							fout << petType << " " << userPet.getName() << " " << userPet.getHunger() << " " << userPet.getAffection() << " " << userPet.getStrength() << " " << userPet.getEnergy();
							userPet.print();
						}
						fout.close();
					}
					fin.close();
				}
				else {
					cout << "-> Please make a valid selection." << endl;
				}
			}
		}
	
	cout << "-> Good bye! " << endl;
	return 0;
}
