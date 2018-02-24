#include <iostream>

#include <Eigen/Core>
#include "base/Cell.hpp"


int main(){
  Eigen::Matrix3d at;
  at << 2., 0., 0.,
        0., 3., 0.,
        0., 0., 2.;
  BaseCell cell0{};
  BaseCell cell1(at);
  //at = cell.lattice();
  std::cout << "cell0's lattice:" << std::endl;
  std::cout << cell0.getLattice() << std::endl;
  std::cout << "cell0's volume:" << std::endl;
  std::cout << cell0.getVolume() << std::endl;

  std::cout << "cell1's lattice:" << std::endl;
  std::cout << cell1.getLattice() << std::endl;
  std::cout << "cell1's volume:" << std::endl;
  std::cout << cell1.getVolume() << std::endl;

  //std::cout << BaseCell::isEqual(cell) << std::endl;
  std::cout << cell0.isEqual(cell0) << std::endl;
  std::cout << cell1.isEqual(cell1) << std::endl;
  std::cout << cell0.isEqual(cell1) << std::endl;

}