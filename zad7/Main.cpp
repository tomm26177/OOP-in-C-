#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// Klasa reprezentująca pole na planszy
class Pole {
public:
    enum class Stan { Puste, Statek, Trafiony, Pudlo };

    Pole() : stan(Stan::Puste) {}

    void ustawStan(Stan nowyStan) {
        stan = nowyStan;
    }

    Stan pobierzStan() const {
        return stan;
    }

private:
    Stan stan;
};

// Klasa reprezentująca planszę
class Plansza {
public:
    Plansza(int rozmiar) : rozmiar(rozmiar) {
        plansza.resize(rozmiar, std::vector<Pole>(rozmiar));
    }
    int pobierzRozmiar(){
        return rozmiar;

    }

    void wyswietl() const {
        for (const auto& wiersz : plansza) {
            for (const auto& pole : wiersz) {
                switch (pole.pobierzStan()) {
                    case Pole::Stan::Puste:
                        std::cout << "- ";
                        break;
                    case Pole::Stan::Statek:
                        std::cout << "S ";
                        break;
                    case Pole::Stan::Trafiony:
                        std::cout << "X ";
                        break;
                    case Pole::Stan::Pudlo:
                        std::cout << "O ";
                        break;
                }
            }
            std::cout << std::endl;
        }
    }


    void wyswietlBezStatkow() const {
        for (const auto& wiersz : plansza) {
            for (const auto& pole : wiersz) {
                switch (pole.pobierzStan()) {
                    case Pole::Stan::Puste:
                        std::cout << "- ";
                        break;
                    case Pole::Stan::Statek:
                        std::cout << "- ";
                        break;
                    case Pole::Stan::Trafiony:
                        std::cout << "X ";
                        break;
                    case Pole::Stan::Pudlo:
                        std::cout << "O ";
                        break;
                }
            }
            std::cout << std::endl;
        }
    }

    Pole& operator()(int wiersz, int kolumna) {
        return plansza[wiersz][kolumna];
    }

private:
    std::vector<std::vector<Pole>> plansza;
    int rozmiar;
};

// Klasa reprezentująca grę
class Gra {
public:
    Gra(int rozmiarPlanszy) : planszaGracza(rozmiarPlanszy), planszaPrzeciwnika(rozmiarPlanszy) {}

    void rozpocznijGre() {
        rozmiescStatki(&planszaGracza);
        rozmiescStatki(&planszaPrzeciwnika);

        while (!(czyGraSkonczona(&planszaGracza)&& czyGraSkonczona(&planszaPrzeciwnika))) {
            ruchGracza();
            ruchPrzeciwnika();
        }

        wyswietlWynik();
    }

private:
    Plansza planszaGracza;
    Plansza planszaPrzeciwnika;

    void rozmiescStatki(Plansza* planszaGracza) {
        // Inicjalizacja generatora liczb losowych
        srand(time(nullptr));

        // Tablica z długościami statków
        std::vector<int> dlugosciStatkow = {5, 4, 3, 3, 2};

        for (int dlugosc : dlugosciStatkow) {
            bool ustawiony = false;

            // Losowe ustawianie statków, dopóki nie zostanie ustawiony poprawnie
            while (!ustawiony) {
                int wiersz = rand() % planszaGracza->pobierzRozmiar();
                int kolumna = rand() % planszaGracza->pobierzRozmiar();

                // Losowe ustawienie pionowe lub poziome
                bool pionowo = rand() % 2 == 0;

                if (pionowo) {
                    // Sprawdzanie czy można ustawić statek pionowo
                    if (wiersz + dlugosc <= planszaGracza->pobierzRozmiar()) {
                        bool moznaUstawic = true;

                        // Sprawdzanie czy pola nie są już zajęte
                        for (int i = wiersz; i < wiersz + dlugosc; ++i) {
                            if (planszaGracza->operator()(i, kolumna).pobierzStan() != Pole::Stan::Puste) {
                                moznaUstawic = false;
                                break;
                            }
                        }

                        // Ustawianie statku pionowo
                        if (moznaUstawic) {
                            for (int i = wiersz; i < wiersz + dlugosc; ++i) {
                                planszaGracza->operator()(i, kolumna).ustawStan(Pole::Stan::Statek);
                            }
                            ustawiony = true;
                        }
                    }
                } else {
                    // Sprawdzanie czy można ustawić statek poziomo
                    if (kolumna + dlugosc <= planszaGracza->pobierzRozmiar()) {
                        bool moznaUstawic = true;

                        // Sprawdzanie czy pola nie są już zajęte
                        for (int j = kolumna; j < kolumna + dlugosc; ++j) {
                            if (planszaGracza->operator()(wiersz, j).pobierzStan() != Pole::Stan::Puste) {
                                moznaUstawic = false;
                                break;
                            }
                        }

                        // Ustawianie statku poziomo
                        if (moznaUstawic) {
                            for (int j = kolumna; j < kolumna + dlugosc; ++j) {
                                planszaGracza->operator()(wiersz, j).ustawStan(Pole::Stan::Statek);
                            }
                            ustawiony = true;
                        }
                    }
                }
            }
        }
    }

