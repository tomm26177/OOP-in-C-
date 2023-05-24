#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

class Student {
    std::string Nazwisko;
    std::string Imie;
    int Nr_albumu;
    std::string Grupa;
    int Rok;

public:
    Student() {}
    Student(std::string nazwisko, std::string imie, int nr_albumu, std::string grupa, int rok)
            : Nazwisko(nazwisko), Imie(imie), Nr_albumu(nr_albumu), Grupa(grupa), Rok(rok) {}

    friend std::ostream& operator<<(std::ostream& os, const Student& s);
    friend std::istream& operator>>(std::istream& is, Student& s);

    int getRok() const { return Rok; }
};

std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << s.Nazwisko << ", " << s.Imie << ", " << s.Nr_albumu << ", " << s.Grupa << ", " << s.Rok;
    return os;
}

std::istream& operator>>(std::istream& is, Student& s) {
    is >> s.Nazwisko >> s.Imie >> s.Nr_albumu >> s.Grupa >> s.Rok;
    return is;
}

int main() {
    std::vector<Student> students;
    students.emplace_back("Tomasz","Kamisjki",1234,"114b",3);

    // Wczytywanie studentów z pliku
    std::ifstream inFile("students.txt");
    if(inFile.is_open()) {
        Student temp;
        while(inFile >> temp) {
            students.push_back(temp);
        }
        inFile.close();
    }

    // Wyświetlanie wszystkich studentów
    std::for_each(students.begin(), students.end(), [](const Student& s) {
        std::cout << s << '\n';
    });

    // Zliczanie studentów z 3 roku
    int count = std::count_if(students.begin(), students.end(), [](const Student& s) {
        return s.getRok() == 3;
    });

    std::cout << "Liczba studentów na 3 roku: " << count << '\n';

    // Zapisywanie studentów do pliku
    std::ofstream outFile("students_out.txt");
    if(outFile.is_open()) {
        for(const auto& s : students) {
            outFile << s << '\n';
        }
        outFile.close();
    }

    return 0;
}