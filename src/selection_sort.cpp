// selection_sort.cpp
#include "sorting_algorithms.h"
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    if(n <= 1) return;
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIdx])
                minIdx = j;
        }
        if(minIdx != i)
            swap(arr[i], arr[minIdx]);
    }
}
