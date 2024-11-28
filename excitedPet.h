#pragma once
#include "Pet.h"

class excitedPet : public Pet {
public:
	excitedPet();
	excitedPet(string, int, int, int, int);
	void petFeed();
	void petPlay();
	void petTrain();
	void petSleep();
	void nextHour();
	void print();
};

excitedPet::excitedPet() : Pet() {

}

excitedPet::excitedPet(string userIn, int food, int love, int power, int sleep) : Pet(userIn, food, love, power, sleep) {

}

void excitedPet::petFeed() {
	setHunger(100);
	setAffection(getAffection() + 10);
	setEnergy(getEnergy() - 5);
	checkValue();
	cout << getName() << " is loving this food!" << endl;
}
void excitedPet::petPlay() {
	setHunger(getHunger() - 5);
	setAffection(getAffection() + 20);
	setEnergy(getEnergy() - 15);
	checkValue();
	cout << getName() << " is having a wonderful time!" << endl;
}
void excitedPet::petTrain() {
	setHunger(getHunger() - 20);
	setStrength(getStrength() + 25);
	setEnergy(getEnergy() - 35);
	cout << getName() << " is hyped to get strong!" << endl;
	if (getStrength() > 200)
		cout << getName() << " is getting a little too excited.." << endl;
	checkValue();
}
void excitedPet::petSleep() {
	setHunger(getHunger() - 40);
	setEnergy(getEnergy() + 100);
	checkValue();
	cout << getName() << " is excited to wake up early!" << endl;
}
void excitedPet::nextHour() {
	setHunger(getHunger() - 60);
	setEnergy(getEnergy() - 55);
	if (getHunger() < 30)
		cout << getName() << " is losing track of time (and food!)" << endl;
	if (getEnergy() < 50)
		cout << getName() << " should not be going overboard, a rest would be best!" << endl;
	checkValue();
}

void excitedPet::print() {
	cout << "Pet: " << getName() << endl;
	cout << "Status: [Hunger: " << getHunger() << "] | " << "[Affection: " << getAffection() << "] | " << "[Strength: " << getStrength() << "] | " << "[Energy: " << getEnergy() << "]" << endl;
}
