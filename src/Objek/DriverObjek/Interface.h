#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
using namespace std;
/* Kelas ini mendefinisikan bagaimana sebuah objek yang dapat terlihat
	berbeda saat runtime seperti ikan-ikan dan siput saat bergerak
*/

class Interface
{
public:
	Interface(string);

	// setter and getter
	void setDirection(bool);
	bool getDirection() const;
	void setImageFile(string);
	string getImageFile() const;


private:
	/* Mendefinisikan kearah mana sebuah objek menghadap.
		True berarti ke Kanan dan False berarti ke Kiri */
	bool direction;	
	/* Image Sekarang */
	string imageFile;
};
#endif