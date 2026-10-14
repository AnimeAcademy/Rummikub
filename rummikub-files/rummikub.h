#ifndef RUMMIKUB_H
#define RUMMIKUB_H
#include <fstream>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

enum Color { Red, Green, Blue, Yellow };


struct Tile {
    int     denomination;
    Color   color;

    bool operator<(const Tile& other) const {
        return denomination < other.denomination;
    }
};

inline std::ostream& operator<<(std::ostream& os, Tile const& t) {
    os << "{ " << t.denomination << ",";
    switch (t.color) {
    case Red:      os << "R"; break;
    case Green:    os << "G"; break;
    case Blue:     os << "B"; break;
    case Yellow:   os << "Y"; break;
    }
    os << " }";
    return os;
}

class RummiKub {
public:
    //Creates hand
    RummiKub() {}

    //adds tiles to the hand
    void Add(Tile const& tileToAdd) { hand.push_back(tileToAdd); } // add a tile to hand

    void Solve(); // solve

    // get solution - groups
    std::vector<std::vector<Tile>> GetGroups() const { return groups; };
    // get solution - runs
    std::vector<std::vector<Tile>> GetRuns() const { return runs; };
    // if both vectors are empty - no solution possible
private:

    int Recursion(int index);

    enum type {
        Group = 0,
        Run = 1
    };

    bool validCheck(std::vector<Tile> toBeChecked, type Typing);

    std::vector<std::vector<Tile>> runs;
    std::vector<std::vector<Tile>> groups;
    std::vector<Tile> hand;
};

#endif
