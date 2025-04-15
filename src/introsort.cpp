// introsort.cpp
#include "sorting_algorithms.h"
#include <vector>
#include <cmath>
#include <algorithm>
#include <stdexcept>
using namespace std;

// 작은 구간에 대한 Insertion Sort
static void insertionSortRangeIdx(vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= left && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// Quick Sort에 사용될 median-of-three pivot 선택 기능 (여기서 정의하고 introsort 구현 파일에서 재사용)
static int choosePivot(vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;
    if(arr[mid] < arr[low])
        swap(arr[low], arr[mid]);
    if(arr[high] < arr[low])
        swap(arr[low], arr[high]);
    if(arr[high] < arr[mid])
        swap(arr[mid], arr[high]);
    swap(arr[mid], arr[high]);
    return arr[high];
}

static int partitionIdx(vector<int>& arr, int low, int high) {
    int pivot = choosePivot(arr, low, high);
    int i = low - 1;
    for (int j = low; j < high; j++){
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

static void introsortUtil(vector<int>& arr, int begin, int end, int depthLimit) {
    int size = end - begin + 1;
    if (size < 16) {
        insertionSortRangeIdx(arr, begin, end);
        return;
    }
    if (depthLimit == 0) {
        // 깊이가 너무 깊으면 Heap Sort로 대체 (heapSort는 heap_sort.cpp에 구현됨)
        vector<int> sub(arr.begin() + begin, arr.begin() + end + 1);
        heapSort(sub);
        copy(sub.begin(), sub.end(), arr.begin() + begin);
        return;
    }
    int pivot = partitionIdx(arr, begin, end);
    introsortUtil(arr, begin, pivot - 1, depthLimit - 1);
    introsortUtil(arr, pivot + 1, end, depthLimit - 1);
}

void introsort(vector<int>& arr) {
    int n = arr.size();
    if(n <= 1) return;
    int depthLimit = 2 * static_cast<int>(log(n));
    introsortUtil(arr, 0, n - 1, depthLimit);
}
