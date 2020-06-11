#!/usr/bin/python
import os
import subprocess


def check_call_quiet(*args, **kwargs):
    p = subprocess.Popen(*args, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, **kwargs)
    output, err = p.communicate()
    rc = p.returncode
    if rc != 0:
        print(output)
        print(err)
        exit(0)


def compile_and_run(source_path, build_path_prefix, target, native, use_clang, args):
    flags = [
        "-DOPTIMIZE_FOR_NATIVE=" + ("ON" if native else "OFF"),
        "-DCMAKE_BUILD_TYPE=Release",
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
        subprocess.check_call([os.path.join(build_path, target)] + args)


if __name__ == '__main__':
    os.chdir(os.path.join(os.path.dirname(__file__), ".."))
    os.makedirs("data", exist_ok=True)
    os.chdir("data")
    with_double = False
    extra_args = ["--validate"]
    for clang in [True]:
        for sizes in [["2048", "2048", "999"]]:  # [["873", "1456", "999"]]:
            args = list(sizes)
            if with_double:
                args.append("--double")
            compile_and_run("..", "builds", "generate_random", True, True, args)
            folder = "x".join(sizes)
            for function in ["block_wise_256_f", "boost_axpy_mul"]:  # ["naive_reordered", "block_wise_256_f", "boost_blocked_mul_64", "boost_blocked_mul_256", "boost_mul", "boost_axpy_mul"]:
                arguments = [folder, "--algorithm", function]
                if with_double:
                    arguments.append("--double")
                compile_and_run("..", "builds", "simd_multiply", True, clang, arguments + extra_args)
