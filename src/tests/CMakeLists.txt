add_executable (sample test.cpp)

target_link_libraries (sample LINK_PUBLIC pbcpp Eigen3::Eigen)