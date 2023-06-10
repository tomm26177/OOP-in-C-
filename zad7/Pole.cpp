#include "Pole.h"

Pole::Pole() : stan(Stan::Puste) {}

void Pole::ustawStan(Stan nowyStan) {
    stan = nowyStan;
}

Pole::Stan Pole::pobierzStan() const {
    return stan;
}
