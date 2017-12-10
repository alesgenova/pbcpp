#include <iostream>
#include <Eigen/Dense>
#include "base.h"

Cell::Cell(){
  std::cout << "Creating a default cell" << std::endl;
  //at = Eigen::Matrix3d(0.);
  at << 1., 0., 0.,
        0., 1., 0.,
        0., 0., 1.;
  //at = 3.0;
  //at(0,0) = 1.0;
  //at(1,1) = 1.0;
  //at(2,2) = 1.0;
}

Cell::~Cell(){

}

Eigen::Matrix3d Cell::lattice() const{
  return at;
}

Eigen::Matrix3d Cell::rlattice() const{
  return bg;
}