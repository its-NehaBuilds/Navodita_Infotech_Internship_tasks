#include <iostream>
#include "Sorting.h"
#include "Utils.h"

using namespace std;

void Sorting::bubbleSort(int arr[], int size)
{
    int comparisons = 0;
    int swaps = 0;

    cout << "\n===== BUBBLE SORT STARTED =====\n";

    for(int i = 0; i < size - 1; i++)
    {
        cout << "\n---------------------------------\n";
        cout << "Pass " << i + 1 << endl;

        for(int j = 0; j < size - i - 1; j++)
        {
            comparisons++;

            cout << "\nComparing " << arr[j]
                 << " and " << arr[j + 1] << endl;

            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swaps++;

                cout << "Swapped!" << endl;
            }
            else
            {
                cout << "No Swap Needed." << endl;
            }

            printArray(arr, size);
            printBars(arr, size);

            cout << endl;
        }
    }

    cout << "\n=====================================\n";
    cout << "Bubble Sort Completed!\n";
    cout << "=====================================\n";

    cout << "\nSorted Array:\n";
    printArray(arr, size);

    cout << "\nStatistics\n";
    cout << "Comparisons : " << comparisons << endl;
    cout << "Swaps       : " << swaps << endl;

    cout << "\nTime Complexity\n";
    cout << "Best Case    : O(n)\n";
    cout << "Average Case : O(n^2)\n";
    cout << "Worst Case   : O(n^2)\n";

    cout << "\nSpace Complexity : O(1)\n";
}

void Sorting::selectionSort(int arr[], int size)
{
    int comparisons = 0;
    int swaps = 0;

    cout << "\n===== SELECTION SORT STARTED =====\n";

    for(int i = 0; i < size - 1; i++)
    {
        int minIndex = i;

        cout << "\n---------------------------------\n";
        cout << "Pass " << i + 1 << endl;

        for(int j = i + 1; j < size; j++)
        {
            comparisons++;

            cout << "\nComparing " << arr[minIndex]
                 << " and " << arr[j] << endl;

            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
                cout << "New Minimum Found!" << endl;
            }

            printArray(arr, size);
            printBars(arr, size);

            cout << endl;
        }

        if(minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;

            swaps++;

            cout << "Swapped " << arr[minIndex]
                 << " with " << arr[i] << endl;

            printArray(arr, size);
            printBars(arr, size);
        }
    }

    cout << "\n=====================================\n";
    cout << "Selection Sort Completed!\n";
    cout << "=====================================\n";

    cout << "\nSorted Array:\n";
    printArray(arr, size);

    cout << "\nStatistics\n";
    cout << "Comparisons : " << comparisons << endl;
    cout << "Swaps       : " << swaps << endl;

    cout << "\nTime Complexity\n";
    cout << "Best Case    : O(n^2)\n";
    cout << "Average Case : O(n^2)\n";
    cout << "Worst Case   : O(n^2)\n";

    cout << "\nSpace Complexity : O(1)\n";
}

void Sorting::insertionSort(int arr[], int size)
{
    int comparisons = 0;
    int shifts = 0;

    cout << "\n===== INSERTION SORT STARTED =====\n";

    for(int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        cout << "\n---------------------------------\n";
        cout << "Pass " << i << endl;
        cout << "Key = " << key << endl;

        while(j >= 0 && arr[j] > key)
        {
            comparisons++;

            arr[j + 1] = arr[j];
            shifts++;

            j--;

            printArray(arr, size);
            printBars(arr, size);

            cout << endl;
        }

        if(j >= 0)
            comparisons++;

        arr[j + 1] = key;

        cout << "Inserted " << key << " at position " << j + 1 << endl;

        printArray(arr, size);
        printBars(arr, size);
    }

    cout << "\n=====================================\n";
    cout << "Insertion Sort Completed!\n";
    cout << "=====================================\n";

    cout << "\nSorted Array:\n";
    printArray(arr, size);

    cout << "\nStatistics\n";
    cout << "Comparisons : " << comparisons << endl;
    cout << "Shifts      : " << shifts << endl;

    cout << "\nTime Complexity\n";
    cout << "Best Case    : O(n)\n";
    cout << "Average Case : O(n^2)\n";
    cout << "Worst Case   : O(n^2)\n";

    cout << "\nSpace Complexity : O(1)\n";
}

void Sorting::mergeSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);

        cout << "\nMerged Array:\n";
        printArray(arr, right + 1);
        printBars(arr, right + 1);
    }
}

void Sorting::merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[20], R[20];

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for(int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0;
    int j = 0;
    int k = left;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }

        k++;
    }

    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void Sorting::quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pivot = partition(arr, low, high);

        cout << "\nPivot Positioned: " << arr[pivot] << endl;
        printArray(arr, 10);
        printBars(arr, 10);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int Sorting::partition(int arr[], int low, int high)
{
    int pivot = arr[high];

    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}