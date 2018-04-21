//Dibuat Hagai

#ifndef PIRANHA_H
#define PIRANHA_H

#include "../Ikan.h"
#include "../Guppy/Guppy.h"

/* Kelas turunan dari ikan untuk menggenerate piranha */
class Piranha : public Ikan
{
public:

	/* Konstruktor untuk menentukan posisi piranha ketika pertama kali dibangkitkan*/
	Piranha();
	Piranha(int _x, int _y);
	bool operator==(const Piranha&);

	static int getHARGA_PIRANHA();
	// Atribut konstanta khusus Piranha
	static int getFreeHungry_Time_Piranha(); 
	static int getGetFood_Time_Piranha(); 
	
	/* Method untuk ikan memakan makanan ikan */
	void Eat();
	
	/* Method untuk menjatuhkan koin */
	bool DropCoin(double);

};

#endif
