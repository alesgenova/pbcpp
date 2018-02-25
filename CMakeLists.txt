cmake_minimum_required(VERSION 3.5)

set(CMAKE_BUILD_TYPE "DEBUG")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

project(PBCPP)

if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
    #IF(CMAKE_BUILD_TYPE MATCHES DEBUG)
    #    add_compile_options(--coverage)
    #ENDIF(CMAKE_BUILD_TYPE MATCHES DEBUG)
    
endif()

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_subdirectory(src/pbcpp)
add_subdirectory(tests)
