#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <Gra.h>
#include <Plansza.h>
#include <Pole.h>


int main() {
    // Inicjalizacja generatora liczb losowych
    srand(time(nullptr));

    // Utworzenie gry
    Gra gra(10);

    // Rozpoczęcie gry
    gra.rozpocznijGre();

    return 0;
}
