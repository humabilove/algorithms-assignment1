// insertion_sort.cpp
#include "sorting_algorithms.h"
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    if(n <= 1) return;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
