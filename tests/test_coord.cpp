#include <iostream>
#include <Eigen/Core>
#include <cmath>

#include "catch.hpp"
#include "utils/Utils.hpp"
#include "cell/DirectCell.hpp"
#include "coord/Coord.hpp"

#include "utils.hpp"



TEST_CASE( "Coord Basic Tests" ) {
  const int n = 100;
  double a, b, c;
  DirectCell cell0;
  Eigen::Vector3d pos0;
  Coord rcoord0, rcoord1, scoord0, scoord1;
  
  for (int i = 0; i < n; i++){
    a = randomBetween(0.1, 100.); b = randomBetween(0.1, 100.); c = randomBetween(0.1, 100.);
    cell0 = getOrthoDirectCell(a, b, c);
    pos0 << randomBetween(-100, 100.),
            randomBetween(-100, 100.),
            randomBetween(-100, 100.);
    // rcoord is a cartesian coordinate
    rcoord0 = Coord(pos0, cell0, 'r');
    // scoord0 is rcoord0 in crystal basis
    scoord0 = rcoord0.toCrys();
    // rcoord1 is scoord0 in cartesian basis (i.e. back to rcoord0)
    rcoord1 = scoord0.toBasis('r'); // equivalent to scoord0.toCart()
    // adding integer values to a crystal coordinate is equivalent to a translation by a lattice vector
    // so scoord1 is still technically equivalent to scoord0
    pos0 << floor(randomBetween(-100, 100.)),
            floor(randomBetween(-100, 100.)),
            floor(randomBetween(-100, 100.));
    scoord1 = Coord(scoord0.getPos()+pos0, cell0, 's');

    REQUIRE( almostEqual(rcoord0.dd_MIC(scoord0), 0.) );
    REQUIRE( rcoord0 == scoord0 );
    REQUIRE( !(rcoord0 != scoord0) );
    REQUIRE( almostEqual(rcoord0.dd_MIC(scoord1), 0.) );
    REQUIRE( rcoord0 == scoord1 );
    REQUIRE( almostEqual(rcoord0.dd_MIC(rcoord1), 0.) );
    REQUIRE( rcoord0 == rcoord1 );
    REQUIRE( almostEqual(scoord0.dd_MIC(scoord1), 0.) );
    REQUIRE( scoord0 == scoord1 );
    REQUIRE( scoord0.getBasis() == 's' );
    REQUIRE( rcoord0.getBasis() == 'r' );
  }
}

TEST_CASE( "Coord Distance Tests" ) {
  double a, b, c;
  DirectCell cell0;
  Eigen::Vector3d pos0;
  Coord rcoord0, rcoord1, scoord0, scoord1;

  a = 9. ; b = 12.; c = 18.;
  cell0 = getOrthoDirectCell(a,b,c);
  pos0 << 0.5, 0.0, 1.0;
  scoord0 = Coord(pos0, cell0, 's');
  pos0 << 0.6, -1.0, 3.0;
  scoord1 = Coord(pos0, cell0, 's');
  REQUIRE( almostEqual(scoord0.dd_MIC(scoord1), 0.9 ) );

}