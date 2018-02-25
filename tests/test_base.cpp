#include "catch.hpp"

#include <Eigen/Core>
#include "base/DirectCell.hpp"
#include "base/ReciprocalCell.hpp"
#include "constants/Constants.hpp"

#include "utils.hpp"

unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? 1 : Factorial(number-1)*number;
}

TEST_CASE( "Basic DirectCell Tests" ) {
    double a, b, c;

    a = 2; b = 3; c = 4;
    DirectCell cell0 = getOrthorombicCell(a, b, c);
    REQUIRE( almostEqual(cell0.getVolume(), a*b*c ) );
    REQUIRE( cell0 == cell0 );
}