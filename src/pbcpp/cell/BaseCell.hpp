#ifndef PBCPP_BASE_BASECELL
#define PBCPP_BASE_BASECELL

#include <Eigen/Core>

class BaseCell{

  public:
    // constructor
    BaseCell(Eigen::Matrix3d lattice=Eigen::Matrix3d::Identity(),
             Eigen::Vector3i shape=Eigen::Vector3i::Ones());
    // destructor: BaseCell is an abstract class
    virtual ~BaseCell() = 0;
    // returns the volume of the cell
    double getVolume() const;
    double getDv() const;
    Eigen::Vector3i getShape() const;
    int getNnr() const;
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
    // the number of points along each direction
    Eigen::Vector3i shape;
    // the total number of points in the grid
    int nnr;
    // the volume size of each point on the grid
    double dv;

};

#endif // PBCPP_BASE_BASECELL