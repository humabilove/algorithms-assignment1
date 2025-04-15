// main.cpp
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <functional>
#include <cmath>
#include <stdexcept>
#include <limits>
#include <sstream>
#include "sorting_algorithms.h"  // 정렬 알고리즘 함수 원형을 선언한 헤더

using namespace std;

// ===================================================
// Data Generation Functions (Robust with Exception Checks)
// ===================================================

vector<int> generateAscending(int n) {
    if(n <= 0) throw invalid_argument("generateAscending: n must be positive.");
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;
    return arr;
}

vector<int> generateDescending(int n) {
    if(n <= 0) throw invalid_argument("generateDescending: n must be positive.");
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = n - i;
    return arr;
}

vector<int> generateRandom(int n) {
    if(n <= 0) throw invalid_argument("generateRandom: n must be positive.");
    vector<int> arr(n);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, n);
    for (int i = 0; i < n; i++)
        arr[i] = dist(gen);
    return arr;
}

vector<int> generatePartiallySorted(int n, double swapFraction = 0.1) {
    if(n <= 0) throw invalid_argument("generatePartiallySorted: n must be positive.");
    if(swapFraction < 0 || swapFraction > 1)
        throw invalid_argument("generatePartiallySorted: swapFraction must be in [0,1].");
    vector<int> arr = generateAscending(n);
    int numSwaps = static_cast<int>(n * swapFraction);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, n - 1);
    for (int i = 0; i < numSwaps; i++) {
        int idx1 = dist(gen);
        int idx2 = dist(gen);
        swap(arr[idx1], arr[idx2]);
    }
    return arr;
}

// ===================================================
// Utility Function to Validate Sorted Output
// ===================================================
bool isSorted(const vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i-1] > arr[i])
            return false;
    }
    return true;
}

// ===================================================
// Benchmark Function: Run Sorting Function Repeatedly
// ===================================================
double benchmarkSort(function<void(vector<int>&)> sortFunc, const vector<int>& original, int repetitions = 10) {
    if(repetitions <= 0) throw invalid_argument("benchmarkSort: repetitions must be > 0.");
    double totalTime = 0.0;
    for (int i = 0; i < repetitions; i++) {
        vector<int> arr = original;  // 데이터 복사
        auto start = chrono::high_resolution_clock::now();
        try {
            sortFunc(arr);
        } catch (const exception &e) {
            ostringstream oss;
            oss << "Sort failed for algorithm in repetition " << i+1 << ": " << e.what();
            throw runtime_error(oss.str());
        }
        auto end = chrono::high_resolution_clock::now();
        double elapsed = chrono::duration<double, milli>(end - start).count();
        totalTime += elapsed;
        if(!isSorted(arr)) {
            ostringstream oss;
            oss << "Sort failed for algorithm in repetition " << i+1;
            throw runtime_error(oss.str());
        }
    }
    return totalTime / repetitions;
}

// ===================================================
// Main: Execute Benchmarks over Various Data Sets and Sizes
// ===================================================
int main() {
    try {
        ios::sync_with_stdio(false);
        cout.tie(nullptr);

        // 테스트할 데이터 크기를 정의 (예: 1K, 10K, 100K, 1M)
        vector<int> sizes = {1000, 10000, 100000, 1000000};

        // 각 데이터셋 종류와 대응하는 데이터 생성 함수들
        vector<pair<string, function<vector<int>(int)>>> datasetGenerators = {
            {"Ascending", [](int n){ return generateAscending(n); }},
            {"Descending", [](int n){ return generateDescending(n); }},
            {"Random", [](int n){ return generateRandom(n); }},
            {"Partially Sorted", [](int n){ return generatePartiallySorted(n, 0.1); }}
        };

        // 정렬 알고리즘 목록 (12개), 각 함수는 sorting_algorithms.h에서 선언된 함수를 사용
        vector<pair<string, function<void(vector<int>&)>>> sortingAlgorithms = {
            {"Merge Sort", mergeSort},
            {"Heap Sort", heapSort},
            {"Bubble Sort", bubbleSort},
            {"Insertion Sort", insertionSort},
            {"Selection Sort", selectionSort},
            {"Quick Sort", quickSort},
            {"Library Sort", [](vector<int>& arr){ librarySort(arr, 2.0); }},
            {"Tim Sort", timSort},
            {"Cocktail Shaker Sort", cocktailShakerSort},
            {"Comb Sort", combSort},
            {"Tournament Sort", tournamentSort},
            {"Introsort", introsort}
        };

        int repetitions = 10;  // 각 데이터셋별 테스트 횟수

        // 데이터 크기와 데이터 유형별로 각 정렬 알고리즘의 평균 실행 시간 측정 및 출력
        for (int size : sizes) {
            cout << "Dataset Size: " << size << "\n";
            for (auto& generator : datasetGenerators) {
                cout << "  Data Type: " << generator.first << "\n";
                vector<int> data = generator.second(size);
                for (auto& sortAlgo : sortingAlgorithms) {
                    double avgTime = benchmarkSort(sortAlgo.second, data, repetitions);
                    cout << "    " << sortAlgo.first << ": " << avgTime << " ms\n";
                }
                cout << "\n";
            }
            cout << "---------------------------------------\n";
        }
    } catch (const exception& e) {
        cerr << "Exception caught: " << e.what() << "\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
