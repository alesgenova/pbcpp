#ifndef PBCPP_TESTS_UTILS
#define PBCPP_TESTS_UTILS

#include "base/DirectCell.hpp"

extern DirectCell getOrthorombicCell(double a, double b, double c);

extern bool almostEqual(double a, double b, double thr=1.e-6);

#endif // PBCPP_TESTS_UTILS