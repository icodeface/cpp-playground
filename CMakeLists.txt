cmake_minimum_required(VERSION 3.14)
project(cpp_playground)

set(CMAKE_CXX_STANDARD 14)

include_directories(digestpp)

add_executable(cpp_playground
        main.cpp
        blake2b/blake2.h
        blake2b/blake2-impl.h
        blake2b/blake2b-ref.c
        pointer_struct/size_offset.cpp
        pointer_struct/size_offset.h
        )