    void ruchGracza() {

        std::cout << "plansza oponenta" << "\n";

        planszaPrzeciwnika.wyswietlBezStatkow();
        std::cout<< "------------------------------------------------------"<<"\n";

        std::cout << "Twoja plansza:" << std::endl;
        planszaGracza.wyswietl();




        int wiersz, kolumna;
        std::cout << "Podaj wspolrzedne strzalu (wiersz, kolumna): ";
        std::cin >> wiersz >> kolumna;


        if (wiersz < 0 || wiersz >= planszaPrzeciwnika.pobierzRozmiar() ||
            kolumna < 0 || kolumna >= planszaPrzeciwnika.pobierzRozmiar()) {
            std::cout << "Niepoprawne wspolrzedne strzalu!" << std::endl;
            return;
        }

        Pole& polePrzeciwnika = planszaPrzeciwnika(wiersz, kolumna);

        if (polePrzeciwnika.pobierzStan() == Pole::Stan::Statek) {
            std::cout << "TRAFIONY!" << std::endl;
            polePrzeciwnika.ustawStan(Pole::Stan::Trafiony);
        } else if (polePrzeciwnika.pobierzStan() == Pole::Stan::Puste) {
            std::cout << "PUDLO!" << std::endl;
            polePrzeciwnika.ustawStan(Pole::Stan::Pudlo);
        }
    }

    void ruchPrzeciwnika() {
        int wiersz = rand() % planszaGracza.pobierzRozmiar();
        int kolumna = rand() % planszaGracza.pobierzRozmiar();

        Pole& poleGracza = planszaGracza(wiersz, kolumna);

        if (poleGracza.pobierzStan() == Pole::Stan::Statek) {
            std::cout << "Przeciwnik trafia Twoj statek!" << std::endl;
            poleGracza.ustawStan(Pole::Stan::Trafiony);
        } else if (poleGracza.pobierzStan() == Pole::Stan::Puste) {
            std::cout << "Przeciwnik pudluje!" << std::endl;
            poleGracza.ustawStan(Pole::Stan::Pudlo);
        }
    }

    bool czyGraSkonczona(Plansza* p) {
        // Sprawdzenie, czy gra się skończyła (czy wszystkie statki zostały zatopione)
        // Można zaimplementować własną logikę zakończenia gry.
        // W przypadku, gdy wszystkie statki zostaną trafione, można zwrócić true.

        // Przykład sprawdzenia, czy wszystkie statki zostały zatopione:
        for (int i = 0; i < p->pobierzRozmiar(); ++i) {
            for (int j = 0; j < p->pobierzRozmiar(); ++j) {
                if (p->operator()(i, j).pobierzStan() == Pole::Stan::Statek) {
                    return false;
                }
            }
        }

        return true;
    }

    void wyswietlWynik() {
        std::cout << "Koniec gry!" << std::endl;
        std::cout << "Twoja plansza:" << std::endl;
        planszaGracza.wyswietl();
        std::cout << "Plansza przeciwnika:" << std::endl;
        planszaPrzeciwnika.wyswietl();
    }
};

int main() {
    // Inicjalizacja generatora liczb losowych
    srand(time(nullptr));

    // Utworzenie gry
    Gra gra(10);

    // Rozpoczęcie gry
    gra.rozpocznijGre();

    return 0;
}
