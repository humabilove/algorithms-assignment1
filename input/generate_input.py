#!/usr/bin/env python3
import random

def generate_ascending(n):
    return [i for i in range(1, n+1)]

def generate_descending(n):
    return [i for i in range(n, 0, -1)]

def generate_random(n):
    return [random.randint(0, n) for _ in range(n)]

def generate_partially_sorted(n, swap_fraction=0.1):
    arr = [i for i in range(1, n+1)]
    num_swaps = int(n * swap_fraction)
    for _ in range(num_swaps):
        idx1 = random.randint(0, n-1)
        idx2 = random.randint(0, n-1)
        arr[idx1], arr[idx2] = arr[idx2], arr[idx1]
    return arr

def write_to_file(data, filename):
    with open(filename, 'w') as f:
        for val in data:
            f.write(str(val) + '\n')

if __name__ == "__main__":
    # 예: 1,000 ~ 1,000,000 등 자유롭게 설정
    # Ascending
    asc_1k = generate_ascending(1000)
    write_to_file(asc_1k, "ascending_1k.txt")

    # Descending
    desc_10k = generate_descending(10000)
    write_to_file(desc_10k, "descending_10k.txt")

    # Random
    rand_100k = generate_random(100000)
    write_to_file(rand_100k, "random_100k.txt")

    # Partially Sorted
    part_1m = generate_partially_sorted(1000000, 0.1)
    write_to_file(part_1m, "partially_sorted_1M.txt")
    
    print("Text files generated successfully!")
