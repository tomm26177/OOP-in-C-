#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>
#include <iomanip>
#include <vector>
#include "Team.cpp"
using namespace std;





int main() {
    Team team1("Team A", 5, 2, 3, 15, 10);
    Team team2("Team B", 7, 1, 2, 20, 8);

    std::cout << team1 << std::endl;
    std::cout << team2 << std::endl;

    if (team1 < team2) {
        std::cout << "Team A has a lower ranking than Team B" << std::endl;
    } else {
        std::cout << "Team A has a higher or equal ranking than Team B" << std::endl;
    }

    return 0;
}
