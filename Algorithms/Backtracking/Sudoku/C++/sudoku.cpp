/**
 *  Author: Nhat M. Nguyen
 *  Date: 07-01-2018
 *  Note: Input in the form of txt files are taken from:
 *   http://www.printable-sudoku-puzzles.com/wfiles/
**/

#include <iostream>
#include <string>
#include <time.h>
#include <vector>


using namespace std;


struct Cell {
    int num = 0;
    bool given = false;
};


vector<string> inputLine;
Cell sudoku[9][9];


void parseInput() {
    string line;
    while (cin >> line) {
        inputLine.push_back(line);
    }
}


void processInput(string line) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            int index = row * 9 + col;
            int num = line[index] - '0';
            sudoku[row][col].num = num;
            if (num == 0) {
                sudoku[row][col].given = false;
            }
            else {
                sudoku[row][col].given = true;
            }
        }
    }
}


bool checkRow(int row, int col, int num) {
    for (int j = 0; j < 9; j++) {
        if (j == col) continue;
        if (sudoku[row][j].num == num) {
            return false;
        }
    }
    return true;
}


bool checkCol(int row, int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (i == row) continue;
        if (sudoku[i][col].num == num) {
            return false;
        }
    }
    return true;
}


bool checkSubgrid(int row, int col, int num) {
    int startRow = row / 3 * 3;
    int startCol = col / 3 * 3;
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (i == row && j == col) continue;
            if (sudoku[i][j].num == num) {
                return false;
            }
        }
    }
    return true;
}


bool accept(int row, int col, int num) {
    bool result = true;
    result &= checkRow(row, col, num);
    result &= checkCol(row, col, num);
    result &= checkSubgrid(row, col, num);
    return result;
}


void printGrid() {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            cout << sudoku[row][col].num << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}


void solveCell(int row, int col) {
    // Terminate
    if (row == 9) {
        printGrid();
        return;
    }

    // Calculate next row, next col
    int nextRow = 0;
    int nextCol = 0;
    if (col == 8) {
        nextCol = 0;
        nextRow = row + 1;
    }
    else {
        nextCol = col + 1;
        nextRow = row;
    }

    // Check if cell is given
    if (sudoku[row][col].given) {
        // If given, solve next cell
        solveCell(nextRow, nextCol);
    }
    else {
        // If not, try all possible nums
        for (int num = 1; num <= 9; num++) {
            if (accept(row, col, num)) {
                sudoku[row][col].num = num;
                solveCell(nextRow, nextCol);
                // Return the value of num back to 0 after a try
                sudoku[row][col].num = 0;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    freopen("input1.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    parseInput();

    clock_t beginTime = clock();

    for (int i = 0; i < 10000; i++) {
        processInput(inputLine[i]);
        solveCell(0, 0);
    }

    clock_t endTime = clock();
    double elapsedTime = (double) (endTime - beginTime);
    cerr << "Time elapsed: " << elapsedTime / CLOCKS_PER_SEC << " s.\n";
    return 0;
}
