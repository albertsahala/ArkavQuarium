#ifndef IKAN_H
#define IKAN_H

#include "Akuarium.h"
#include "Interface.h"
#include <string>

/* Kelas turunan dari akuarium untuk menggenerate ikan */
class Ikan : public Akuarium, Interface
{
public:
	// Definisi Level Ikan
	enum FishLevel {
		BabyFish, TeenFish, AdultFish
	};

	/* Konstruktor untuk menentukan posisi ikan ketika pertama kali dibangkitkan*/
	Ikan();
	Ikan(double _x, double _y, double nowTime);
	Ikan(double _x, double _y, double nowTime, string fileGambar);
	
	/* Destruktor untuk memusnahkan ikan */
	~Ikan();
	/* Method untuk menentukan apakah ikan lapar atau tidak */
	bool getHunger() const;
	
	/* Method untuk mengeset apakah ikan lapar atau tidak */
	void setHunger(bool);

	/* Method untuk pergerakan ikan */
	void Move(double sec_since_last);
	void Move(double sec_since_last, double _x, double _y);

	// setter and getter
	FishLevel getLevel() const;
	void setLevel(FishLevel);
	double getTimeHungry() const;
	void setTimeHungry(double);
	double getMoveDirection() const;
	void setMoveDirection(double);
	double getMoveDuration() const;
	void setMoveDuration(double);

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

	// setter and getter
	void setHasEaten(int _y);
	int getHasEaten() const;


	void updateLevel();

	static int getFishPopulation();

	
	/* Method yang tidak melakukan apapun */
	virtual void Eat();
	
	/* Method yang tidak melakukan apapun */
	virtual bool DropCoin(double); 

private:
	static int fishPopulation;
	// BabyFish(lv1), TeenFish(lv2) and AdultFish(lv3)
	FishLevel level;
	// false means not hungry, vice versa 
	bool hunger;
	// Time counting for state changing
	double timeHungry;
	// The path fish go
	double moveDirection;
	// Time left to Move into that direction
	double moveDuration;
	// Umur
	int hasEaten;
};

#endif
