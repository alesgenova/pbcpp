#include <Eigen/Core>
#include "base/DirectCell.hpp"
#include "base/ReciprocalCell.hpp"
#include "constants/Constants.hpp"
#include "utils.hpp"

DirectCell getOrthoDirectCell(double a, double b, double c){
  Eigen::Matrix3d lattice;
  lattice <<  a,  0., 0.,
              0., b,  0.,
              0., 0., c ;
  return DirectCell(lattice);
}

ReciprocalCell getOrthoReciprocalCell(double a, double b, double c){
  Eigen::Matrix3d lattice;
  lattice <<  TWOPI/a,  0., 0.,
              0., TWOPI/b,  0.,
              0., 0., TWOPI/c ;
  return ReciprocalCell(lattice);
}

bool almostEqual(double a, double b, double thr){
  return abs(a-b) < thr;
}

double randomBetween(double start, double stop){
  const double delta = stop - start;
  return start + delta*((double) rand() / (RAND_MAX));
}