#include <Gracz.cpp>
#include <Kolejka.cpp>
class TextPlayers {
public:
    TextPlayers(Gracz gracze[3], Kolejka kolejka){
        int i;
        std::cout << "\n";
        for (i = 0; i < 3; i++) {
            if (i == kolejka.getKolejka()) {
                std::cout << "\033[1;34m";
            }
            std::cout << gracze[i].imie << "\t" << gracze[i].kasa << "\n";
            std::cout << "\033[0m";

        }
        std::cout << "\n";
    }
};