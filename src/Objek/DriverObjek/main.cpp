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

#define MIN_DISTANCE 20

int main( int argc, char* args[] )
{
    init();

    /* initialize random seed: */
    srand (time(NULL));
    LinkedList<Koin> ListKoin;
    LinkedList<MakananIkan> ListMakananIkan;

    bool running = true;
    bool exit = false;
    bool win = false;
    int money = 15000;

    double prevtime = time_since_start();
    double now = time_since_start();
    double sec_since_last = now - prevtime;

    int number = 1;
    int map = 1;

    double hold = 0.5;
    while (running && !exit) {
        now = time_since_start();
        sec_since_last = now - prevtime; 
        prevtime = now;

        handle_input();
        // HANDLING FOR WHAT HAD BEEN PRESSED
        if (quit_pressed()) {
            exit = true;;
        }

        if (!getPosPressedX().empty()) {
            std::set<double>::iterator PosX=getPosPressedX().begin();
            std::set<double>::iterator PosY=getPosPressedY().begin();
            if ((*PosX > 655) && (*PosX < 940) && (*PosY > 75) && (*PosY < 180)) {
                running = false;
            }
            else if ((*PosX > 865) && (*PosX < 975) && (*PosY > 660) && (*PosY < 705)) {
                exit = true;
            }
        }

        for (auto key : get_tapped_keys()) {
            if (key == SDLK_x) exit = true;
        }

        if (hold < 0) {
            if (map == 1) {
                map = 2;
            }
            else {
                map = 1;
            }
            hold = 0.5;
        }
        else {
            hold -= sec_since_last;
        }

        clear_screen();
        draw_image("image/mainmenu" + std::to_string(map) + ".png", SCREEN_WIDTH/ 2, SCREEN_HEIGHT / 2);
        update_screen();
    }

    running = true;

    while (running && !exit) {
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
            // x untuk keluar
            case SDLK_d : {
                if (map == 3) {
                    map = 1;
                }
                else {
                    map++;
                }
                break;
            }
            case SDLK_x:
                running = false;
                break;
            
           
            case SDLK_f:{
                    int updateMoney = money - 5;
                    if (updateMoney >= 0) {
                        MakananIkan a((rand() % (SCREEN_WIDTH-400)) + 200, 160);
                        ListMakananIkan.add(a);
                        money = updateMoney;
                    }
                }
                break;
            case SDLK_c:
                switch (number) {
                    case 1 : if (money > 50) {
                        money -= 50;
                        number++;
                        break;
                    }
                    case 2 : if (money > 100) {
                        money -= 100;
                        number++;
                        break;
                    }
                    case 3 : if (money > 150) {
                        money -= 150;
                        running = false;
                        win = true;
                        break;
                    }
                }
                break;
            }
        }

        // HANDLING FOR WHAT HAD BEEN PRESSED
        if (!getPosPressedX().empty()) {
            std::set<double>::iterator PosX=getPosPressedX().begin();
            std::set<double>::iterator PosY=getPosPressedY().begin();
            if ((*PosX > 40) && (*PosX < 120) && (*PosY > 10) && (*PosY < 75)) {
                int updateMoney = money - Guppy::getHARGA_GUPPY();
                if (updateMoney >= 0) {
                    Guppy a((rand() % (SCREEN_WIDTH-400)) + 200, (rand() % (SCREEN_HEIGHT-300)) + 150);
                    ListGuppy.add(a);
                    money = updateMoney;
                }
            }
            else if ((*PosX > 355) && (*PosX < 430) && (*PosY > 10) && (*PosY < 75)) {
                int updateMoney = money - Piranha::getHARGA_PIRANHA();
                if (updateMoney >= 0) {
                    Piranha a((rand() % (SCREEN_WIDTH-400)) + 200, (rand() % (SCREEN_HEIGHT-300)) + 150);
                    ListPiranha.add(a);
                    money = updateMoney;
                }
            }
            else if ((*PosX > 705) && (*PosX < 777) && (*PosY > 10) && (*PosY < 75)) {
                switch (number) {
                    case 1 : if (money > 50) {
                        money -= 50;
                        number++;
                        break;
                    }
                    case 2 : if (money > 100) {
                        money -= 100;
                        number++;
                        break;
                    }
                    case 3 : if (money > 150) {
                        money -= 150;
                        running = false;
                        win = true;
                        break;
                    }
                }
            }
            else if (*PosY > 120) {
                double x, y;
                ListKoin.findNearest(*PosX, *PosY, &x, &y);

                if (abs(*PosX - x) < MIN_DISTANCE && abs(*PosY - y) < MIN_DISTANCE) {
                    Koin i = ListKoin.remove(x, y);
                    i.addMoney(&money);
                }
                else {
                    int updateMoney = money - 5;
                    if (updateMoney >= 0) {
                        MakananIkan a(*PosX, *PosY);
                        ListMakananIkan.add(a);
                        money = updateMoney;
                    }
                }
            }
        }

        clear_screen();
        draw_image("image/Aquarium" + std::to_string(map) + ".jpg", SCREEN_WIDTH/ 2, SCREEN_HEIGHT / 2);
        string backTank = "image/tank" + std::to_string(number) + ".png";
        draw_image(backTank, SCREEN_WIDTH/ 2, SCREEN_HEIGHT / 2);
        draw_text(std::to_string(money), 30, 900, 60, 0x9c, 0xcc, 0x65);

       /* // UPDATING SNAIL
        double posisiTerdekatX, posisiTerdekatY;
        ListKoin.findWay(&posisiTerdekatX, &posisiTerdekatY, Eka.getPosX());
        if (posisiTerdekatX != -999) {
            if (abs(Eka.getPosX() - posisiTerdekatX) < MIN_DISTANCE && abs(Eka.getPosY() - posisiTerdekatY) < MIN_DISTANCE) {
                Koin i = ListKoin.remove(posisiTerdekatX, posisiTerdekatY);
                i.addMoney(&money);
            }
            else {
                if (posisiTerdekatX - Eka.getPosX() < 0) {
                    Eka.Move(false, sec_since_last);    
                }
                else {
                    Eka.Move(true, sec_since_last);
                }
            }
        }

        // DRAWING SNAIL
        if (Eka.getDirection()) {
            draw_image(Eka.getImageFile() + "2.png", Eka.getPosX(), Eka.getPosY());
        }
        else {
            draw_image(Eka.getImageFile() + "1.png", Eka.getPosX(), Eka.getPosY());
        }

        // ------------------------------------------------------------------------------------------------------------------------
        node<Guppy> *g;
        // UPDATING GUPPY POSITION
        g = ListGuppy.getFirst();
        while (g != NULL) {
            Guppy &hidup = g -> data;
            if (hidup.getHunger()) {
                double x, y;
                ListMakananIkan.findNearest(hidup.getPosX(), hidup.getPosY(), &x, &y);
                if (x > 0) {
                // Ada MakananIkan
                    hidup.Move(sec_since_last, x, y);
                    if (abs(hidup.getPosX() - x) < MIN_DISTANCE && abs(hidup.getPosY() - y) < MIN_DISTANCE) {
                        hidup.setHunger(false);
                        hidup.setTimeHungry(hidup.getFreeHungry_Time_Guppy());
                        ListMakananIkan.remove(x, y);
                        hidup.setHasEaten(hidup.getHasEaten() + 1);
                    }
                }
                else {
                    hidup.setTimeHungry(hidup.getTimeHungry() - sec_since_last); 
                    hidup.Move(sec_since_last);  
                    if (hidup.getTimeHungry() < 0) {
                        ListGuppy.remove(hidup);
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

            if (hidup.DropCoin(sec_since_last)) {
                Ikan::FishLevel level = hidup.getLevel();
                switch (level) {
                    case Ikan::BabyFish : {Koin a(Koin::Bronze, hidup.getPosX(), hidup.getPosY()); ListKoin.add(a); break;}
                    case Ikan::TeenFish : {Koin a(Koin::Silver, hidup.getPosX(), hidup.getPosY()); ListKoin.add(a); break;}
                    default : {Koin a(Koin::Gold, hidup.getPosX(), hidup.getPosY()); ListKoin.add(a); break;}
                }
            }
            g = g -> next;
        }

        // ------------------------------------------------------------------------------------------------------------------------
        // DRAWING THE GUPPY
        g = ListGuppy.getFirst();
        while (g != NULL) {
            Guppy hidup = g -> data;
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
            g = g -> next;
            //cout << hidup.getPosX() << " " << hidup.getPosY() << endl;
        }

        // ------------------------------------------------------------------------------------------------------------------------
        node<Piranha> *p;
        // UPDATING Piranha POSITION
        p = ListPiranha.getFirst();
        while (p != NULL) {
            Piranha &hidup = p -> data;
            if (hidup.getHunger()) {
                double x, y;
                ListGuppy.findNearest(hidup.getPosX(), hidup.getPosY(), &x, &y);
                if (x > 0) {
                // Ada Ikan
                    hidup.Move(sec_since_last, x, y);
                    if (abs(hidup.getPosX() - x) < MIN_DISTANCE && abs(hidup.getPosY() - y) < MIN_DISTANCE) {
                        hidup.setHunger(false);
                        hidup.setImageFile("image/piranha");
                        hidup.setTimeHungry(hidup.getFreeHungry_Time_Piranha());
                        Ikan i = ListGuppy.remove(x, y);
                        Ikan::FishLevel level = i.getLevel();
                        switch (level) {
                            case Ikan::BabyFish : {Koin a(Koin::Diamond1, i.getPosX(), i.getPosY()); ListKoin.add(a); break;}
                            case Ikan::TeenFish : {Koin a(Koin::Diamond2, i.getPosX(), i.getPosY()); ListKoin.add(a); break;}
                            default : {Koin a(Koin::Diamond3, i.getPosX(), i.getPosY()); ListKoin.add(a); break;}
                        }
                    }
                }
                else {
                    hidup.setTimeHungry(hidup.getTimeHungry() - sec_since_last); 
                    hidup.Move(sec_since_last);  
                    if (hidup.getTimeHungry() < 0) {
                        ListPiranha.remove(hidup);
                    }
                }
            }
            else {
                hidup.Move(sec_since_last);
                if (hidup.getTimeHungry() < 0) {
                    hidup.setHunger(true);
                    hidup.setTimeHungry(hidup.getGetFood_Time_Piranha());
                    hidup.setImageFile("image/piranhaX");
                }
                else {
                    hidup.setTimeHungry(hidup.getTimeHungry() - sec_since_last);   
                }
            }

            p = p -> next;
        }

        // ------------------------------------------------------------------------------------------------------------------------
        // DRAWING THE Piranha
        p = ListPiranha.getFirst();
        while (p != NULL) {
            Piranha hidup = p -> data;
            if (hidup.getDirection()) {
                draw_image(hidup.getImageFile() + "2.png", hidup.getPosX(), hidup.getPosY());
            }
            else {
                draw_image(hidup.getImageFile() + "1.png", hidup.getPosX(), hidup.getPosY());
            }
            p = p -> next;
            //cout << hidup.getPosX() << " " << hidup.getPosY() << endl;
        }*/

        // ------------------------------------------------------------------------------------------------------------------------
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

        if (!running) {
            if (win) {
                draw_text("YOU WIN !!!", 160, 100, 270, 0x31, 0x1b, 0x92);
                draw_text("YOU WIN !!!", 150, 125, 280, 0xed, 0xe7, 0xf6);
            }
            else {
                draw_text("YOU LOSE !!!", 160, 100, 270, 0xff, 0x3d, 0x00); 
                draw_text("YOU LOSE !!!", 150, 125, 280, 0xfb, 0xe9, 0xe7);   
            }

            draw_text("Press Any Key to Exit", 50, 280, SCREEN_HEIGHT/2 + 50, 0x21, 0x21, 0x21);
        }

        update_screen();
    }

    running = true;
    while (running && !exit) {
        handle_input();
        if (!get_tapped_keys().empty()) {
            running = false;
        }
    }

    close();

    return 0;
}
