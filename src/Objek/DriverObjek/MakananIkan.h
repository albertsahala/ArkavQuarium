//Dibuat Eka
#ifndef MAKANANIKAN_H
#define MAKANANIKAN_H

#include "Objek.h"

/* Kelas turunan dari objek untuk menggenerate makanan ikan */
class MakananIkan : public Objek {
public :
	friend class Guppy;
	/* Konstruktor untuk menentukan posisi makanan ikan ketika pertama kali dibangkitkan*/
	MakananIkan();
	MakananIkan(int _x, int _y);
	MakananIkan& operator=(const MakananIkan&);
	bool operator==(const MakananIkan&);

	/* Setter and Getter */
	int getIterasiGambar() const;
	void updateIterasiGambar();

private :
	int iterasiGambar;
};

#endif
