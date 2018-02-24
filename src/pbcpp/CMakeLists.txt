add_library(
    pbcpp
    constants/Constants.hpp
    constants/Constants.cpp
    base/Cell.hpp
    base/Cell.cpp
)

target_include_directories (pbcpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries (pbcpp Eigen3::Eigen)