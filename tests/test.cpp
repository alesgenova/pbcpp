#include <iostream>

#include <Eigen/Core>
#include "base/DirectCell.hpp"
#include "base/ReciprocalCell.hpp"
#include "constants/Constants.hpp"


int main(){
  Eigen::Matrix3d at;
  at << 2., 0., 0.,
        0., 3., 0.,
        0., 0., 2.;
  DirectCell cell0{};

  DirectCell cell1(at);

  ReciprocalCell reciprocal1;
  reciprocal1 = cell1.getReciprocal();

  DirectCell cell2;
  cell2 = reciprocal1.getDirect();
  //at = cell.lattice();
  std::cout << "cell0's lattice:" << std::endl;
  std::cout << cell0.getLattice() << std::endl;
  std::cout << "cell0's volume:" << std::endl;
  std::cout << cell0.getVolume() << std::endl;

  std::cout << "cell1's lattice:" << std::endl;
  std::cout << cell1.getLattice() << std::endl;
  std::cout << "cell1's volume:" << std::endl;
  std::cout << cell1.getVolume() << std::endl;

  std::cout << "reciprocal1's lattice:" << std::endl;
  std::cout << reciprocal1.getLattice() << std::endl;
  std::cout << "reciprocal1's volume:" << std::endl;
  std::cout << reciprocal1.getVolume() << std::endl;

  std::cout << "cell2's lattice:" << std::endl;
  std::cout << cell2.getLattice() << std::endl;
  std::cout << "cell2's volume:" << std::endl;
  std::cout << cell2.getVolume() << std::endl;

  //std::cout << BaseCell::isEqual(cell) << std::endl;
  std::cout << cell0.isEqual(cell0) << std::endl;
  std::cout << cell1.isEqual(cell1) << std::endl;
  std::cout << cell0.isEqual(cell1) << std::endl;
  std::cout << cell1.isEqual(reciprocal1) << std::endl;
  std::cout << cell1.isEqual(cell2) << std::endl;

  std::cout << PI << std::endl;
  std::cout << TWOPI << std::endl;

  std::cout << at << std::endl;
  std::cout << 2.*at << std::endl;

}