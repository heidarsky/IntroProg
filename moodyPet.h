#pragma once
#include "Pet.h"

class moodyPet : public Pet {
public:
	moodyPet();
	moodyPet(string, int, int, int, int);
	void petFeed();
	void petPlay();
	void petTrain();
	void petSleep();
	void nextHour();
	void print();
};

moodyPet::moodyPet() : Pet() {

}

moodyPet::moodyPet(string userIn, int food, int love, int power, int sleep) : Pet(userIn, food, love, power, sleep) {

}

void moodyPet::petFeed() {
	setHunger(100);
	setEnergy(getEnergy() - 10);
	if (getEnergy() < 35) {
		setAffection(getAffection() - 5);
		checkValue();
		cout << getName() << " doesn't like being starved." << endl;
	}
	else {
		setAffection(getAffection() + 15);
		checkValue();
		cout << getName() << " is grateful for feeding in time." << endl;
	}
}
void moodyPet::petPlay() {
	if (getEnergy() < 50) {
		cout << getName() << " is not in mood for playing." << endl;
	}
	else {
		setHunger(getHunger() - 10);
		setAffection(getAffection() + 10);
		setEnergy(getEnergy() - 25);
		checkValue();
		cout << getName() << " is enjoying some quality time." << endl;
	}
}
void moodyPet::petTrain() {
	if (getStrength() > 100) {
		cout << getName() << " doesn't like unnecessary extra power." << endl;
	}
	else {
		setHunger(getHunger() - 30);
		setStrength(getStrength() + 10);
		setEnergy(getEnergy() - 20);
		checkValue();
		cout << getName() << " enjoys a good workout." << endl;
	}
}
void moodyPet::petSleep() {
	if (getEnergy() > 20) {
		cout << getName() << " still has energy left." << endl;
	}
	else {
		setHunger(getHunger() - 25);
		setEnergy(getEnergy() + 100);
		checkValue();
		cout << getName() << " is getting sleepy." << endl;
	}
}
void moodyPet::nextHour() {
	setHunger(getHunger() - 5);
	setEnergy(getEnergy() - 10);
	if (getHunger() < 20)
		cout << getName() << " may need a stack." << endl;
	if (getEnergy() < 60)
		cout << getName() << " is spending some energy today." << endl;
	checkValue();
}

void moodyPet::print() {
	cout << "Pet: " << getName() << endl;
	cout << "Status: [Hunger: " << getHunger() << "] | " << "[Affection: " << getAffection() << "] | " << "[Strength: " << getStrength() << "] | " << "[Energy: " << getEnergy() << "]" << endl;
}
