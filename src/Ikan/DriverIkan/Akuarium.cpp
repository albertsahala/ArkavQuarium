#include "Akuarium.h"
#include <iostream>

// ctor
Akuarium::Akuarium(double _x, double _y){
	x = _x;
	y = _y;
}
/*
	Untuk empat sekawan lainnya dianggap tidak perlu
	karena class ini hanya memiliki atribut double
	dan dari spek game dapat dilihat hal ini
	tidak dibutuhkan
*/

/* Method untuk mengeset posisi dari objek dan ikan pada akuarium */
void Akuarium::setPos(double _x, double _y){
	x = _x;
	y = _y;
}

/* Method untuk mengeset posisi dari objek dan ikan pada sumbu x */
void Akuarium::setPosX(double _x){
	x = _x;
}

/* Method untuk mengeset posisi dari objek dan ikan pada sumbu y */
void Akuarium::setPosY(double _y){
	y = _y;
}

/* Method untuk menentukan posisi dari objek dan ikan pada sumbu x */
double Akuarium::getPosX() const{
	return x;
}

/* Method untuk menentukan posisi dari objek dan ikan pada sumbu y */
double Akuarium::getPosY() const{
	return y;
}

