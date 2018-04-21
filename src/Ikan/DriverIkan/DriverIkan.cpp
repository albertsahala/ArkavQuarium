#include "oop.hpp"
#include "Guppy.h"
#include "Piranha.h"
#include <iostream>
#include <cmath>
using namespace std;

#define MIN_DISTANCE 20

int main( int argc, char* args[] )
{
    init();

    /* initialize random seed: */
    srand (time(NULL));

    bool running = true;

    double prevtime = time_since_start();
    double now = time_since_start();
    double sec_since_last = now - prevtime;

    Guppy hidup(100,100);
    Piranha mati(500,500);

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

        // UPDATING GUPPY
        if (hidup.getHunger()) {
            hidup.Move(sec_since_last, SCREEN_WIDTH/ 2, SCREEN_HEIGHT / 2);
            if (abs(hidup.getPosX() - SCREEN_WIDTH/ 2) < MIN_DISTANCE && abs(hidup.getPosY() - SCREEN_HEIGHT / 2) < MIN_DISTANCE) {
                hidup.setHunger(false);
                hidup.setTimeHungry(hidup.getFreeHungry_Time_Guppy());
                hidup.setHasEaten(hidup.getHasEaten() + 1);
            }
            else {
                hidup.setTimeHungry(hidup.getTimeHungry() - sec_since_last); 
                      
                if (hidup.getTimeHungry() < 0) {
                    running = false;         
                }
                else {
                    hidup.setTimeHungry(hidup.getTimeHungry() - sec_since_last);    
                }
            }
        }
        else {
            hidup.Move(sec_since_last);
            if (hidup.getTimeHungry() < 0) {
                hidup.setHunger(true);
                hidup.setTimeHungry(hidup.getGetFood_Time_Guppy());
            }
            else {
                hidup.setTimeHungry(hidup.getTimeHungry() - sec_since_last);   
            }
        }

        if (hidup.getLevel() != Ikan::AdultFish) {
            hidup.updateLevel();
        }

        // DRAWING GUPPY
        string sizeIkan = hidup.getImageFile();

        if (hidup.getHunger()) {
            sizeIkan += "x";
        }

        if (hidup.getDirection()) {
            draw_image(sizeIkan + "2.png", hidup.getPosX(), hidup.getPosY());
        }
        else {
            draw_image(sizeIkan + "1.png", hidup.getPosX(), hidup.getPosY());
        }

        // UPDATING Piranha POSITION
        if (mati.getHunger()) {
            mati.Move(sec_since_last, hidup.getPosX(), hidup.getPosY());
            if (abs(mati.getPosX() - hidup.getPosX()) < MIN_DISTANCE && abs(mati.getPosY() - hidup.getPosY()) < MIN_DISTANCE) {
                mati.setHunger(false);
                mati.setImageFile("piranha");
                mati.setTimeHungry(mati.getFreeHungry_Time_Piranha());
            }
            else {
                mati.setTimeHungry(mati.getTimeHungry() - sec_since_last); 
                      
                if (mati.getTimeHungry() < 0) {
                    running = false;         
                }
                else {
                    mati.setTimeHungry(mati.getTimeHungry() - sec_since_last);    
                }
            }
        }
        else {
            mati.Move(sec_since_last);
            if (mati.getTimeHungry() < 0) {
                mati.setHunger(true);
                mati.setTimeHungry(mati.getGetFood_Time_Piranha());
                mati.setImageFile("piranhaX");
            }
            else {
                mati.setTimeHungry(mati.getTimeHungry() - sec_since_last);   
            }
        }

        // DRAWING THE Piranha
        if (mati.getDirection()) {
            draw_image(mati.getImageFile() + "2.png", mati.getPosX(), mati.getPosY());
        }
        else {
            draw_image(mati.getImageFile() + "1.png", mati.getPosX(), mati.getPosY());
        }
        update_screen();
    }

    close();

    return 0;
}