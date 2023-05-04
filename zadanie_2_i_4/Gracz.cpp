#include <iostream>
#include <string>

class Gracz {
public:
    string imie;
    int portfel;
    int kasa;

    // Przeciążony operator << do wyświetlania informacji o graczu
       friend std::ostream& operator<<(std::ostream& os, const Gracz& gracz)
       {
           os << "Imie: " << gracz.imie << ", Portfel: " << gracz.portfel << ", Kasa: " << gracz.kasa << std::endl;
           return os;
       }
       Gracz operator+(const Gracz& g1, const Gracz& g2)
       {
           Gracz nowyGracz;
           nowyGracz.imie = g1.imie + " i " + g2.imie;
           nowyGracz.portfel = g1.portfel + g2.portfel;
           nowyGracz.kasa = g1.kasa + g2.kasa;
           return nowyGracz;
       }

       bool operator==(const Gracz& g1, const Gracz& g2)
       {
           return g1.imie == g2.imie;
       }

       bool operator!=(const Gracz& g1, const Gracz& g2)
       {
           return !(g1 == g2);
       }

       bool operator<(const Gracz& g1, const Gracz& g2)
       {
           return g1.portfel < g2.portfel;
       }



};
