add_library(
    pbcpp
    constants/Constants.hpp
    constants/Constants.cpp
    base/BaseCell.hpp
    base/BaseCell.cpp
    base/DirectCell.hpp
    base/DirectCell.cpp
    base/ReciprocalCell.hpp
    base/ReciprocalCell.cpp
    base/Coord.hpp
    base/Coord.cpp
)

target_include_directories (pbcpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries (pbcpp Eigen3::Eigen)