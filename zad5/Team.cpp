#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>
#include <iomanip>
#include <vector>
#include<stdlib.h>
using namespace std;

class Team {
public:
    std::string name;
    int wins;
    int draws;
    int losses;
    int goals;
    int conceded_goals;

    Team(const std::string& n, int w, int d, int l, int g, int cg):
        name(n), wins(w), draws(d), losses(l), goals(g), conceded_goals(cg) {}

    int score() const {
        return draws + wins * 3;
    }

    friend std::ostream& operator<<(std::ostream& os, const Team& team) {
        os << team.name << " - " << team.wins << "\033[32m" << "W \t" << "\033[0m"
           << team.draws << "R \t" << team.losses << "\033[31m" << "L \t" << "\033[0m"
           << team.goals << "\033[32m" << "G\t" << "\033[0m" << team.conceded_goals
           << "\033[31m" << "CG \n" << "\033[0m";
        return os;
    }

    bool operator<(const Team& other) const {
        if (score() != other.score()) return score() > other.score();
        if (wins != other.wins) return wins > other.wins;
        if (losses != other.losses) return losses < other.losses;
        if (goals != other.goals) return goals > other.goals;
        return conceded_goals < other.conceded_goals;
    }
};



