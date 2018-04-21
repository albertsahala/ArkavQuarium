#include "Ikan.h"
#include "../oop.hpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14159265
#define TeenStandard 3
#define AdultStandard 6

// Implementasi file Ikan.h

int Ikan::fishPopulation = 0;
int slowSpeed = 50, fastSpeed = 100;


Ikan::Ikan() : Akuarium (100, 100), Interface ("image/ikan.png") {
}

/* Konstruktor untuk menentukan posisi ikan ketika pertama kali dibangkitkan*/
Ikan::Ikan(double _x, double _y, double nowTime) : Akuarium (_x, _y), Interface("image/ikan.png") {
	level = BabyFish;
	hunger = false;
	timeHungry = nowTime;
	fishPopulation++;
    moveDirection = 0;
    moveDuration = 0; 
    hasEaten = 0;
}

/* Konstruktor untuk menentukan posisi ikan ketika pertama kali dibangkitkan*/
Ikan::Ikan(double _x, double _y, double nowTime, string fileGambar) : Akuarium (_x, _y), Interface (fileGambar) {
	level = BabyFish;
	hunger = false;
	timeHungry = nowTime;
	fishPopulation++;
    moveDirection = 0;
    moveDuration = 0;
    hasEaten = 0;
}

/* Destruktor untuk memusnahkan ikan */
Ikan::~Ikan() {
	fishPopulation--;
}

/* Method untuk menentukan apakah ikan lapar atau tidak */
bool Ikan::getHunger() const {
	return hunger;
}

/* Method untuk mengeset apakah ikan lapar atau tidak */
void Ikan::setHunger(bool _hunger) {
	hunger = _hunger;
}

/* Method untuk pergerakan ikan */
void Ikan::Move(double sec_since_last) {
    if (moveDuration < 0) {
        moveDuration = ((double) (rand() % 1000))/(double) 200;
        moveDirection = ((double) (rand() % 360))/((double)180)* PI;
		if (cos(moveDirection) > 0) {
			Interface::setDirection(true);
		}
		else {
			Interface::setDirection(false);
		}
    }
    else {
        moveDuration -= sec_since_last; 
    }

	if (hunger) {
        double newPosX = Akuarium::getPosX() + fastSpeed*cos(moveDirection)*sec_since_last;
        double newPosY = Akuarium::getPosY() + fastSpeed*sin(moveDirection)*sec_since_last;

		if ((newPosX > 39) && (newPosX < SCREEN_WIDTH - 39) && (newPosY > 154) && (newPosY < SCREEN_HEIGHT - 80)) {
            Akuarium::setPosX(newPosX); 
            Akuarium::setPosY(newPosY);   
        }
        else {
            moveDuration = ((double) (rand() % 1000))/(double) 200;
            moveDirection = ((double) (rand() % 360))/((double)180)* PI;
            if (cos(moveDirection) > 0) {
				Interface::setDirection(true);
			}
			else {
				Interface::setDirection(false);
			}
        } 
	}
	else {
		double newPosX = Akuarium::getPosX() + slowSpeed*cos(moveDirection)*sec_since_last;
        double newPosY = Akuarium::getPosY() + slowSpeed*sin(moveDirection)*sec_since_last;

        if ((newPosX > 39) && (newPosX < SCREEN_WIDTH - 39) && (newPosY > 154) && (newPosY < SCREEN_HEIGHT - 80)) {
            Akuarium::setPosX(newPosX); 
            Akuarium::setPosY(newPosY);   
        }
        else {
            moveDuration = ((double) (rand() % 1000))/(double) 200;
            moveDirection = ((double) (rand() % 360))/((double)180)* PI;
            if (cos(moveDirection) > 0) {
				Interface::setDirection(true);
			}
			else {
				Interface::setDirection(false);
			}
        } 
	}
}

void Ikan::Move(double sec_since_last, double _x, double _y) {
	double y = Akuarium::getPosY(), x = Akuarium::getPosX();
	double arahKejar = atan2(_y-y, _x-x);
    double newPosX = x + fastSpeed*cos(arahKejar)*0.01;
    double newPosY = y + fastSpeed*sin(arahKejar)*0.01;

    if (cos(arahKejar) > 0) {
		Interface::setDirection(true);
	}
	else {
		Interface::setDirection(false);
	}

    setPosX(newPosX); 
    setPosY(newPosY);   
}

// setter and getter
Ikan::FishLevel Ikan::getLevel() const {
	return level;
}

void Ikan::setLevel(Ikan::FishLevel _level) {
	level = _level;
}

double Ikan::getTimeHungry() const {
	return timeHungry;
}

void Ikan::setTimeHungry(double _timeHungry) {
	timeHungry = _timeHungry;
}

int Ikan::getFishPopulation() {
	return fishPopulation;
}

double Ikan::getMoveDirection() const{
	return moveDirection;
}

void Ikan::setMoveDirection(double _moveDirection){
	moveDirection = _moveDirection;
}

double Ikan::getMoveDuration() const{
	return moveDuration;
}

void Ikan::setMoveDuration(double _moveDuration){
	moveDuration = _moveDuration;
}

/* Method yang tidak melakukan apapun */
void Ikan::Eat() {

}

/* Method yang tidak melakukan apapun */
bool Ikan::DropCoin(double sec_since_last) {
	return false;
}

// COPY THIS TO OBJECT AND SNAIL
/* Method untuk mengeset posisi dari objek dan ikan pada akuarium */
void Ikan::setPos(double _x, double _y){
    Akuarium::setPos(_x, _y);
}

/* Method untuk mengeset posisi dari objek dan ikan pada sumbu x */
void Ikan::setPosX(double _x){
    Akuarium::setPosX(_x);
}

/* Method untuk mengeset posisi dari objek dan ikan pada sumbu y */
void Ikan::setPosY(double _y){
    Akuarium::setPosY(_y);
}

/* Method untuk menentukan posisi dari objek dan ikan pada sumbu x */
double Ikan::getPosX() const{
    return Akuarium::getPosX();
}

/* Method untuk menentukan posisi dari objek dan ikan pada sumbu y */
double Ikan::getPosY() const{
    return Akuarium::getPosY();
}

// setter and getter
void Ikan::setDirection(bool b){
    Interface::setDirection(b);
}

bool Ikan::getDirection() const{
    return Interface::getDirection();
}

void Ikan::setImageFile(string _imageFile) {
    Interface::setImageFile(_imageFile);
}

string Ikan::getImageFile() const {
    return Interface::getImageFile();
}

// setter and getter
void Ikan::setHasEaten(int _y) {
	hasEaten = _y;
}

int Ikan::getHasEaten() const {
	return hasEaten;
}

void Ikan::updateLevel() {
	if (hasEaten > TeenStandard && hasEaten < AdultStandard) {
		level = TeenFish;
	}
	else if (hasEaten > AdultStandard) {
		level = AdultFish;
	}
}
