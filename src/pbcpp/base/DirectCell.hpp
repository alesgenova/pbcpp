#ifndef PBCPP_BASE_DIRECTCELL
#define PBCPP_BASE_DIRECTCELL

#include <Eigen/Core>

#include "BaseCell.hpp"


class ReciprocalCell;

class DirectCell : public BaseCell {

  public:
    // Constructors
    DirectCell();
    DirectCell(Eigen::Matrix3d lattice);
    // Returns the ReciprocalCell of a DirectCell
    ReciprocalCell getReciprocal() const;

};

#endif // PBCPP_BASE_DIRECTCELL