//
// Created by 48510 on 23.05.2023.
//


class Student {
public:
    std::string Nazwisko;
    std::string Imie;
    std::string NrAlbumu;
    std::string Grupa;
    int Rok;

    // Przeciążony operator <<
    friend std::ostream& operator<<(std::ostream& os, const Student& student) {
        os << "Nazwisko: " << student.Nazwisko << std::endl;
        os << "Imie: " << student.Imie << std::endl;
        os << "Nr albumu: " << student.NrAlbumu << std::endl;
        os << "Grupa: " << student.Grupa << std::endl;
        os << "Rok: " << student.Rok << std::endl;
        return os;
    }
};