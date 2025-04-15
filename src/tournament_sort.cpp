// tournament_sort.cpp
#include "sorting_algorithms.h"
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

void tournamentSort(vector<int>& arr) {
    int n = arr.size();
    if(n <= 1) return;
    int N = 1;
    while(N < n) N *= 2;
    vector<int> tree(2 * N, numeric_limits<int>::max());
    for (int i = 0; i < n; i++)
        tree[N + i] = arr[i];
    for (int i = n; i < N; i++)
        tree[N + i] = numeric_limits<int>::max();
    for (int i = N - 1; i > 0; i--)
        tree[i] = min(tree[2*i], tree[2*i+1]);
    vector<int> sorted;
    sorted.reserve(n);
    for (int i = 0; i < n; i++) {
        int minVal = tree[1];
        sorted.push_back(minVal);
        int idx = 1;
        while(idx < N) {
            if(tree[2*idx] == minVal)
                idx = 2*idx;
            else
                idx = 2*idx + 1;
        }
        tree[idx] = numeric_limits<int>::max();
        idx /= 2;
        while(idx >= 1) {
            tree[idx] = min(tree[2*idx], tree[2*idx+1]);
            idx /= 2;
        }
    }
    arr = sorted;
}
