#!/usr/bin/python
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


def compile_and_run(source_path, build_path_prefix, target, native, use_clang, args):
    flags = [
        "-DOPTIMIZE_FOR_NATIVE=" + ("ON" if native else "OFF"),
        "-DCMAKE_BUILD_TYPE=RelWithDebInfo",
        "-DUSE_CLANG=" + ("ON" if use_clang else "OFF"),
        "-DNDEBUG=ON", "-DBOOST_UBLAS_NDEBUG=ON"
    ]
    build_path = os.path.join(build_path_prefix, " ".join(flags))
    os.makedirs(build_path, exist_ok=True)
    check_call_quiet(["cmake", "-B", build_path, "-S", source_path] + flags)
    check_call_quiet(["make", target], cwd=build_path)
    if False:
        subprocess.check_call(["perf", "stat", "-B", "-e", "cache-references,cache-misses,cycles,instructions,branches,faults,migrations"]
                              + [os.path.join(build_path, target)] + args)
    else:
        print(" ".join([os.path.join(build_path, target)] + args))
        output = subprocess.check_output([os.path.join(build_path, target)] + args)
        return output



if __name__ == '__main__':
    os.chdir(os.path.join(os.path.dirname(__file__), ".."))
    os.makedirs("data", exist_ok=True)
    os.chdir("data")
    with_double = False
    extra_args = []#["--validate"]

    total = float(sys.argv[1] if len(sys.argv) > 1 else 1e8)
    sss= []
    i = pow(total, 1. / 3.)
    for _ in range(20):
        a = round(max(0.01 * i + 1, numpy.random.normal(i, i / 2)))
        b = round(max(0.01 * i + 1, numpy.random.normal(i, i / 2)))

        c = round(total / a / b)
        sss.append([str(a), str(b), str(c)])

    functions = ["block_wise_256_f", "block_wise_256_f2", "boost_axpy_mul",
                  "divide_and_conquer_block1", "divide_and_conquer_block2", "divide_and_conquer_naive_r3",
                  "blas"]
    if total < 1e10:
        functions.append("naive_reordered")
    times = [[] for f in functions]
    output_file = datetime.now().strftime("%Y.%m.%d_%H-%M-%S.json")
    for clang in [True]:
        for sizes in sss:
            args = list(sizes)
            if with_double:
                args.append("--double")
            compile_and_run("..", "builds", "generate_random", True, True, args)
            folder = "x".join(sizes)
            for fidx, function in enumerate(functions):
                arguments = [folder, "--algorithm", function]
                if with_double:
                    arguments.append("--double")
                output = compile_and_run("..", "builds", "simd_multiply", True, clang, arguments + extra_args)
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
                    "times": times,
                    "sizes": sss,
                    "functions": functions,
                    "means": ["%.3f" % numpy.mean(ts) for ts in times]
                }, f)
            os.rename(output_file + ".cache", output_file)