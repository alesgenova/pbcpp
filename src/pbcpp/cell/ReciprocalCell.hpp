#ifndef PBCPP_BASE_RECIPROCALCELL
#define PBCPP_BASE_RECIPROCALCELL

#include <Eigen/Core>

#include "constants/Constants.hpp"
#include "BaseCell.hpp"



class DirectCell;

class ReciprocalCell : public BaseCell {

  public:
    // Constructors
    ReciprocalCell(Eigen::Matrix3d lattice=TWOPI*Eigen::Matrix3d::Identity(),
                   Eigen::Vector3i shape=Eigen::Vector3i::Ones());
    // Returns the DirectCell of a ReciprocalCell
    DirectCell getDirect() const;
    // compare operators
    bool operator==(const ReciprocalCell & other) const;
    bool operator!=(const ReciprocalCell & other) const;

};


#endif // PBCPP_BASE_RECIPROCALCELL