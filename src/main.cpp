#include "base.h"
#include <Eigen/Dense>

int main(){
  Cell cell{};
  Eigen::Matrix3d at;
  //at = cell.lattice();
  std::cout << "Cell's at:" << std::endl;
  std::cout << cell.lattice() << std::endl;
  /*
  std::cout << at(0,0) << at(0,1) << at(0,2) << std::endl;
  std::cout << at(1,0) << at(1,1) << at(1,2) << std::endl;
  std::cout << at(2,0) << at(2,1) << at(2,2) << std::endl;
  */
}