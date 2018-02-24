#include <iostream>
#include <vector>
#include <Eigen/Core>


#ifndef PBCPP_BASE_CELL
#define PBCPP_BASE_CELL

class BaseCell{
  public:
    // default constructor
    BaseCell();

    // constructor
    BaseCell(Eigen::Matrix3d lattice);

    // destructor
    ~BaseCell();

    // returns the volume of the cell
    double getVolume() const;

    // returns the lattice of the cell
    Eigen::Matrix3d getLattice() const;

    // compare the cell to another and determine if they are equivalent
    bool isEqual(const BaseCell & other) const;

    
  private:
    // the lattice vectors
    //std::vector< std::vector<double> > lattice;
    Eigen::Matrix3d lattice;
    // the volume
    double volume;
};


class DirectCell : private BaseCell {
  public:

  private:

};


class ReciprocalCell : private BaseCell {
  public:

  private:

};

#endif