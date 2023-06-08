//
// Created by 48510 on 08.06.2023.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include "Board.cpp"

class Ship {
protected:
    std::string name;
    int size;
    int hits;
public:
    Ship(const std::string& n, int s) : name(n), size(s), hits(0) {}
    virtual ~Ship() {}

    // Metoda sprawdzająca, czy statek został zatopiony
    bool isSunk() const {
        return hits == size;
    }

    // Metoda zwracająca nazwę statku
    std::string getName() const {
        return name;
    }

    // Metoda zwracająca rozmiar statku
    int getSize() const {
        return size;
    }

    // Metoda oznaczająca trafienie w statek
    void hit() {
        hits++;
    }

    // Metoda wirtualna do użycia przez klasy pochodne
    virtual void place(Board& board) = 0;
};
