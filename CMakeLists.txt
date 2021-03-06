cmake_minimum_required(VERSION 3.16)
project(smid_matrix CXX)

include(CheckCXXCompilerFlag)
set(CMAKE_CXX_STANDARD 17)
option(OPTIMIZE_FOR_NATIVE "Build with -march=native" ON)
option(USE_CLANG "Build with clang instead of gcc" ON)
option(WITH_AVX512 "Enable AVX512" OFF)
option(WITH_MANUAL "Enable MANUAL" ON)

if(WITH_AVX512)
    add_compile_definitions(WITH_AVX512)
endif()
if(WITH_MANUAL)
    add_compile_definitions(WITH_MANUAL)
endif()

if(USE_CLANG)
    set(CMAKE_CXX_COMPILER "clang++")
else()
    set(CMAKE_CXX_COMPILER "g++")
endif()

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -O3")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mfma")

if(OPTIMIZE_FOR_NATIVE)
    CHECK_CXX_COMPILER_FLAG("-march=native" COMPILER_SUPPORTS_MARCH_NATIVE)
    if(COMPILER_SUPPORTS_MARCH_NATIVE)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
    else()
        error(FATAL_ERROR "-march=native not supported")
    endif()
else()
    CHECK_CXX_COMPILER_FLAG("-march=native" COMPILER_SUPPORTS_MARCH_NATIVE)
    if(COMPILER_SUPPORTS_MARCH_NATIVE)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
    else()
        error(FATAL_ERROR "-march=native not supported")
    endif()
endif()

set(BLA_VENDER OpenBLAS)
find_package(BLAS REQUIRED)
if(BLAS_FOUND)
    include_directories(${BLAS_INCLUDE_DIRS})
ELSE()
    message("OpenBLAS NOT found.")
endif(BLAS_FOUND)

find_package(Boost REQUIRED COMPONENTS filesystem program_options)

include_directories("${Boost_INCLUDE_DIRS} ${BLAS_INCLUDE_DIRS}")

add_library(simple_matrix src/Matrix.cpp)
target_link_libraries(simple_matrix ${Boost_LIBRARIES} ${BLAS_LIBRARIES})

add_executable(simd_multiply src/main.cpp)
target_link_libraries(simd_multiply simple_matrix)

add_executable(generate_random src/generate_random.cpp)
target_link_libraries(generate_random simple_matrix)
