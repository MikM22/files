//***************************************************************************
//
//  selection_sort.cpp
//  CSCI 241 Assignment 1
//
//  Created by Mik Mieczkowski (z2010367)
//
//***************************************************************************

#include <iostream>
#include <iomanip>

using namespace std;

int build_array(int[]);
void sort_array(int[], int);
void print_array(int[], int);

/**
 * Builds a list of integers from standard input and then sorts and prints
 * them.
 *
 * @return Returns 0 on successful completion.
 */
int main()
{
    int numbers[13] = {10, 11, 12, 13, 15, 123, 1231, 12, 123, 1243124,1, 0, -1};
    int n;

    n = 13;

    sort_array(numbers, n);

    print_array(numbers, n);

    return 0;
}

/**
 * Reads a list of integers into an array from standard input.
 *
 * @author Kurt McMahon
 *
 * @param array The array into which the integers are read.
 *
 * @return The number of integers read (size of the list).
 */
int build_array(int array[])
{
    int n = 0;

    while (cin >> array[n])
        n++;

    return n;
}

/**
 * Sorts a list of integers in ascending order.
 *
 * @param array The list of integers to sort.
 * @param n The size of the list.
 *
 * @note Uses the insertion sort algorithm.
 */
void sort_array(int array[], int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (array[j] < array[j-1]) {
                swap(array[j], array[j-1]);
            } else {
                //if it didn't swap then it's in the right place
                break;
            }
        }
    }
}

/**
 * Prints a list of integers.
 *
 * @param array The list of integers to print.
 * @param n The size of the list.
 */
void print_array(int array[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << setw(8) << array[i];
        bool isEighthNumber = (i+1) % 8 == 0;
        if (isEighthNumber || i == n - 1) {
            cout << endl;
        }
    }
}
