#include <Eigen/Core>
#include <cmath>

#include "Coord.hpp"
#include "DirectCell.hpp"
#include "utils/Utils.hpp"


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

bool Coord::operator==(const Coord & other) const{
  if (cell != other.getCell()){
    // if two coordinates are represented on different cells they are not equal
    return false;
  }
  // if their distance using MIC is 0, then they are the same coordinate
  return almostEqual(dd_MIC(other), 0.0, 1.e-6);
}

bool Coord::operator!=(const Coord & other) const{
  return !(*this==other);
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
  if (cell != other.getCell()){
    throw std::invalid_argument( "The Cell of the two coordinates is not the same" );
  }
  Eigen::Vector3d d12s;
  d12s = other.toCrys().getPos() - toCrys().getPos();
  for (int i=0; i<3; i++){
    d12s[i] = d12s[i] - round(d12s[i]);
  }
  return Coord(d12s, cell, 's').toBasis(basis);
}

double Coord::dd_MIC(const Coord &other) const{
    Coord tmp;
    tmp = d_MIC(other).toCart();
    double d;
    d = tmp.getPos().dot(tmp.getPos());
    return sqrt(d);
}