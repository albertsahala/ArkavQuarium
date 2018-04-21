#include "oop.hpp"
#include "Siput.h"
#include <iostream>
#include <cmath>
using namespace std;

int main () {
	init();

    /* initialize random seed: */
    srand (time(NULL));

    bool running = true;

    double prevtime = time_since_start();
    double now = time_since_start();
    double sec_since_last = now - prevtime;

    Siput Eka(500);
    double posisiTerdekatX;
    double hold = 3;

    posisiTerdekatX = rand() % SCREEN_WIDTH;

    while (running) {
        now = time_since_start();
        sec_since_last = now - prevtime; 
        prevtime = now;

        handle_input();
        if (quit_pressed()) {
            running = true;
        }

        // Proses masukan yang bersifat "tombol"
        for (auto key : get_tapped_keys()) {
            switch (key) {
            case SDLK_x:
                running = false;
                break;
            }
        }

        clear_screen();
        draw_image("Aquarium1.jpg", SCREEN_WIDTH/ 2, SCREEN_HEIGHT / 2);

        if (hold > 0) {
        	hold -= sec_since_last;
        }
        else {
        	hold = ((double) (rand() % 1000))/200.0;
		    posisiTerdekatX = (rand() % 8)*100;
        }

        // UPDATING SNAIL
        if (posisiTerdekatX != 0) {
        	if (posisiTerdekatX - Eka.getPosX() < 0) {
	            Eka.Move(false, sec_since_last);    
	        }
	        else {
	            Eka.Move(true, sec_since_last);
	        }	
        } 
        
        // DRAWING SNAIL
        if (Eka.getDirection()) {
            draw_image(Eka.getImageFile() + "2.png", Eka.getPosX(), Eka.getPosY());
        }
        else {
            draw_image(Eka.getImageFile() + "1.png", Eka.getPosX(), Eka.getPosY());
        }

        update_screen();
    }

    close();

    return 0;
}