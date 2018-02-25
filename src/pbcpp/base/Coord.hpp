#ifndef PBCPP_BASE_COORD
#define PBCPP_BASE_COORD

#include <Eigen/Core>
#include "DirectCell.hpp"

class Coord{

  public:
    // constructor
    Coord(Eigen::Vector3d pos=Eigen::Vector3d::Zero(), DirectCell cell=DirectCell(), char basis='r');
    // getters
    Eigen::Vector3d getPos() const;
    DirectCell getCell() const;
    char getBasis() const;
    // returns a coordinate in Cartesian basis
    Coord toCart() const;
    // returns a coordinate in Crystal basis
    Coord toCrys() const;
    // convert the coordinate to Cartesian|Crystal basis
    Coord toBasis(char basis) const;
    // find the shortest vector connecting two coordinates using the Minimum Image Convention
    Coord d_MIC(const Coord &other) const;
    // find the distance of two coordinates using the Minimum Image Convention (i.e. the length of d_MIC)
    double dd_MIC(const Coord &other) const;
    // calculate the length of the pos vector
    double length() const;
    
  private:

    Eigen::Vector3d pos;
    DirectCell cell;
    char basis;

};

#endif // PBCPP_BASE_COORD