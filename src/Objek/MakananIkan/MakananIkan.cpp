#include <iostream>
#include "MakananIkan.h"

/* Konstruktor untuk menentukan posisi makanan ikan ketika pertama kali dibangkitkan*/
MakananIkan::MakananIkan () {
	iterasiGambar = 1;
}

MakananIkan::MakananIkan(int _x, int _y) : Objek (_x, _y, "image/food") {
	iterasiGambar = 1;
}


/* Setter and Getter */
int MakananIkan::getIterasiGambar() const {
	return iterasiGambar;
}

void MakananIkan::updateIterasiGambar() {
	if (iterasiGambar == 3) {
		iterasiGambar = 1;
	}
	else {
		iterasiGambar++;
	}
}

MakananIkan& MakananIkan::operator=(const MakananIkan& k) {
	this->setPosX(k.getPosX());
	this->setPosY(k.getPosY());
	this->setImageFile(k.getImageFile());
	this->setDirection(k.getDirection());
	return *this;
}

bool MakananIkan::operator==(const MakananIkan& a) {
	return (Akuarium::getPosX() == a.Akuarium::getPosX()) && (Akuarium::getPosY() == a.Akuarium::getPosY());
}