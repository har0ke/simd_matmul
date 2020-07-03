#!/usr/bin/python
import argparse
import json
import os
import shutil
import subprocess
import sys
from datetime import datetime
from pprint import pprint

import numpy


def check_call_quiet(*args, **kwargs):
    p = subprocess.Popen(*args, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, **kwargs)
    output, err = p.communicate()
    rc = p.returncode
    if rc != 0:
        print(output.decode())
        print(err)
        exit(0)


def compile_and_run(source_path, build_path_prefix, target, native, use_clang, avx512, args):
    flags = [
        "-DOPTIMIZE_FOR_NATIVE=" + ("ON" if native else "OFF"),
        "-DCMAKE_BUILD_TYPE=RelWithDebInfo",
        "-DUSE_CLANG=" + ("ON" if use_clang else "OFF"),
        "-DNDEBUG=ON", "-DBOOST_UBLAS_NDEBUG=ON",
        "-DWITH_AVX512=" + ("ON" if avx512 else "OFF"),
    ]
    build_path = os.path.join(build_path_prefix, " ".join(flags))
    if not os.path.exists(build_path):
        os.makedirs(build_path)
    check_call_quiet(["cmake", "-B", build_path, "-S", source_path] + flags)
    check_call_quiet(["make", target], cwd=build_path)
    if False:
        subprocess.check_call(["perf", "stat", "-B", "-e", "cache-references,cache-misses,cycles,instructions,branches,faults,migrations"]
                              + [os.path.join(build_path, target)] + args)
    else:
        print(" ".join([os.path.join(build_path, target)] + args))
        output = subprocess.check_output([os.path.join(build_path, target)] + args)
        return output

very_slow_functions = ["naive_reordered", "divide_and_conquer_naive_r4", "divide_and_conquer_naive_r2", "divide_and_conquer_naive_r1"]
slow_functions = ["boost_axpy_mul", "divide_and_conquer_naive_r3", "divide_and_conquer_naive_r5"]
normal_functions = ["block_wise_avx2"]
fast_functions = ["divide_and_conquer_block_avx2", "blas"]
avx512_functions = ["block_wise_avx512", "divide_and_conquer_block_avx512"]

if __name__ == '__main__':
    os.chdir(os.path.join(os.path.dirname(__file__), ".."))
    if not os.path.exists("data"):
        os.makedirs("data")
    os.chdir("data")
    with_double = False

    parser = argparse.ArgumentParser()
    parser.add_argument("total_size", type=float)
    parser.add_argument("--very_slow", action="store_true")
    parser.add_argument("--slow", action="store_true")
    parser.add_argument("--normal", action="store_true")
    parser.add_argument("--avx512", action="store_true")
    parser.add_argument("--validate", action="store_true")
    parser.add_argument("--double", action="store_true")
    parser.add_argument("--function", type=str, nargs="*")

    options = parser.parse_args()

    functions = fast_functions

    if options.very_slow:
        functions += very_slow_functions

    if options.very_slow or options.slow:
        functions += slow_functions

    if options.very_slow or options.slow or options.normal:
        functions += normal_functions

    if options.avx512:
        functions += avx512_functions

    if options.function:
        functions = options.function

    extra_args = []
    if options.validate:
        extra_args.append("--validate")
    if options.double:
        extra_args.append("--double")

    total = options.total_size
    matrix_combinations = []
    i = pow(total, 1. / 3.)
    for _ in range(20):
        a = int(round(max(0.01 * i + 1, numpy.random.normal(i, i / 2))))
        b = int(round(max(0.01 * i + 1, numpy.random.normal(i, i / 2))))
        c = int(round(total / a / b))
        matrix_combinations.append([str(a), str(b), str(c)])

    times = [[] for f in functions]
    output_file = datetime.now().strftime("%Y.%m.%d_%H-%M-%S.json")
    for clang in [True]:
        for sizes in matrix_combinations:
            args = list(sizes)
            compile_and_run("..", "builds", "generate_random", True, True, options.avx512, args)
            folder = "x".join(sizes)
            for fidx, function in enumerate(functions):
                arguments = [folder, "--algorithm", function]
                if with_double:
                    arguments.append("--double")
                output = compile_and_run("..", "builds", "simd_multiply", True, clang, options.avx512, arguments + extra_args)
                ms = output.decode()[output.decode().find("multiply:") + 10:]
                if "ms\n" in ms:
                    ms = float(ms.split("ms\n")[0])
                else:
                    ms = float(ms.split("s\n")[0]) * 1000
                times[fidx].append(ms)

            shutil.rmtree(folder)
            print(["%.3f" % numpy.mean(ts) for ts in times])
            with open(output_file + ".cache", "w") as f:
                json.dump({
                    "extr_args": extra_args,
                    "times": times,
                    "sizes": matrix_combinations,
                    "functions": functions,
                    "means": ["%.3f" % numpy.mean(ts) for ts in times]
                }, f)
            os.rename(output_file + ".cache", output_file)