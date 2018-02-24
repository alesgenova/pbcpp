#include <iostream>
#include <vector>
#include <Eigen/Core>


#ifndef PBCPP_BASE_CELL
#define PBCPP_BASE_CELL


class BaseCell;
class DirectCell;
class ReciprocalCell;


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


class DirectCell : public BaseCell {

  public:
    // Constructors
    DirectCell();
    DirectCell(Eigen::Matrix3d lattice);

    // Returns the ReciprocalCell of a DirectCell
    ReciprocalCell getReciprocal() const;

};


class ReciprocalCell : public BaseCell {

  public:
    // Constructors
    ReciprocalCell();
    ReciprocalCell(Eigen::Matrix3d lattice);

    // Returns the DirectCell of a ReciprocalCell
    DirectCell getDirect() const;

};

#endif