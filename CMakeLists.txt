cmake_minimum_required(VERSION 3.12)
project(HammingDistance VERSION 1.0)

add_library(
    header
    hamming_distance.h
    hamming_distance.c
)

add_executable(hamming_distance hamming_distance.c)

target_link_libraries(hamming_distance PRIVATE header)

