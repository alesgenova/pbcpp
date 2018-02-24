#ifndef PBCPP_BASE_RECIPROCALCELL
#define PBCPP_BASE_RECIPROCALCELL

#include <Eigen/Core>

#include "BaseCell.hpp"


class DirectCell;

class ReciprocalCell : public BaseCell {

  public:
    // Constructors
    ReciprocalCell();
    ReciprocalCell(Eigen::Matrix3d lattice);
    // Returns the DirectCell of a ReciprocalCell
    DirectCell getDirect() const;

};


#endif // PBCPP_BASE_RECIPROCALCELL