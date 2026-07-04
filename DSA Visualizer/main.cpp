#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

#include "Sorting.h"
#include "Utils.h"

using namespace std;

int main()
{
    srand(time(0));

    Sorting sort;

    int choice;

    const int SIZE = 10;

    int arr[SIZE];

    generateRandomArray(arr, SIZE);

    do
    {
        cout << "\n=============================================\n";
        cout << "   DATA STRUCTURES & ALGORITHMS VISUALIZER\n";
        cout << "=============================================\n";

        cout << "\nCurrent Array:\n";
        printArray(arr, SIZE);

        cout << endl;

        printBars(arr, SIZE);

        cout << "\nWelcome to the Data Structures and Algorithms Visualizer\n";
        cout << "This project demonstrates the working of different sorting algorithms.\n\n";
        cout << "\n1. Bubble Sort";
        cout << "\n2. Selection Sort";
        cout << "\n3. Insertion Sort";
        cout << "\n4. Merge Sort";
        cout << "\n5. Quick Sort";
        cout << "\n6. Generate New Array";
        cout << "\n7. About Project";
        cout << "\n8. Exit";

        cout << "\n\nEnter Choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                sort.bubbleSort(arr, SIZE);
                break;

            case 2:
                sort.selectionSort(arr, SIZE);
                break;

            case 3:
                sort.insertionSort(arr, SIZE);
                break;

            case 4:
                sort.mergeSort(arr, 0, SIZE - 1);
                break;

            case 5:
                sort.quickSort(arr, 0, SIZE - 1);
                break;

            case 6:
                generateRandomArray(arr, SIZE);
                break;

            case 7:
                cout << "\n=====================================\n";
                cout << "        ABOUT THIS PROJECT\n";
                cout << "=====================================\n";

                cout << "\nProject Name:\n";
                cout << "Data Structures and Algorithms Visualizer\n";

                cout << "\nLanguage Used:\n";
                cout << "C++\n";

                cout << "\nAlgorithms Implemented:\n";
                cout << "- Bubble Sort\n";
                cout << "- Selection Sort\n";
                cout << "- Insertion Sort\n";
                cout << "- Merge Sort\n";
                cout << "- Quick Sort\n";

                cout << "\nPurpose:\n";
                cout << "To help learners visually understand sorting algorithms step-by-step.\n";

                break;

            case 8:
                cout << "\nThank You!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 8);

    return 0;
}