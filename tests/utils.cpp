#include <Eigen/Core>
#include "cell/DirectCell.hpp"
#include "cell/ReciprocalCell.hpp"
#include "constants/Constants.hpp"
#include "utils.hpp"

DirectCell getOrthoDirectCell(double a, double b, double c, Eigen::Vector3i shape){
  Eigen::Matrix3d lattice;
  lattice <<  a,  0., 0.,
              0., b,  0.,
              0., 0., c ;
  return DirectCell(lattice, shape);
}

ReciprocalCell getOrthoReciprocalCell(double a, double b, double c, Eigen::Vector3i shape){
  Eigen::Matrix3d lattice;
  lattice <<  TWOPI/a,  0., 0.,
              0., TWOPI/b,  0.,
              0., 0., TWOPI/c ;
  return ReciprocalCell(lattice, shape);
}
