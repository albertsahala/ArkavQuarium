#include "Guppy.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <cmath>
using namespace std;

int Guppy::populationNumber = 0;

// Harga
int HARGA_GUPPY = 100;
// Atribut konstanta khusus Guppy
double CoinOut_Time_Guppy = 4; 
int FreeHungry_Time_Guppy = 5; 
int GetFood_Time_Guppy = 5; 

/* Konstruktor untuk menentukan posisi ikan ketika pertama kali dibangkitkan*/
Guppy::Guppy() : Ikan (0, 0, 0, "image/guppy") {
	populationNumber++;
	lastCoinDrop = CoinOut_Time_Guppy;
}

Guppy::Guppy(double _x, double _y) : Ikan (_x, _y, FreeHungry_Time_Guppy, "image/guppy") {
	populationNumber++;
	lastCoinDrop = CoinOut_Time_Guppy;
}

/* dtor untuk mengupdate jumlah Guppy yang hidup */
Guppy::~Guppy() {
	populationNumber--;
}

/* setter dan getter */
int Guppy::getPopulationNumber() {
	return populationNumber;
}

// behavior
void Guppy::Eat() {

}

bool Guppy::DropCoin(double sec_since_last) {
	if (lastCoinDrop - sec_since_last < 0) {
		lastCoinDrop = CoinOut_Time_Guppy;
		return true;
	}
	else {
		lastCoinDrop -= sec_since_last;
		return false;
	}
}

double Guppy::getLastCoinDrop() const{
	return lastCoinDrop;
}

void Guppy::setLastCoinDrop(double _lastCoinDrop){
	lastCoinDrop = _lastCoinDrop;
}

int Guppy::getHARGA_GUPPY() {
	return HARGA_GUPPY;
}
// Atribut konstanta khusus Guppy
int Guppy::getCoinOut_Time_Guppy() {
	return CoinOut_Time_Guppy;
} 

int Guppy::getFreeHungry_Time_Guppy() {
	return FreeHungry_Time_Guppy;
} 

int Guppy::getGetFood_Time_Guppy() {
	return GetFood_Time_Guppy;
} 

bool Guppy::operator==(const Guppy& a) {
	return (Akuarium::getPosX() == a.Akuarium::getPosX()) && (Akuarium::getPosY() == a.Akuarium::getPosY());
}

string Guppy::getImageFile() const {
	FishLevel level = this->getLevel();
    switch (level) {
        case BabyFish : return "image/guppy";
        case TeenFish : return "image/guppy1";
        default : return"image/guppy2";
    }
}
