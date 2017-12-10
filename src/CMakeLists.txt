cmake_minimum_required(VERSION 3.5)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

project(pbcpp)

if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_executable(
    sample
    main.cpp
    base.h
    base.cpp
)
target_link_libraries (sample Eigen3::Eigen)