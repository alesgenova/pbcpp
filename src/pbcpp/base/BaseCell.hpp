#ifndef PBCPP_BASE_BASECELL
#define PBCPP_BASE_BASECELL

#include <Eigen/Core>

class BaseCell{

  public:
    // default constructor
    BaseCell();
    // constructor
    BaseCell(Eigen::Matrix3d lattice);
    // destructor: BaseCell is an abstract class
    virtual ~BaseCell() = 0;
    // returns the volume of the cell
    double getVolume() const;
    // returns the lattice of the cell
    Eigen::Matrix3d getLattice() const;
    // compare the cell to another and determine if they are equivalent
    
  protected:
    // the lattice vectors
    Eigen::Matrix3d lattice;
    // isEqual helper function, invoked by the derived classes when overloading ==
    bool isEqual(const BaseCell& other) const;
    // the volume
    double volume;

};

#endif // PBCPP_BASE_BASECELL