#ifndef AKUARIUM_H
#define AKUARIUM_H

/* Kelas dasar utama */
class Akuarium
{
public :
	// ctor
	Akuarium(double _x, double _y);
	/*
		Untuk empat sekawan lainnya dianggap tidak perlu
		karena class ini hanya memiliki atribut doubleeger
		dan dari spek game dapat dilihat hal ini
		tidak dibutuhkan
	*/
	
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
	
	/* Method yang tidak melakukan apapun, selanjutnya akan didefinisikan di kelas anak */
	virtual void Move(double sec_since_last) = 0;
	
private :
	double x,y;
};

#endif
