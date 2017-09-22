/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 * Teraz jest zrobiony linear search = O(n)
 * Później trzeba przejść na O(log n) czyli binary search
 */
bool search(int value, int values[], int n)
{
    for (int i = 0; i < n; i ++) {
        if (values[i] == value) {
            return true;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 * Musi być w ramach O(n^2), czyli wystarczy bubble sort
 */
void sort(int values[], int n)
{
    // TODO: implement a sorting algorithm
    // values[] to array, a n to jego wielkość
    for (int i = 0; i < n-2; i++) {
        int a = values[i];
        int b = values[i+1];
        if (a > b) {
            values[i] = b;
            values[i+1] = a;
        }
    }
    return;
}