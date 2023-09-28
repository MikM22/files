/**
 * CSCI 241
 *
 * Author: Mik Mieczkowski (z2010367)
 *
 *
 */
#include <iostream>
#include <iomanip>
#include "solution.h"
using std::cin;
using std::cout;
using std::endl;

solution::solution()
{
    for (int row = 0; row < 9; row++)
        for (int col = 0; col < 9; col++)
            grid[row][col] = 0;
}

void solution::read()
{
    for (int row = 0; row < 9; row++)
        for (int col = 0; col < 9; col++)
            cin >> grid[row][col];
}
   
void solution::print() const
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
            cout << grid[row][col] << ' ';

        cout << endl;
    }

    cout << endl;
}
bool solution::verify() const {
    //r
    for (int r = 0; r < 9; r++) {
        bool num[9] = {false};
        for (int c = 0; c < 9; c++) {
            if (num[grid[r][c]-1]) {
                return false;
            } else {
                num[grid[r][c]-1] = true;
            }
        }
    }
    for (int c = 0; c < 9; c++) {
        bool num[9] = {false};
        for (int r = 0; r < 9; r++) {
            if (num[grid[r][c]-1]) {
                return false;
            } else {
                num[grid[r][c]-1] = true;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            bool num[9] = {false};
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    if (num[grid[i*3+k][j*3+l]-1]) {
                        return false;
                    } else {
                        num[grid[i*3+k][j*3+l]-1] = true;
                    }
                }
            }
        }
    }
    return true;
}
