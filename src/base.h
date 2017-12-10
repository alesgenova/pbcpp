#include <iostream>
#include <Eigen/Dense>

class Cell{
  public:
    // constructors
    Cell();
    //Cell(int a, int b, int c);
    //Cell(int a, int b, int c, char u);
    //Cell(Eigen::Matrix2d at);
    //Cell(Eigen::Matrix2d at, char u);
    // destructor
    ~Cell();
    Eigen::Matrix3d at;
    // get volume in atomic units
    double volume() const;
    // get volume in other units
    double volume(char u) const;
    // get direct lattice
    Eigen::Matrix3d lattice() const;
    // set direct lattice (also affects bg)
    Eigen::Matrix3d lattice(Eigen::Matrix2d);
    // get reciprocal lattice
    Eigen::Matrix3d rlattice() const;
    // set reciprocal lattice (also affects at)
    Eigen::Matrix3d rlattice(Eigen::Matrix2d);
    
  private:
    //Eigen::Matrix3d at;
    Eigen::Matrix3d bg;
    double omega;
};