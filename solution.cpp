/**
 * CSCI 241
 *
 * Authors: Mik Mieczkowski (z2010367), Nasiru Williams (z1907156), Anna Madalone (z1997286)
 *
 * solution.cpp
 */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int minimum(int array[], int n);
int maximum(int array[], int n);
int range(int array[], int n);
double average(int array[], int n);
double median(int array[], int n);
double stddev(int array[], int n);
void sort_array(int array[], int n);

int minimum(int array[], int n){
    sort_array(array, n);
    return array[0];
}
int maximum(int array[], int n){
    sort_array(array, n);
    return array[n-1];
}
int range(int array[], int n){
    return maximum(array, n) - minimum(array,n);
}
double average(int array[], int n){
    double avg;
    double total;
    for(int i=0;i<n;i++){
        total += array[i];
    }
    avg = total / n;
    return avg;
}
double median(int array[], int n){
    if (n%2==0) {
        return (array[n/2-1] + array[n/2])/2;
    } else {
        return array[n/2];
    }
}
double stddev(int array[], int n){
    int sqDist;
    int avg = average(array, n);
    for (int i = 0; i < n; i++) {
        sqDist += (array[i] - avg) * (array[i] - avg);
    }
    return sqrt(sqDist/n);
}

/**
 * Sorts a list of integers in ascending order.
 *
 * @param array The list of integers to sort.
 * @param n The size of the list.
 *
 * @note Uses the selection sort algorithm.
 */
void sort_array(int array[], int n)
{
    int i, j, min_index;
    // int temp;

    for (i = 0; i < n - 1; i++)
    {
        // Locate the smallest value in the unsorted part of the list.

        min_index = i;
        for (j = i + 1; j < n; j++)
            if (array[j] < array[min_index])
                min_index = j;

        // Swap smallest value with first unsorted value.

        swap(array[i], array[min_index]);

        /*
        temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
        */
    }
}

