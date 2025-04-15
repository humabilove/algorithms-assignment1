// tim_sort.cpp
#include "sorting_algorithms.h"
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// 내부 범위에 대한 Insertion Sort
static void insertionSortRange(vector<int>& arr, int left, int right) {
    for (int i = left+1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= left && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void timSort(vector<int>& arr) {
    int n = arr.size();
    if(n <= 1) return;
    const int RUN = 32;
    for (int i = 0; i < n; i += RUN)
        insertionSortRange(arr, i, min(i+RUN-1, n-1));
    for (int size = RUN; size < n; size *= 2) {
        for (int left = 0; left < n; left += 2*size) {
            int mid = left + size - 1;
            int right = min(left + 2*size - 1, n-1);
            if(mid < right) {
                // 재사용: merge 함수는 merge_sort.cpp에 구현된 함수와 동일하게 동작
                int n1 = mid - left + 1, n2 = right - mid;
                vector<int> L(n1), R(n2);
                for (int i = 0; i < n1; i++)
                    L[i] = arr[left+i];
                for (int j = 0; j < n2; j++)
                    R[j] = arr[mid+1+j];
                int i = 0, j = 0, k = left;
                while (i < n1 && j < n2) {
                    if (L[i] <= R[j])
                        arr[k++] = L[i++];
                    else
                        arr[k++] = R[j++];
                }
                while(i < n1) arr[k++] = L[i++];
                while(j < n2) arr[k++] = R[j++];
            }
        }
    }
}
