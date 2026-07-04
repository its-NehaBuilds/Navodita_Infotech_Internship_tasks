#ifndef SORTING_H
#define SORTING_H

class Sorting
{
public:
    void bubbleSort(int arr[], int size);

    void selectionSort(int arr[], int size);

    void insertionSort(int arr[], int size);

    void mergeSort(int arr[], int left, int right);

    void quickSort(int arr[], int low, int high);

    void merge(int arr[], int left, int mid, int right);

    int partition(int arr[], int low, int high);
};

#endif