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
    Coord toCart();
    // returns a coordinate in Crystal basis
    Coord toCrys();
    // convert the coordinate to Cartesian|Crystal basis
    Coord toBasis(char basis);
    // find the shortest vector connecting two coordinates using the Minimum Image Convention
    Coord d_MIC(Coord other);
    // find the distance of two coordinates using the Minimum Image Convention (i.e. the length of d_MIC)
    double dd_MIC(Coord other);
    // calculate the length of the pos vector
    double length();
    
  private:

    Eigen::Vector3d pos;
    DirectCell cell;
    char basis;

};

#endif // PBCPP_BASE_COORD