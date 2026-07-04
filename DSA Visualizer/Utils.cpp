#include <iostream>
#include <cstdlib>

#include "Utils.h"

using namespace std;

void printArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void generateRandomArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        arr[i] = rand() % 20 + 1;
    }
}

void printBars(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " | ";

        for(int j = 0; j < arr[i]; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}