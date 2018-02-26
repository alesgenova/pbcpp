#ifndef PBCPP_TESTS_UTILS
#define PBCPP_TESTS_UTILS

#include <Eigen/Core>
#include "cell/DirectCell.hpp"

extern DirectCell getOrthoDirectCell(double a, double b, double c,
          Eigen::Vector3i shape=Eigen::Vector3i::Identity());

extern ReciprocalCell getOrthoReciprocalCell(double a, double b, double c,
          Eigen::Vector3i shape=Eigen::Vector3i::Identity());

#endif // PBCPP_TESTS_UTILS