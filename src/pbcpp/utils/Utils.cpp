#include <cmath>

#include "Utils.hpp"

bool almostEqual(double a, double b, double thr){
  return abs(a-b) < thr;
}

double randomBetween(double start, double stop){
  const double delta = stop - start;
  return start + delta*((double) rand() / (RAND_MAX));
}