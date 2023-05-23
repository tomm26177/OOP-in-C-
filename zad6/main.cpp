//
// Created by 48510 on 23.05.2023.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "Student.cpp"

int main() {
    std::vector<Student> students;

    // Dodajemy przykładowych studentów do listy
    students.push_back({"Kowalski", "Jan", "12345", "A", 2});
    students.push_back({"Nowak", "Anna", "67890", "B", 3});
    students.push_back({"Smith", "John", "54321", "A", 3});
    students.push_back({"Johnson", "Emily", "98765", "B", 2});

    // Zapisujemy listę studentów do pliku
    std::ofstream outputFile("students.txt");
    if (outputFile.is_open()) {
        for (const auto &student: students) {
            outputFile << student.Nazwisko << " "
                       << student.Imie << " "
                       << student.NrAlbumu << " "
                       << student.Grupa << " "
                       << student.Rok << std::endl;
        }
        outputFile.close();
    } else {
        std::cout << "Błąd podczas otwierania pliku do zapisu." << std::endl;
    }

    // Wczytujemy listę studentów z pliku
    std::ifstream inputFile("students.txt");
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            Student student;
            iss >> student.Nazwisko >> student.Imie >> student.NrAlbumu >> student.Grupa >> student.Rok;
            students.push_back(student);
        }
        inputFile.close();
    } else {
        std::cout << "Błąd podczas otwierania pliku do odczytu." << std::endl;
    }

    // Wyświetlanie studenta na ekranie za pomocą przeciążonego operatora <<
    std::cout << "Student 1:" << std::endl;
    std::cout << students[0] << std::endl;

    // Wyświetlanie wszystkich studentów za pomocą for_each i lambdy
    std::cout << "Wszyscy studenci:" << std::endl;
    std::for_each(students.begin(), students.end(), [](const Student &student) {
        std::cout << student << std::endl;
        }


    // Zliczanie studentów 3 roku za pomocą count_if
    int count = std::count_if(students.begin(), students.end(), [](const Student &student)) {
        return student.Rok == 3;
    }

        std::cout << "Liczba studentów 3 roku: " << count << std::endl;
    };