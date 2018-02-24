#include <Eigen/Dense>

#include "BaseCell.hpp"
#include "DirectCell.hpp"
#include "ReciprocalCell.hpp"
#include "../constants/Constants.hpp"


ReciprocalCell::ReciprocalCell() : BaseCell() {}

ReciprocalCell::ReciprocalCell(Eigen::Matrix3d t_lattice) : BaseCell(t_lattice) {}

DirectCell ReciprocalCell::getDirect() const{
  Eigen::Matrix3d at;
  at = TWOPI*lattice.inverse();
  return DirectCell(at);
}
