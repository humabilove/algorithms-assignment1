#!/usr/bin/env python3
import subprocess
import sys

def run_benchmark(executable, output_file):
    try:
        # 실행 파일을 실행하여 결과 캡처
        result = subprocess.run(["./" + executable], capture_output=True, text=True, check=True)
        with open(output_file, "w") as f:
            f.write(result.stdout)
        print("Benchmark completed. Results saved to", output_file)
    except subprocess.CalledProcessError as e:
        print("Error during benchmark execution:", e)
        sys.exit(1)

if __name__ == '__main__':
    executable = "../sorting_benchmark"
    output_file = "../output/benchmark_results.txt"
    run_benchmark(executable, output_file)