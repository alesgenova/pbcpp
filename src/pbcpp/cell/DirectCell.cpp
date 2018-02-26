#include <Eigen/Dense>

#include "BaseCell.hpp"
#include "DirectCell.hpp"
#include "ReciprocalCell.hpp"
#include "constants/Constants.hpp"


DirectCell::DirectCell(Eigen::Matrix3d t_lattice, Eigen::Vector3i t_shape)
  : BaseCell(t_lattice, t_shape) {}

bool DirectCell::operator==(const DirectCell & other) const{
  return BaseCell::isEqual(other);
}

bool DirectCell::operator!=(const DirectCell & other) const{
  return !(*this==other);
}

ReciprocalCell DirectCell::getReciprocal() const{
  Eigen::Matrix3d bg;
  bg = TWOPI*lattice.inverse();
  bg.transposeInPlace();
  return ReciprocalCell(bg, shape);
}
