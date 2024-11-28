#pragma once
#include "Pet.h"

class sleepyPet : public Pet {
public:
	sleepyPet();
	sleepyPet(string, int, int, int, int);
	void petFeed();
	void petPlay();
	void petTrain();
	void petSleep();
	void nextHour();
	void print();
};

sleepyPet::sleepyPet() : Pet() {

}

sleepyPet::sleepyPet(string userIn, int food, int love, int power, int sleep) : Pet(userIn, food, love, power, sleep) {

}

void sleepyPet::petFeed() {
	setHunger(100);
	setAffection(getAffection() + 2);
	setEnergy(getEnergy() - 25);
	checkValue();
	cout << getName() << " grows satisfied (and sleepy!!)" << endl;
}
void sleepyPet::petPlay() {
	setHunger(getHunger() - 10);
	setAffection(getAffection() + 10);
	setEnergy(getEnergy() - 50);
	checkValue();
	cout << getName() << " is getting real tired." << endl;
}
void sleepyPet::petTrain() {
	setHunger(getHunger() - 40);
	setStrength(getStrength() + 10);
	setEnergy(getEnergy() - 75);
	cout << getName() << " is not so fond of training..." << endl;
	if (getStrength() > 200)
		cout << getName() << " will definitely get sleepy soon" << endl;
	checkValue();
}
void sleepyPet::petSleep() {
	setHunger(getHunger() - 100);
	setEnergy(getEnergy() + 200);
	checkValue();
	cout << getName() << " sleeps like a newborn" << endl;
}
void sleepyPet::nextHour() {
	setHunger(getHunger() - 10);
	setEnergy(getEnergy() - 25);
	if (getHunger() < 30)
		cout << getName() << " prefers to eat before sleeping" << endl;
	if (getEnergy() < 50)
		cout << getName() << " must go sleep immediately" << endl;
	checkValue();
}

void sleepyPet::print() {
	cout << "Pet: " << getName() << endl;
	cout << "Status: [Hunger: " << getHunger() << "] | " << "[Affection: " << getAffection() << "] | " << "[Strength: " << getStrength() << "] | " << "[Energy: " << getEnergy() << "]" << endl;
}
