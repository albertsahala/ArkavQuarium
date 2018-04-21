//Dibuat Eka
#ifndef KOIN_H
#define KOIN_H

#include "Objek.h"

/* Kelas turunan dari objek untuk menggenerate koin */
class Koin : public Objek {
public :
	friend class Siput;

	// Definisi Jenis Koin
	enum CoinType { Bronze, Silver, Gold, Diamond1, Diamond2, Diamond3 };

	/* Konstruktor untuk menentukan posisi koin ketika pertama kali dibangkitkan*/
	Koin();
	Koin(CoinType _value, int _x, int _y);
	/* dtor untuk mengurangi nilai Number of Coin */
	~Koin();

	Koin& operator=(const Koin&);
	bool operator==(const Koin&);
	
	/* Method untuk mendapat nilai koin */
	CoinType getValue() const;

	/* Getter dan Setter untuk jumlah koin */
	static int getNumberOfCoin();
	string getImageFile() const;

	void addMoney(int *money);
	
private :
	CoinType value; 		// Bronze, Silver or Gold
	static int numberOfCoin;
};

#endif	
