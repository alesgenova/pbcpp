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

Coord Coord::toCart() const{
  Coord newCoord;
  if (basis=='r'){
    newCoord = Coord(pos, cell, basis);
  }else{
    Eigen::Vector3d newPos;
    newPos = cell.getLattice()*pos; // thank you Eigen :D
    newCoord = Coord(newPos, cell, 'r');
  }
  return newCoord;
}

Coord Coord::toCrys() const{
  Coord newCoord;
  if (basis=='s'){
    newCoord = Coord(pos, cell, basis);
  }else{
    Eigen::Matrix3d bg;
    Eigen::Vector3d newPos;
    bg = cell.getLattice().inverse();
    newPos = bg*pos; // thank you Eigen :D
    newCoord = Coord(newPos, cell, 's');
  }
  return newCoord;
}

Coord Coord::toBasis(char basis) const{
  if (basis=='r'){
    return toCart();
  }else{
    return toCrys();
  }
}


Coord Coord::d_MIC(const Coord &other) const{
    return Coord();
}

double Coord::dd_MIC(const Coord &other) const{
    return 0.;
}