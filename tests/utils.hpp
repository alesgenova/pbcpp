#ifndef PBCPP_TESTS_UTILS
#define PBCPP_TESTS_UTILS

#include "base/DirectCell.hpp"

extern DirectCell getOrthoDirectCell(double a, double b, double c);

extern ReciprocalCell getOrthoReciprocalCell(double a, double b, double c);

extern bool almostEqual(double a, double b, double thr=1.e-6);

extern double randomBetween(double low=0., double high=1.);

#endif // PBCPP_TESTS_UTILS