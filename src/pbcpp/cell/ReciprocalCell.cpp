#include <Eigen/Dense>

#include "BaseCell.hpp"
#include "DirectCell.hpp"
#include "ReciprocalCell.hpp"
#include "constants/Constants.hpp"


ReciprocalCell::ReciprocalCell(Eigen::Matrix3d t_lattice, Eigen::Vector3i t_shape) 
  : BaseCell(t_lattice, t_shape) {}

bool ReciprocalCell::operator==(const ReciprocalCell & other) const{
  return BaseCell::isEqual(other);
}

bool ReciprocalCell::operator!=(const ReciprocalCell & other) const{
  return !(*this==other);
}

DirectCell ReciprocalCell::getDirect() const{
  Eigen::Matrix3d at;
  at = TWOPI*lattice.inverse();
  return DirectCell(at, shape);
}
