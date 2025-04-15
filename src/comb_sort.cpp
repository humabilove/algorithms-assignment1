// comb_sort.cpp
#include "sorting_algorithms.h"
#include <vector>
#include <algorithm>
using namespace std;

void combSort(vector<int>& arr) {
    int n = arr.size();
    if(n <= 1) return;
    int gap = n;
    const double shrink = 1.3;
    bool sorted = false;
    while(gap > 1 || !sorted) {
        gap = max(1, static_cast<int>(gap / shrink));
        sorted = true;
        for (int i = 0; i + gap < n; i++) {
            if(arr[i] > arr[i+gap]) {
                swap(arr[i], arr[i+gap]);
                sorted = false;
            }
        }
    }
}
