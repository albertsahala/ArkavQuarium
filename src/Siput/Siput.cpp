#include <iostream>
#include "Siput.h"
#include "../oop.hpp"
using namespace std;

#define SNAIL_SPEED 50

/* Konstruktor untuk menentukan posisi Siput ketika pertama kali dibangkitkan*/
Siput::Siput(double _x) : Akuarium(_x, SCREEN_HEIGHT-100), Interface("image/snail") {

}

/* Method untuk pergerakan siput */
void Siput::Move (bool arah, double sec_since_last) {
	double x = Akuarium::getPosX();
    double newPosX;
    if (arah) {
    	newPosX = x + SNAIL_SPEED*sec_since_last;
    }
    else {
    	newPosX = x - SNAIL_SPEED*sec_since_last;
    }

    Interface::setDirection(arah);
    Akuarium::setPosX(newPosX);
}

void Siput::Move(double sec_since_last) {

}

// COPY THIS TO OBJECT AND SNAIL
/* Method untuk mengeset posisi dari objek dan ikan pada akuarium */
void Siput::setPos(double _x, double _y){
    Akuarium::setPos(_x, _y);
}

/* Method untuk mengeset posisi dari objek dan Siput pada sumbu x */
void Siput::setPosX(double _x){
    Akuarium::setPosX(_x);
}

/* Method untuk mengeset posisi dari objek dan Siput pada sumbu y */
void Siput::setPosY(double _y){
    Akuarium::setPosY(_y);
}

/* Method untuk menentukan posisi dari objek dan Siput pada sumbu x */
double Siput::getPosX() const{
    return Akuarium::getPosX();
}

/* Method untuk menentukan posisi dari objek dan Siput pada sumbu y */
double Siput::getPosY() const{
    return Akuarium::getPosY();
}

// setter and getter
void Siput::setDirection(bool b){
    Interface::setDirection(b);
}

bool Siput::getDirection() const{
    return Interface::getDirection();
}

void Siput::setImageFile(string _imageFile) {
    Interface::setImageFile(_imageFile);
}

string Siput::getImageFile() const {
    return Interface::getImageFile();
}