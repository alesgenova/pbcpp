add_executable (
  unittests
  catch.hpp
  main.cpp
  utils.cpp
  test_base.cpp
)

target_link_libraries (unittests LINK_PUBLIC pbcpp Eigen3::Eigen)
