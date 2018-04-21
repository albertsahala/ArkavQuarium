#ifndef OBJEK_H
#define OBJEK_H

#include "Akuarium.h"
#include "Interface.h"

/* Kelas turunan dari akuarium untuk menggenerate Objek yang kemudian menurunkan kelas MakananIkan dan Koin */
class Objek : public Akuarium , public Interface {
public :
	/* Konstruktor untuk menentukan posisi Objek ketika pertama kali dibangkitkan*/
	Objek();
	Objek(double _x, double _y);
	Objek(double _x, double _y, string imageFile);
	
	/* Method untuk pergerakan objek */
	void Move(double sec_since_last);

	void setTimeAtBottom (double);
	double getTimeAtBottom () const;

	bool remove();

private :
	// Menyimpan Waktu Objek di dasar
	double timeAtBottom;
	
};


#endif