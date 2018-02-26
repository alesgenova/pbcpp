

add_library(
    pbcpp
    SHARED
    utils/Utils.hpp
    utils/Utils.cpp
    constants/Constants.hpp
    constants/Constants.cpp
    cell/BaseCell.hpp
    cell/BaseCell.cpp
    cell/DirectCell.hpp
    cell/DirectCell.cpp
    cell/ReciprocalCell.hpp
    cell/ReciprocalCell.cpp
    coord/Coord.hpp
    coord/Coord.cpp
)

target_include_directories (pbcpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries (pbcpp Eigen3::Eigen)