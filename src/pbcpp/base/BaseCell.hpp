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
    bool isEqual(const BaseCell & other) const;
    
  protected:
    // the lattice vectors
    //std::vector< std::vector<double> > lattice;
    Eigen::Matrix3d lattice;
    // the volume
    double volume;

};

#endif // PBCPP_BASE_BASECELL