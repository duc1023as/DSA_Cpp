cmake_minimum_required(VERSION 3.10)

project(DSA_CPP)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_subdirectory(application)
add_subdirectory(LinkedList)

