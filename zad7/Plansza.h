#ifndef OOP_IN_C_PLANSZA_H
#define OOP_IN_C_PLANSZA_H

#include <iostream>
#include <vector>
#include <fstream>
#include "Pole.h"

class Plansza {
public:
    Plansza(int rozmiar);

    int pobierzRozmiar();

    void wyswietl() const;

    void wyswietlBezStatkow() const;

    Pole& operator()(int wiersz, int kolumna);

    static void zapiszDoPliku(const Plansza& plansza, const std::string& nazwaPliku);

private:
    std::vector<std::vector<Pole>> plansza;
    int rozmiar;
};

#endif // OOP_IN_C_PLANSZA_H
