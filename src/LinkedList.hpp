#include <iostream>
#include "Ikan/Guppy/Guppy.h"
#include "Objek/Koin/Koin.h"

using namespace std;

double abs (double a) {
    if (a > 0) return a;
    else return -a;
}

/* Definisi Isi tiap node dalam list */
template<class Type>
struct node {
	Type data;
	node *next;
};

/* LinkedList berupa list yang memiliki dua atribut yaitu
	address node list awal dan akhir. List generik ini linier
	dan 
*/
template<class T>
class LinkedList {
public :	
	// ctor. Menginisiasi kedua atribut dengan NULL
	LinkedList() {
		first = NULL;
		last = NULL;
	}

	// cctor dan operator= dinilai tidak dibutuhkan dalam 
	// penggunaan kelas list, mengingat game yang hanya akan
	// memiliki satu buah list untuk masing-masing tipe objek 
	// turunan terbawah.

	// dtor. Membebaskan semua isi list
	~LinkedList() {
		node<T> *curr = first;
		node<T> *temp;
		while (curr != NULL) {
			temp = curr;
			curr = curr -> next;
			delete temp;
		}
	}

	// Mencari posisi data dalam list, mengembalikan -1 jika tidak ditemukan
	int find(T &a) const {
		int i = 1;
		node<T> *curr = first;
		while (curr != NULL) {
			if (curr->data == a) {
				return i;
			}
			else {
				i++;
				curr = curr->next;
			}
		}
		return -1;
	}

	void findWay(double * positionX, double * positionY, double PosX) {
		if(!isEmpty()) {
			node<T> *curr = first;
			T isi = curr->data;
			*positionX = isi.getPosX();
			*positionY = isi.getPosY();
			do {
				isi = curr->data;
				if (*positionY < isi.getPosY()) {
					*positionX = isi.getPosX();
					*positionY = isi.getPosY();
				}
				else if (*positionY == isi.getPosY()) {
					if (abs(*positionX - PosX) > abs(isi.getPosX()- PosX)) {
						*positionX = isi.getPosX();
						*positionY = isi.getPosY();
					}
				}

				curr = curr->next;
			} while (curr != NULL);
		}
		else {
			*positionX = -999;
		}
	}

	// Mengembalikan true apabila List kosong dan sebaliknya
	bool isEmpty () const {
		return (first == NULL);
	}
	
	// Menambahkan satu buah data dalam list di bagian ujung
	void add(T &a) {
		node<T> *temp = new node<T>;
		temp->data = a;
		temp->next = NULL;
		
		if (first == NULL) {
			first = temp;
			last = temp;
		}
		else {
			last->next = temp;
			last = last->next;
		}
		cout <<"Telah ditambahkan ke Linked List" << endl;
	}

	// Menghapus list dengan data a dari dalam list dan menuliskan pesan
	// error jika elemen tersebut tidak ada dalam list
	void remove(T &a) {
		int idx = find(a);
		node<T> *curr = first;
		node<T> *prev = NULL;
		if (idx == -1) {
			cout << "Elemen tidak ada di dalam List" << endl;
		}
		else {
			for (int i = 1; i < idx; i++) {
				prev = curr;
				curr = curr->next;
			}
			if (prev == NULL) {
				first = curr->next;
				delete curr;
			}
			else {
				prev->next = curr->next;
				delete curr;
			}
		}
	}

	T remove(double x, double y) {
		node<T> *curr = first;
		T isi, temp;
		while (curr != NULL) {
			isi = curr->data; 
			if (isi.getPosX() == x && isi.getPosY() == y) {
				break;
			}
			else {
				curr = curr->next;
			}
		}

		temp = isi;
		this->remove(temp);
		return isi;
	}

	// Mengambil nilai list yang sudah diberikan posisinya
	T& get (int idx) const {
		if (idx == 1) {
			return first->data;
		}
		else {
			node<T> *curr = first;
			for (int i = 1; i < idx; i++) {
				curr = curr->next;
			}
			return curr->data;
		}
	}
	
	// TAMBAHAN
	// Menulikan seluruh isi list dengan newline untuk setiap data.
	// Fungsi juga akan menuliskan pesan kosong jika list kosong
	void printList() const {
		if(!isEmpty()) {
			node<T> *curr = first;
			do {
				cout << curr->data << endl;
				curr = curr->next;
			} while (curr != NULL);
		}
		else {
			cout << "List kosong";
		}
	}

	node<T> * getFirst() const {
		return first;
	}

	void findNearest(double x1, double y1, double *x2, double *y2) {
		if(!isEmpty()) {
			node<T> *curr = first;
			T isi = curr->data;
			*x2 = isi.getPosX();
			*y2 = isi.getPosY();
			double jarakMin = (x1 - *x2)*(x1 - *x2) + (y1 - *y2)*(y1 - *y2);
			do {
				isi = curr->data;
				if (jarakMin > (x1 - isi.getPosX())*(x1 - isi.getPosX()) + (y1 - isi.getPosY())*(y1 - isi.getPosY())) {
					*x2 = isi.getPosX();
					*y2 = isi.getPosY();
					jarakMin = (x1 - isi.getPosX())*(x1 - isi.getPosX()) + (y1 - isi.getPosY())*(y1 - isi.getPosY());
				}
				curr = curr->next;
			} while (curr != NULL);
		}
		else {
			*x2 = -999;
			*y2 = -999;
		} 
	}

private :
	// pointer penunjuk awal dan akhir list
	node<T> *last, *first;
};