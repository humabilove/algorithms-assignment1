// library_sort.cpp
#include "sorting_algorithms.h"
#include <vector>
#include <cmath>
#include <stdexcept>
#include <limits>
#include <algorithm>
using namespace std;

void librarySort(vector<int>& arr, double alpha) {
    if(arr.empty()) return;
    if(alpha < 1.0) throw invalid_argument("librarySort: alpha must be >= 1.0");
    int n = arr.size();
    int newSize = static_cast<int>(ceil(alpha * n));
    vector<int> B(newSize);
    int count = 0;
    B[0] = arr[0];
    count = 1;
    for (int i = 1; i < n; i++){
        int left = 0, right = count;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if(B[mid] < arr[i])
                left = mid + 1;
            else
                right = mid;
        }
        int pos = left;
        if(count == newSize)
            throw runtime_error("librarySort: Array full unexpectedly.");
        for (int j = count; j > pos; j--)
            B[j] = B[j - 1];
        B[pos] = arr[i];
        count++;
    }
    vector<int> sorted(B.begin(), B.begin() + count);
    if(sorted.size() != arr.size())
        throw runtime_error("librarySort: Insertion count mismatch.");
    arr = sorted;
}
