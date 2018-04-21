#include "Interface.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

Interface::Interface(string _imageFile){
	//srand(time(0));
	int randomval = rand() % 2;
	if (randomval == 0){
		direction = false;
	} else {
		direction = true;
	}

	imageFile = _imageFile;
}

// setter and getter
void Interface::setDirection(bool b){
	direction = b;
}

bool Interface::getDirection() const{
	return direction;
}

void Interface::setImageFile(string _imageFile) {
	imageFile = _imageFile;
}

string Interface::getImageFile() const {
	return imageFile;
}

