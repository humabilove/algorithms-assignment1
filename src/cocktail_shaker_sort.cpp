// cocktail_shaker_sort.cpp
#include "sorting_algorithms.h"
#include <vector>
using namespace std;

void cocktailShakerSort(vector<int>& arr) {
    int n = arr.size();
    if(n <= 1) return;
    int start = 0, end = n - 1;
    bool swapped = true;
    while(swapped) {
        swapped = false;
        for (int i = start; i < end; i++) {
            if(arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
                swapped = true;
            }
        }
        if(!swapped) break;
        end--;
        swapped = false;
        for (int i = end; i > start; i--) {
            if(arr[i-1] > arr[i]) {
                swap(arr[i-1], arr[i]);
                swapped = true;
            }
        }
        start++;
    }
}
