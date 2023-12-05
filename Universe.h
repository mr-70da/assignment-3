#ifndef UNTITLED1_UNIVERSE_H
#define UNTITLED1_UNIVERSE_H
#include <bits/stdc++.h>
#include <random>
using namespace std;
class Universe {
private:
    static const int Rows = 30;
    static const int Columns= 30;
    int Grid[Rows][Columns]{0};
public:
    void initialize();
    void reset();
    int count_neighbors(int row, int col);
    void next_generation();
    void display();
    void run(int repetition);
};


#endif //UNTITLED1_UNIVERSE_H
