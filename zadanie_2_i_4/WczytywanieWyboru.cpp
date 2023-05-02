#include <WczytywanieZnaku.cpp>
#include <iostream>
#include <string>

class WczytywanieWyboru {
public:
    WczytywanieZnaku wczytywanieZanku;

public:
 char WczytajWybor(){
    char wybor;
    wybor = wczytywanieZanku.WczytajZnak();

    while (wybor != '1' && wybor != '2')
    {
       std::cout << "\n" << "Wybierz [1-2]: ";
       std::cin >> wybor;
    }

    return wybor;

}


};
