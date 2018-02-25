#include <iostream>
#include <Eigen/Core>

#include "catch.hpp"
#include "base/DirectCell.hpp"
#include "base/ReciprocalCell.hpp"
#include "base/Coord.hpp"
#include "constants/Constants.hpp"

#include "utils.hpp"

unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? 1 : Factorial(number-1)*number;
}

TEST_CASE( "Basic DirectCell Tests" ) {
    const int n = 100;
    double a, b, c;
    DirectCell cell0;
    //a = 2; b = 3; c = 4;
    //std::cout << a << "  " << b << "  " << c  <<std::endl;
    for (int i = 0; i < n; i++){
        a = randomBetween(0.1, 100.); b = randomBetween(0.1, 100.); c = randomBetween(0.1, 100.);
        cell0 = getOrthoDirectCell(a, b, c);
        REQUIRE( almostEqual(cell0.getVolume(), a*b*c ) );
        REQUIRE( cell0 == cell0 );
    }
}

TEST_CASE( "Basic ReciprocalCell Tests" ) {
    const int n = 100;
    double a, b, c;
    ReciprocalCell cell0;
    for (int i = 0; i < n; i++){
        a = randomBetween(0.1, 100.); b = randomBetween(0.1, 100.); c = randomBetween(0.1, 100.);
        cell0 = getOrthoReciprocalCell(a, b, c);
        REQUIRE( almostEqual(cell0.getVolume(), (TWOPI*TWOPI*TWOPI)/(a*b*c) ) );
        REQUIRE( cell0 == cell0 );
    }
}

TEST_CASE( "DirectCell ReciprocalCell conversion Tests" ) {
    const int n = 100;
    double a, b, c;
    DirectCell cell0, cell1;
    ReciprocalCell reciprocal0, reciprocal1;

    for (int i = 0; i < n; i++){
        a = randomBetween(0.1, 100.); b = randomBetween(0.1, 100.); c = randomBetween(0.1, 100.);
        // cells generated 
        cell0 = getOrthoDirectCell(a, b, c);
        reciprocal0 = getOrthoReciprocalCell(a, b, c);
        // cells generated by conversion
        reciprocal1 = cell0.getReciprocal();
        cell1 = reciprocal1.getDirect();
        REQUIRE( almostEqual(cell0.getVolume(), a*b*c ) );
        REQUIRE( almostEqual(cell1.getVolume(), a*b*c ) );
        REQUIRE( cell0 == cell1 );
        REQUIRE( almostEqual(reciprocal1.getVolume(), (TWOPI*TWOPI*TWOPI)/(a*b*c) ) );
        REQUIRE( reciprocal0 == reciprocal1 );
    }
}

TEST_CASE( "Basic Coord Tests" ) {
    const int n = 100;
    double a, b, c;
    DirectCell cell0 = getOrthoDirectCell(2,3,3);
    Eigen::Vector3d pos0;
    pos0 << 2., 1., 1.;
    Coord coord0;
    coord0 = Coord(pos0, cell0, 's');
    std::cout << coord0.getPos() << std::endl;
    std::cout << coord0.getCell().getLattice() << std::endl;
    std::cout << coord0.getBasis() << std::endl;
    
    for (int i = 0; i < n; i++){

    }
}