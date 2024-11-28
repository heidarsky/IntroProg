#pragma once

#ifndef PET_H
#define PET_H

#include <string>
#include <iostream>
using namespace std;

class Pet {
public:
	Pet();
	Pet(string, int, int, int, int);
	string getName();
	int getHunger();
	int getAffection();
	int getStrength();
	int getEnergy();
	void setName(string);
	void setHunger(int);
	void setAffection(int);
	void setStrength(int);
	void setEnergy(int);
	void print();

	void petFeed();
	void petPlay();
	void petTrain();
	void petSleep();
	void nextHour();

	void checkValue();

private:
	string name;
	int hunger;
	int affection;
	int strength;
	int energy;
};

Pet::Pet() {
	name = "";
	hunger, affection, strength, energy = 0;
}
Pet::Pet(string userIn, int food, int love, int power, int sleep) {
	name = userIn;
	hunger = food;
	affection = love;
	strength = power;
	energy = sleep;
}
string Pet::getName() {return name;}
int Pet::getHunger() { return hunger; }
int Pet::getAffection() { return affection; }
int Pet::getStrength() { return strength; }
int Pet::getEnergy() { return energy; }

void Pet::setName(string userIn) {name = userIn;}
void Pet::setHunger(int userIn) { hunger = userIn; }
void Pet::setAffection(int userIn) { affection = userIn; }
void Pet::setStrength(int userIn) { strength = userIn; }
void Pet::setEnergy(int userIn) { energy = userIn; }

void Pet::checkValue() {
	if (hunger > 100)
		hunger = 100;
	if (hunger < 0)
		hunger = 0;
	if (affection > 200)
		affection = 200;
	if (affection < 0)
		affection = 0;
	if (strength > 300)
		strength = 300;
	if (strength < 0)
		strength = 0;
	if (energy > 100)
		energy = 100;
	if (energy < 0)
		energy = 0;
}

void Pet::petFeed() {
	setHunger(100);
	setAffection(affection+2);
	setEnergy(energy-3);
	checkValue();
	cout << name << " grows satisfied!" << endl;
}
void Pet::petPlay() {
	setHunger(hunger-10);
	setAffection(affection+10);
	setEnergy(energy-5);
	checkValue();
	cout << name << " seems to enjoy your presence!" << endl;
}
void Pet::petTrain() {
	setHunger(hunger - 30);
	setAffection(affection + 1);
	setStrength(strength+25);
	setEnergy(energy - 50);
	cout << name << " is ready to protect!!" << endl;
	if (strength > 200)
		cout << name << " may be getting a little too powerful!" << endl;
	checkValue();
}
void Pet::petSleep() {
	setHunger(hunger - 50);
	setEnergy(energy + 100);
	checkValue();
	cout << name << " loves a good rest." << endl;
}
void Pet::nextHour() {
	setHunger(hunger - 10);
	setEnergy(energy - 8);
	if (hunger < 30)
		cout << name << " may be getting hungry!" << endl;
	if (energy < 50)
		cout << name << " it might be time to rest." << endl;
	checkValue();
}

void Pet::print() {
	cout << "Pet: " << name << endl;
	cout << "Status: [Hunger: " << hunger << "] | " << "[Affection: " << affection << "] | " << "[Strength: " << strength << "] | " << "[Energy: " << energy << "]" << endl;
}


#endif 
