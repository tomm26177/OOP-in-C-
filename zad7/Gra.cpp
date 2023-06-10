#include "Gra.h"

Gra::Gra(int rozmiarPlanszy) : planszaGracza(rozmiarPlanszy), planszaPrzeciwnika(rozmiarPlanszy) {
    // Konstruktor
}

void Gra::rozpocznijGre() {
    rozmiescStatki(&planszaGracza);
    rozmiescStatki(&planszaPrzeciwnika);

    while (!(czyGraSkonczona(&planszaGracza) || czyGraSkonczona(&planszaPrzeciwnika))) {
        ruchGracza();
        Plansza::zapiszDoPliku(planszaGracza, "MyBoard.txt");
        ruchPrzeciwnika();
        Plansza::zapiszDoPliku(planszaPrzeciwnika, "EnemyBoard.txt");
    }

    wyswietlWynik();
}

void Gra::rozmiescStatki(Plansza* planszaGracza) {
    // Implementacja metody rozmiescStatki()
}

void Gra::ruchGracza() {
    // Implementacja metody ruchGracza()
}

void Gra::ruchPrzeciwnika() {
    // Implementacja metody ruchPrzeciwnika()
}

bool Gra::czyGraSkonczona(Plansza* p) {
    // Implementacja metody czyGraSkonczona()
}

void Gra::wyswietlWynik() {
    // Implementacja metody wyswietlWynik()
}
