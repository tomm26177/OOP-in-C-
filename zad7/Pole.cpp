#include "Pole.h"

Pole::Pole() : stan(Stan::Puste) {
    // Konstruktor
}

void Pole::ustawStan(Stan nowyStan) {
    stan = nowyStan;
}

Pole::Stan Pole::pobierzStan() const {
    return stan;
}
