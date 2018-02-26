#include <iostream>
#include <Eigen/Core>
#include <cmath>

#include "catch.hpp"
#include "utils/Utils.hpp"
#include "cell/DirectCell.hpp"
#include "cell/ReciprocalCell.hpp"
#include "constants/Constants.hpp"

#include "utils.hpp"


TEST_CASE( "Basic Grid Tests" ) {
  const int n = 100;
  double a, b, c;
  int i,j,k;
  Eigen::Vector3i shape;
  DirectCell grid0;
  //a = 2; b = 3; c = 4;
  //std::cout << a << "  " << b << "  " << c  <<std::endl;
  for (int l = 0; l < n; l++){
    a = randomBetween(0.1, 100.);
    b = randomBetween(0.1, 100.);
    c = randomBetween(0.1, 100.);
    i = randomBetween(1., 1000.);
    j = randomBetween(1., 1000.);
    k = randomBetween(1., 1000.);
    shape << i, j, k;
    grid0 = getOrthoDirectCell(a, b, c, shape);
    REQUIRE( almostEqual(grid0.getVolume(), a*b*c ) );
    REQUIRE( almostEqual(grid0.getDv(), a*b*c/(i*j*k) ) );
    REQUIRE( grid0.getNnr() == i*j*k );
    REQUIRE( grid0 == grid0 );
  }
}