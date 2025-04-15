// quick_sort.cpp
#include "sorting_algorithms.h"
#include <vector>
#include <stdexcept>
#include <algorithm>
using namespace std;

static int choosePivot(vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;
    if(arr[mid] < arr[low]) swap(arr[low], arr[mid]);
    if(arr[high] < arr[low]) swap(arr[low], arr[high]);
    if(arr[high] < arr[mid]) swap(arr[mid], arr[high]);
    swap(arr[mid], arr[high]);
    return arr[high];
}

static int partition(vector<int>& arr, int low, int high) {
    int pivot = choosePivot(arr, low, high);
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

static void quickSortHelper(vector<int>& arr, int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

void quickSort(vector<int>& arr) {
    if(arr.empty()) return;
    quickSortHelper(arr, 0, static_cast<int>(arr.size()) - 1);
}
