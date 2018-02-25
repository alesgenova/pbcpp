#include <Eigen/Core>
#include "base/DirectCell.hpp"
#include "utils.hpp"

DirectCell getOrthorombicCell(double a, double b, double c){
  Eigen::Matrix3d lattice;
  lattice <<  a,  0., 0.,
              0., b,  0.,
              0., 0., c ;
  return DirectCell(lattice);
}

bool almostEqual(double a, double b, double thr){
  return abs(a-b) < thr;
}