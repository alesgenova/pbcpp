add_executable (
  unittests
  catch.hpp
  main.cpp
  utils.cpp
  test_cell.cpp
  test_coord.cpp
  test_grid.cpp
)

target_link_libraries (unittests LINK_PUBLIC pbcpp Eigen3::Eigen)
