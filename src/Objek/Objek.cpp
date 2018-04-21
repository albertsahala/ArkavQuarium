#include <iostream>
using namespace std;
#include "Objek.h"
#include "../oop.hpp"

#define Speed 50
#define TIME_MAX_AT_BOTTOM 3

Objek::Objek() : Akuarium(0,0), Interface("image/coin1.png") {
	timeAtBottom = 0;
}

Objek::Objek(double _x, double _y) : Akuarium(_x,_y), Interface("image/coin1.png") {
	timeAtBottom = 0;
}

Objek::Objek(double _x, double _y, string imageFile) : Akuarium(_x,_y), Interface(imageFile) {
	timeAtBottom = 0;
}
	
/* Method untuk pergerakan objek */
void Objek::Move (double sec_since_last) {
	double y = Akuarium::getPosY();
    double newPosY = y + Speed*sec_since_last;
    
    if (newPosY >= SCREEN_HEIGHT - 100) {
    	timeAtBottom += sec_since_last;
    }
    else {
    	Akuarium::setPosY(newPosY);
    }
}

void Objek::setTimeAtBottom (double _timeAtBottom) {
	timeAtBottom = _timeAtBottom;
}

double Objek::getTimeAtBottom () const {
	return timeAtBottom;
}

bool Objek::remove() {
	if (timeAtBottom > 3) {
		return true;
	}
	else {
		return false;
	}
}
