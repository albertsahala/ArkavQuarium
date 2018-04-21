//Dibuat Hagai

#ifndef GUPPY_H
#define GUPPY_H

#include "../Ikan.h"
#include "../Piranha/Piranha.h"


/* Kelas turunan dari ikan untuk menggenerate piranha */
class Guppy : public Ikan
{
public:
	// agar kelas piranha dapat melihat populationNumber Guppy dsb
	friend class Piranha;

	// ctor
	/* Konstruktor untuk menentukan posisi guppy ketika pertama kali dibangkitkan*/
	Guppy();
	Guppy(double _x, double _y);
	/* dtor untuk mengupdate jumlah Guppy yang hidup */
	~Guppy();

	bool operator==(const Guppy&);
	
	/* setter dan getter */
	static int getPopulationNumber();
	double getLastCoinDrop() const;
	void setLastCoinDrop(double);
	// Harga
	static int getHARGA_GUPPY();
	// Atribut konstanta khusus Guppy
	static int getCoinOut_Time_Guppy(); 
	static int getFreeHungry_Time_Guppy(); 
	static int getGetFood_Time_Guppy(); 
	string getImageFile() const;

	// behavior
	void Eat();
	bool DropCoin(double);

private:
	static int populationNumber;
	// Time since the last coin dropped
	double lastCoinDrop;
};

#endif
