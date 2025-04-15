// sorting_algorithms.h
#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <vector>

// Merge Sort
void mergeSort(std::vector<int>& arr);

// Heap Sort
void heapSort(std::vector<int>& arr);

// Bubble Sort
void bubbleSort(std::vector<int>& arr);

// Insertion Sort
void insertionSort(std::vector<int>& arr);

// Selection Sort
void selectionSort(std::vector<int>& arr);

// Quick Sort (with median-of-three)
void quickSort(std::vector<int>& arr);

// Library Sort (with default alpha = 2.0)
void librarySort(std::vector<int>& arr, double alpha = 2.0);

// Tim Sort
void timSort(std::vector<int>& arr);

// Cocktail Shaker Sort
void cocktailShakerSort(std::vector<int>& arr);

// Comb Sort
void combSort(std::vector<int>& arr);

// Tournament Sort
void tournamentSort(std::vector<int>& arr);

// Introsort
void introsort(std::vector<int>& arr);

#endif // SORTING_ALGORITHMS_H
