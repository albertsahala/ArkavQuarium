#include "Piranha.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <cmath>
using namespace std;

// Harga
int HARGA_PIRANHA = 1000;
// Atribut konstanta khusus Piranha
int CoinOut_Time_Piranha = 5; 
int FreeHungry_Time_Piranha = 7; 
int GetFood_Time_Piranha = 7; 

/* Konstruktor untuk menentukan posisi ikan ketika pertama kali dibangkitkan*/
Piranha::Piranha() : Ikan (0, 0, 0, "piranha") {
}

Piranha::Piranha(int _x, int _y) : Ikan (_x, _y, FreeHungry_Time_Piranha, "piranha") {
}

// behavior
void Piranha::Eat() {

}

bool Piranha::DropCoin(double sec_since_last) {
	return false;
}

int Piranha::getHARGA_PIRANHA() {
	return HARGA_PIRANHA;
}
// Atribut konstanta khusus Piranha
int Piranha::getCoinOut_Time_Piranha() {
	return CoinOut_Time_Piranha;
} 

int Piranha::getFreeHungry_Time_Piranha() {
	return FreeHungry_Time_Piranha;
} 

int Piranha::getGetFood_Time_Piranha() {
	return GetFood_Time_Piranha;
}

bool Piranha::operator==(const Piranha& a) {
	return (Akuarium::getPosX() == a.Akuarium::getPosX()) && (Akuarium::getPosY() == a.Akuarium::getPosY());
}