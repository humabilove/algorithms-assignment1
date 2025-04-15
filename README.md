# CSE331 Sorting Algorithm Benchmark

## Overview
This repository contains an extensive implementation of **12 sorting algorithms** (6 basic and 6 advanced) in C++, along with a benchmarking suite. The purpose of this project is to compare each algorithm’s performance on various dataset sizes (1,000 ~ 1,000,000) and data distributions (Ascending, Descending, Random, Partially Sorted). 

## Project Structure
├── README.md                         # This file
├── Makefile                          # Build configuration
├── scripts
│   ├── benchmark_runner.py           # Python script to run the benchmarking executable
│   └── visualize.py                  # (Optional) script for creating charts from results
├── src
│   ├── main.cpp                      # Main driver for benchmarking
│   ├── merge_sort.cpp               # Separate implementation of each sorting algorithm
│   ├── quick_sort.cpp
│   ├── ...
│   └── introsort.cpp
├── input
│   ├── random_1k.txt                # Example input data file(s)
│   ├── descending_10k.txt
│   └── ...
├── output
│   ├── benchmark_results.txt        # Collected benchmark results


## Implemented Algorithms
1. **Merge Sort**  
2. **Heap Sort**  
3. **Bubble Sort**  
4. **Insertion Sort**  
5. **Selection Sort**  
6. **Quick Sort**  
7. **Library Sort**  
8. **Tim Sort**  
9. **Cocktail Shaker Sort**  
10. **Comb Sort**  
11. **Tournament Sort**  
12. **Introsort**

Each algorithm is located in its own `.cpp` file under the `src` directory and is callable from `main.cpp` through function pointers.

## How to Build and Run

### Prerequisites
- A C++ compiler supporting **C++11** or higher
- (Optional) Python 3 + `matplotlib` if you wish to use the visualization scripts

### Using Makefile
1. From the project root directory, run:
   ```bash
   make
   ```
2. This will produce an executable named `sorting_benchmark` (or similar, depending on your Makefile).
3. Execute the compiled program:
   ```bash
   ./sorting_benchmark
   ```
   It will automatically run all algorithms on each data set, repeating 10 times, and print the average times to the console (or to a file, if so configured).

### Using benchmark_runner.py
Alternatively, if you want an automated script:
1. Ensure you have Python 3 installed.
2. Run:
   ```bash
   cd scripts
   python benchmark_runner.py
   ```
   The script may call the compiled `sorting_benchmark` executable and capture/redirect output to `output/benchmark_results.txt`.

## Usage
1. Modify the data sizes or input distributions in `main.cpp` (or in the Python script) as needed.
2. Recompile using `make`.
3. Run the program to generate updated benchmark results.

