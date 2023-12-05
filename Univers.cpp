#include "Universe.h"

void Universe::initialize() {
    Grid[14][14] = 1;
    Grid[15][15] = 1;
    Grid[16][15] = 1;
    Grid[16][14] = 1;
    Grid[16][13] = 1;
}

void Universe::reset() {
    memset(Grid, 0, sizeof(Grid));
}

int Universe::count_neighbors(int row, int col) {
    int count = 0;
    for (int k = 0; k < 8; ++k) {
        int newRow, newCol;
        switch (k) {
            case 0: newRow = row - 1; newCol = col - 1; break;
            case 1: newRow = row - 1; newCol = col; break;
            case 2: newRow = row - 1; newCol = col + 1; break;
            case 3: newRow = row; newCol = col - 1; break;
            case 4: newRow = row; newCol = col + 1; break;
            case 5: newRow = row + 1; newCol = col - 1; break;
            case 6: newRow = row + 1; newCol = col; break;
            case 7: newRow = row + 1; newCol = col + 1; break;
        }
        if (newRow > 0 && newRow < Rows && newCol > 0 && newCol < Columns) {
            count += Grid[newRow][newCol];
        }
    }
    return count;
}

void Universe::next_generation() {
    int newGrid[Rows][Columns]{0};
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Columns; j++) {
            int neighbors = count_neighbors(i, j);
            if (Grid[i][j]) {
                if (neighbors == 2 || neighbors == 3){
                    newGrid[i][j] = 1 ;
                }
            } else {
                if(neighbors == 3){
                    newGrid[i][j] = 1;
                }
            }
        }
    }
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Columns; j++) {
            Grid[i][j] = newGrid[i][j];
        }
    }
}

void Universe::display() {
    for (auto & i : Grid) {
        for (int j : i) {
            cout << (j ? "X" : ".")<<" ";
        }
        cout << endl;
    }

}

void Universe::run(int repetition) {
    for (int i = 0 ; i < repetition; i++) {
        display();
        cout << endl ;
        cout << endl ;
        cout << endl ;
        next_generation() ;
    }
}
