#include <Eigen/Core>

#include "Coord.hpp"
#include "DirectCell.hpp"


Coord::Coord(Eigen::Vector3d t_pos, DirectCell t_cell, char t_basis)
  : pos{t_pos}
  , cell{t_cell}
  , basis{t_basis}
{
}

Eigen::Vector3d Coord::getPos() const{
  return pos;
}

DirectCell Coord::getCell() const{
  return cell;
}

char Coord::getBasis() const{
  return basis;
}