#ifndef OOP_IN_C_POLE_H
#define OOP_IN_C_POLE_H

class Pole {
public:
    enum class Stan { Puste, Statek, Trafiony, Pudlo };

    Pole();

    void ustawStan(Stan nowyStan);

    Stan pobierzStan() const;

private:
    Stan stan;
};

#endif // OOP_IN_C_POLE_H
