// bubble_sort.cpp
#include "sorting_algorithms.h"
#include <vector>
using namespace std;

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    if(n <= 1) return;
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < n - 1; i++) {
            if(arr[i] > arr[i+1]) {
                std::swap(arr[i], arr[i+1]);
                swapped = true;
            }
        }
        n--; 
    } while(swapped);
}
