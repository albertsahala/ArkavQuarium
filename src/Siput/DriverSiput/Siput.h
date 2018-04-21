//Dibuat Tanor
#ifndef SIPUT_H
#define SIPUT_H

#include "Akuarium.h"
#include "Interface.h"

/* Kelas turunan dari akuarium untuk menggenerate siput */
class Siput : public Akuarium, Interface {

public :
	/* Konstruktor untuk menentukan posisi Siput ketika pertama kali dibangkitkan*/
	Siput(double _x);
	
	/* Method untuk pergerakan siput */
	void Move(double sec_since_last);
	void Move(bool, double sec_since_last);

	// setter and getter interface
	void setDirection(bool);
	bool getDirection() const;
	void setImageFile(string);
	string getImageFile() const;

	/* Method untuk mengeset posisi dari objek dan ikan pada akuarium */
	void setPos(double _x, double _y);
	
	/* Method untuk mengeset posisi dari objek dan ikan pada sumbu x */
	void setPosX(double _x);
	
	/* Method untuk mengeset posisi dari objek dan ikan pada sumbu y */
	void setPosY(double _y);
	
	/* Method untuk menentukan posisi dari objek dan ikan pada sumbu x */
	double getPosX() const;
	
	/* Method untuk menentukan posisi dari objek dan ikan pada sumbu y */
	double getPosY() const;
};

#endif
