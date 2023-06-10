#ifndef OOP_IN_C_GRA_H
#define OOP_IN_C_GRA_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "Plansza.h"

class Gra {
public:
    Gra(int rozmiarPlanszy);

    void rozpocznijGre();

private:
    Plansza planszaGracza;
    Plansza planszaPrzeciwnika;

    void rozmiescStatki(Plansza* planszaGracza);
    void ruchGracza();
    void ruchPrzeciwnika();
    bool czyGraSkonczona(Plansza* p);
    void wyswietlWynik();
};

#endif // OOP_IN_C_GRA_H
