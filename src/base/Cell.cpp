#include <iostream>
#include <Eigen/Dense>

#include "Cell.hpp"


BaseCell::BaseCell()
{
  /*
  lattice <<  1., 0., 0.,
              0., 1., 0.,
              0., 0., 1.;
  */
  lattice = Eigen::Matrix3d::Identity();
  volume = 1.0;
}

BaseCell::BaseCell(Eigen::Matrix3d t_lattice)
  : lattice{ t_lattice }
{
  volume = lattice.col(0).dot( lattice.col(1).cross(lattice.col(2)) );
}

BaseCell::~BaseCell(){}

Eigen::Matrix3d BaseCell::getLattice() const{
  return lattice;
}

double BaseCell::getVolume() const{
  return volume;
}

bool BaseCell::isEqual(const BaseCell & other) const{
  double eps{1.e-5};
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      if ( abs(lattice(i,j)-other.lattice(i,j)) > eps ){
        return false;
      }
    }
  }
  return true;
}