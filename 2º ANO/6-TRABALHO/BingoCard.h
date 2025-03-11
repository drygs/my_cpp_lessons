#ifndef BINGOCARD_H
#define BINGOCARD_H

#include <vector>
#include <string>

using namespace std;

class BingoCard {
public:
    BingoCard(int id);
    void generate();
    void printToFile(const string& filename) const;

private:
    int id;
    vector<vector<int>> card;
};

#endif