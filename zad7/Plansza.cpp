#include "Plansza.h"

Plansza::Plansza(int rozmiar) : rozmiar(rozmiar) {
    plansza.resize(rozmiar, std::vector<Pole>(rozmiar));
}

int Plansza::pobierzRozmiar() {
    return rozmiar;
}

void Plansza::wyswietl() const {
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

void Plansza::wyswietlBezStatkow() const {
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

Pole& Plansza::operator()(int wiersz, int kolumna) {
    return plansza[wiersz][kolumna];
}

void Plansza::zapiszDoPliku(const Plansza& plansza, const std::string& nazwaPliku) {
    std::ofstream plik(nazwaPliku);

    if (plik.is_open()) {
        for (const auto& wiersz : plansza.plansza) {
            for (const auto& pole : wiersz) {
                switch (pole.pobierzStan()) {
                    case Pole::Stan::Puste:
                        plik << "- ";
                        break;
                    case Pole::Stan::Statek:
                        plik << "S ";
                        break;
                    case Pole::Stan::Trafiony:
                        plik << "X ";
                        break;
                    case Pole::Stan::Pudlo:
                        plik << "O ";
                        break;
                }
            }
            plik << std::endl;
        }

        plik.close();
        std::cout << "Pomyślnie zapisano do pliku: " << nazwaPliku << std::endl;
    } else {
        std::cout << "Błąd podczas otwierania pliku: " << nazwaPliku << std::endl;
    }
}
