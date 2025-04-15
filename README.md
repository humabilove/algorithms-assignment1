# algorithms-assignment1 (20191333 황건희)

# Sorting Algorithms Benchmark

This repository contains a comparison of 12 sorting algorithms implemented in C++.
It includes classical sorting methods and advanced algorithms with optimized implementations and robust error handling.

## Repository Structure
algorithms-assignment1/
├── README.md ← This file
├── Makefile ← Build script 
├── src/ ← C++ source files 
│ ├── main.cpp ← Main benchmark runner (contains all sorting functions) 
│ ├── merge_sort.cpp ← Merge Sort implementation 
│ ├── heap_sort.cpp ← Heap Sort implementation 
│ ├── bubble_sort.cpp ← Bubble Sort implementation 
│ ├── insertion_sort.cpp ← Insertion Sort implementation 
│ ├── selection_sort.cpp ← Selection Sort implementation 
│ ├── quick_sort.cpp ← Quick Sort with median-of-three pivot 
│ ├── library_sort.cpp ← Library Sort implementation 
│ ├── tim_sort.cpp ← Tim Sort implementation 
│ ├── cocktail_shaker_sort.cpp ← Cocktail Shaker Sort 
│ ├── comb_sort.cpp ← Comb Sort implementation 
│ ├── tournament_sort.cpp← Tournament Sort implementation 
│ └── introsort.cpp ← Introsort implementation 
├── input/ ← Input dataset files 
│ ├── ascending_1k.txt
│ ├── descending_10k.txt 
│ ├── random_100k.txt
│ └── partially_sorted_1M.txt 
├── output/ ← (Optional) Output files (benchmark results, etc.) 
│ └── benchmark_results.txt └── scripts/
└── benchmark_runner.py ← Script to run benchmarks and save output


## How to Build and Run

### Using Makefile
Run the following command in the terminal from the project root:
$ make

This will compile the source code from the src/ directory and produce an executable named sorting_benchmark.

Then run:
./sorting_benchmark
