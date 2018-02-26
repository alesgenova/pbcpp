#include <Eigen/Dense>
#include "BaseCell.hpp"


BaseCell::BaseCell(Eigen::Matrix3d t_lattice, Eigen::Vector3i t_shape)
  : lattice{ t_lattice }
  , shape{ t_shape }
{
  volume = lattice.col(0).dot( lattice.col(1).cross(lattice.col(2)) );
  nnr = shape[0]*shape[1]*shape[2];
  dv = volume / nnr;
}

BaseCell::~BaseCell(){}

Eigen::Matrix3d BaseCell::getLattice() const{
  return lattice;
}

double BaseCell::getVolume() const{
  return volume;
}

double BaseCell::getDv() const{
  return dv;
}

Eigen::Vector3i BaseCell::getShape() const{
  return shape;
}

int BaseCell::getNnr() const{
  return nnr;
}

bool BaseCell::isEqual(const BaseCell & other) const{
  //double eps{1.e-5};
  // check the lattice vectors
  for (int i = 0; i < 3; i++){
    if (!lattice.col(i).isApprox(other.getLattice().col(i))){
      return false;
    }
  }
  return true;
}
