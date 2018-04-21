#include "../Objek.h"
#include "../../Siput/Siput.h"
#include "Koin.h"
#include <iostream>

int Koin::numberOfCoin = 0;

Koin::Koin () : value (Bronze){

}

Koin::Koin(Koin::CoinType _value, int _x, int _y) : Objek (_x, _y, "image/coin"), value (_value) {
	numberOfCoin++;
}

/* dtor untuk mengurangi nilai Number of Coin */
Koin::~Koin() {
	numberOfCoin--;
}

Koin& Koin::operator=(const Koin& k) {
	this->setPosX(k.getPosX());
	this->setPosY(k.getPosY());
	this->setImageFile(k.getImageFile());
	this->setDirection(k.getDirection());
	value = k.value;
	return *this;
}

bool Koin::operator==(const Koin& a) {
	return (Akuarium::getPosX() == a.Akuarium::getPosX()) && (Akuarium::getPosY() == a.Akuarium::getPosY());
}

/* Method untuk mendapat nilai koin */
Koin::CoinType Koin::getValue() const {
	return value;
}

/* Getter dan Setter untuk jumlah koin */
int Koin::getNumberOfCoin(){
	return numberOfCoin;
}

string Koin::getImageFile() const {
	CoinType _value = this->getValue();
    switch (_value) {
        case Bronze : return "image/coin3";
        case Silver : return "image/coin2";
        case Gold : return "image/coin1";
        case Diamond1 : return "image/diamond3";
        case Diamond2 : return "image/diamond2";
        default : return"image/diamond1";
    }
}

void Koin::addMoney(int *money) {
	CoinType _value = this->getValue();
	switch (_value) {
        case Bronze : *money += 10; break;
        case Silver : *money += 20; break;
        case Gold : *money += 40; break;
        case Diamond1 : *money += 100; break;
        case Diamond2 : *money += 200; break;
        default : *money += 300; break;
    }
}
