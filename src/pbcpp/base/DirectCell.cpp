#include <Eigen/Dense>

#include "BaseCell.hpp"
#include "DirectCell.hpp"
#include "ReciprocalCell.hpp"
#include "../constants/Constants.hpp"

DirectCell::DirectCell() : BaseCell() {}

DirectCell::DirectCell(Eigen::Matrix3d t_lattice) : BaseCell(t_lattice) {}

ReciprocalCell DirectCell::getReciprocal() const{
  Eigen::Matrix3d bg;
  bg = TWOPI*lattice.inverse();
  bg.transposeInPlace();
  return ReciprocalCell(bg);
}