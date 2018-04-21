#include "oop.hpp"
#include <iostream>
#include <math.h>
#include <sstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "LinkedList.hpp"
#include "Objek.h"
#include "Koin.h"
#include "MakananIkan.h"
using namespace std;

int main( int argc, char* args[] ) 
{
	 init();

    /* initialize random seed: */
    srand (time(NULL));
    LinkedList<Koin> ListKoin;
    LinkedList<MakananIkan> ListMakananIkan;
 	bool running = true;
    double prevtime = time_since_start();
    double now = time_since_start();
    double sec_since_last = now - prevtime;

    while (running) {
        now = time_since_start();
        sec_since_last = now - prevtime; 
        prevtime = now;

        handle_input();
        if (quit_pressed()) {
            running = false;
        }

        // Proses masukan yang bersifat "tombol"
        for (auto key : get_tapped_keys()) {
            switch (key) {
             case SDLK_a : {
            	MakananIkan a((rand() % (SCREEN_WIDTH-400)) + 200, 160);
                ListMakananIkan.add(a);
                break;
            }
              case SDLK_b : {
            	Koin b(Koin::Gold,(rand() % (SCREEN_WIDTH-400)) + 200, 160);
            	ListKoin.add(b);
            	break;
            }
            case SDLK_x: {
                running = false;
                break;
           	}
          
            }
        }

        clear_screen();
        draw_image("Aquarium1.jpg", SCREEN_WIDTH/ 2, SCREEN_HEIGHT / 2);

        node<Koin> *k;
        // UPDATING Koin POSITION
        k = ListKoin.getFirst();
        while (k != NULL) {
            Koin &isi = k -> data;
            isi.Move(sec_since_last);
            if (isi.remove()) {
                ListKoin.remove(isi);
            }
            k = k -> next;
        }

        // ------------------------------------------------------------------------------------------------------------------------
        // DRAWING THE Koin
        k = ListKoin.getFirst();
        while (k != NULL) {
            Koin isi = k -> data;
            draw_image(isi.getImageFile() + ".png", isi.getPosX(), isi.getPosY());
            k = k -> next;
            //cout << hidup.getPosX() << " " << hidup.getPosY() << endl;
        }

        // ------------------------------------------------------------------------------------------------------------------------
        node<MakananIkan> *m;
        // UPDATING MakananIkan POSITION
        m = ListMakananIkan.getFirst();
        while (m != NULL) {
            MakananIkan &isi = m -> data;
            isi.Move(sec_since_last);
            isi.updateIterasiGambar();
            if (isi.remove()) {
                ListMakananIkan.remove(isi);
            }
            m = m -> next;
        }

        // ------------------------------------------------------------------------------------------------------------------------
        // DRAWING THE MakananIkan
        m = ListMakananIkan.getFirst();
        while (m != NULL) {
            MakananIkan isi = m -> data;
            draw_image(isi.getImageFile() + std::to_string(isi.getIterasiGambar()) + ".png", isi.getPosX(), isi.getPosY());
            m = m -> next;
            //cout << hidup.getPosX() << " " << hidup.getPosY() << endl;
        }
        update_screen();
    }

}