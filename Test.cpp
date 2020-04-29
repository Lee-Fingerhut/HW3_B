
//  Test.cpp
//  solver-a
//
//  Created bnum Lee Fingerhut on 21/04/2020.
//  Copnumright © 2020 Lee Fingerhut. All rights reserved.
//
#include "doctest.h"
#include "solver.hpp"
#include <complex>

using namespace std;
using solver::solve, solver::RealVariable, solver::ComplexVariable;

//************************RealVariable***********************
TEST_CASE("Test for RealVariable")
{
    RealVariable x;
    CHECK(solve(3*x + 2 == 5*x - 10) == double(6));
    CHECK((solve((5*x^2) + 1 == 26) == double(5) || solve((5*x^2) + 1 == 26) == double(-5)));
    CHECK((solve((x^2) + 2 == 11 ) == double(3) || solve((x^2) + 2 == 11 ) == double(-3)));
    CHECK((solve((x^2) + 5*x + 6 == 0 ) == double(-2) || (solve((x^2) + 5*x + 6 == 0 ) == double(-3))));
    CHECK((solve(4*(x^2) ==  64 ) == double(4) || solve(4*(x^2) == 64 ) == double(-4)));
    CHECK(solve(4*x + 5*x == 5*x + 64 ) == double(16));
    CHECK(solve(6*x + 5*x == 4*x + 7) == double(1));
    CHECK(solve(6*x + 5*x +7 == 4*x + 7) == double(0));
    CHECK(solve(7*(x^2) + 6*x + 5*x +7 == 4*x + 7) == double(0));
    CHECK(solve(5*x + 6 == 43) == double(7.4));
    CHECK(solve(2*x - 2 == 3*x - 10) == double(8));
    CHECK((solve((x^2) - 5 == 11 ) == double(4) || solve((x^2) + 2 == 11 ) == double(-4)));
    CHECK((solve((x^2) - 5*x + 6 == 0 ) == double(2) || (solve((x^2) - 5*x + 6 == 0 ) == double(3))));
    CHECK((solve(9*(x^2) ==  81 - 72 ) == double(1) || solve(9*(x^2) ==  81 - 72 ) == double(-1)));
    CHECK(solve(4*x - 5*x == x + 50 ) == double(-25));
    CHECK(solve(6*x - 5*x ==  7) == double(7));
    CHECK(solve(6*x - 5*x  == 2*x + 0) == double(0));
    CHECK(solve(7*(x^2) + 6*x + 5*x - 7 == 6*(x^2) +11*x - 7) == double(0));
    CHECK(solve(12*x - 10*x == 42) == double(21));
    CHECK(solve(5*x * 5 == 50) == double(2));
    CHECK((solve((x^2)*9 == 81 ) == double(-3) || (solve((x^2)*9 == 81) == double(3))));
    CHECK(solve(6*x + 3*4 == 0) == double(-2));
    CHECK(solve(16*x - 4*3*x == 12) == double(3));
    CHECK(solve(4*x - 5*x == (x + 30)*2 ) == double(-20));
    CHECK(solve(6*x - 5*x ==  7) == double(7));
    CHECK(solve(6*x*0 + 5*x  == 25) == double(5));
    CHECK(solve(6*x*0 + 5*x  == 25*0) == double(0));
    CHECK((solve((2*(x^2) +x)*2 == 0) == double(0) || (solve((2*(x^2) +x)*3 == 0) == double(-1))));
    CHECK(solve(5*x * 5 == 50) == double(2));
    CHECK((solve((x^2)*9 == 81 ) == double(-3) || (solve((x^2)*9 == 81) == double(3))));
    CHECK(solve(6*x + 3*4 == 0) == double(-2));
    CHECK(solve(16*x - 4*3*x == 12) == double(3));
    CHECK(solve(4*x - 5*x == (x + 30)*2 ) == double(-20));
    CHECK(solve(6*x - 5*x ==  7) == double(7));
    CHECK(solve(6*x*0 + 5*x  == 25) == double(5));
    CHECK(solve(6*x*0 + 5*x  == 25*0) == double(0));
    CHECK((solve((2*(x^2) +x)*2 == 0) == double(0) || (solve((2*(x^2) +x)*3 == 0) == double(-1))));
    CHECK(solve(6*x/2 == 27) == double(9));
    CHECK((solve(4*(x^2)/2 + 3*x == 3*x + 50) == double(-5) || (solve(4*(x^2)/2 + 3*x == 3*x + 50) == double(5))));
    CHECK((solve((12*(x^2) + 15)/3 == 9) == double(1) || (solve((12*(x^2) + 15)/3 == 9) == double(-1))));
    CHECK(solve((4*x*5*x)/10 == 0) == double(0));
}

TEST_CASE("Test for ComplexVariable")
{
    ComplexVariable x;
    CHECK((solve((x^2) == 16) == std::complex<double>(4.0,0.0) || (solve((x^2) == 16) == std::complex<double>(-4.0,0.0))));
    CHECK(solve(x+5i == 2*x+3i) == std::complex<double>(0.0,2.0));
    CHECK(solve(2*x+6i == 6*x+7i) == std::complex<double>(0.0,-0.25));
    CHECK(solve((10*x+5i)/5 == 5i) == std::complex<double>(0.0,2.0));
    CHECK((solve((x^2) == 49) == std::complex<double>(7.0,0.0) || (solve((x^2) == 49) == std::complex<double>(-7.0,0.0))));
    CHECK(solve(4*x+4i == 3*x+3i) == std::complex<double>(0.0,-1.0));
    CHECK(solve(5*x+99i == 25*x+199i) == std::complex<double>(0.0,-5.0));
    CHECK(solve((10*x+5i)/5 == 5i) == std::complex<double>(0.0,2.0));
    CHECK((solve((x^2) == 81) == std::complex<double>(9.0,0.0) || (solve((x^2) == 81) == std::complex<double>(-9.0,0.0))));
    CHECK(solve(10*x+8i == 9*x+20i) == std::complex<double>(0.0,12.0));
    CHECK(solve((40*x+5i)/5 == 9i) == std::complex<double>(0.0,1.0));
    CHECK((solve((x^2) == 100) == std::complex<double>(10.0,0.0) || (solve((x^2) == 100) == std::complex<double>(-10.0,0.0))));
    CHECK(solve(4*x+4i == 5*3*x-7i) == std::complex<double>(0.0,1.0));
    CHECK(solve(4*(x^2)/4== 0) == std::complex<double>(0.0,0.0));
    CHECK(solve((10*x+10i)/2 == -5i) == std::complex<double>(0.0,-2.0));
    CHECK(solve(2*x+3i == 3*x+3i) == std::complex<double>(0.0,0.0));
    CHECK(solve(4*x+9i == 3*x+3i) == std::complex<double>(0.0,-6.0));
    CHECK(solve((x^2)+2*x+3i == 2*x+3i) == std::complex<double>(0.0,0.0));
    CHECK(solve(10*x+2i == 8*x+6i) == std::complex<double>(0.0,2.0));
    CHECK(solve(12*x+3i == 4*x+19i) == std::complex<double>(0.0,2.0));
    CHECK(solve((x^2) == 0) == std::complex<double>(0.0,0.0));
    CHECK(solve((x^2)+5*x+6i == 5*x+6i) == std::complex<double>(0.0,0.0));
    CHECK(solve(40*x-10i == 10*x-40i) == std::complex<double>(-0,-1));
    CHECK(solve(2*x+3i == 4*x-7i) == std::complex<double>(0.0,5.0));
    CHECK(solve(3*(x^2)/3== 0) == std::complex<double>(0.0,0.0));
    CHECK(solve((24*x+12i)/2 == 0i) == std::complex<double>(-0.0,-0.5));
    CHECK(solve(10*x+3i == 9*x+3i) == std::complex<double>(0.0,0.0));
    CHECK(solve(20*x+101i == 10*x+1i) == std::complex<double>(0.0,-10.0));
    CHECK(solve((x^2)+3*x+3i == 3*x+3i) == std::complex<double>(0.0,0.0));
    CHECK(solve(12*x+2i == 8*x+6i) == std::complex<double>(0.0,1.0));
    CHECK(solve((x^2)+2*x+4i == 2*x+4i) == std::complex<double>(0.0,0.0));
}

TEST_CASE("Test for Exceptions")
{
    ComplexVariable y;
    RealVariable x;
    CHECK_THROWS(solve((x^4) == 64));
    CHECK_THROWS(solve((x^5)+(x^2) == 20));
    CHECK_THROWS(solve((x^10) == 100));
    CHECK_THROWS(solve((4*x^6)+(4*x^5)+34 == 2000));
    CHECK_THROWS(solve((x^4) == 64));
    CHECK_THROWS(solve((x^5)+(x^2) == 20));
    CHECK_THROWS(solve((x^10) == 100));
    CHECK_THROWS(solve(5*(x^2)+6*x+2 == 0));
    CHECK_THROWS(solve((x^2)/0 == 0));
    CHECK_THROWS(solve((x^2) == -100));
    CHECK_THROWS(solve(((x^4)+3)/0== 200));
    CHECK_THROWS(solve((x^40) == 64));
    CHECK_THROWS(solve((x^10)+(x^1) == 20));
    CHECK_THROWS(solve((x^3) == 2300));
    CHECK_THROWS(solve(9*(x^2)+6*x/0 + 5 == 5));
    CHECK_THROWS(solve(4*x - 4*x - 3 == 0));
    CHECK_THROWS(solve((x^2) == -30));
    CHECK_THROWS(solve((x^33) == 445433));
    CHECK_THROWS(solve(((x^6)+7*x)/567 + 6*x/0== 2980));
    CHECK_THROWS(solve((x^2) == -81));
    CHECK_THROWS(solve((x^150) == 280));
    CHECK_THROWS(solve((x^36) == 27300));
    CHECK_THROWS(solve(9*(x^2)+5*6*9*10*x/0 == 5));
    CHECK_THROWS(solve(4*(x^2)+ 1*x + 1 == 0));
    CHECK_THROWS(solve((y^4)+5i == 200));
    CHECK_THROWS(solve((y^6)+(y^5) +8i == 0));
    CHECK_THROWS(solve((4*y^6)+(4*y^5)+34 == 2000));
    CHECK_THROWS(solve((y^4) == -64));
    CHECK_THROWS(solve((y^5)+(y^2) == 67i));
    CHECK_THROWS(solve((y^10) == 100));
    CHECK_THROWS(solve((y^2)/0 * 7i == 0));
    CHECK_THROWS(solve((y^2)/0 == -100));
    CHECK_THROWS(solve((y^70) == -64));
    CHECK_THROWS(solve((y^10)+(y^1) == 208i));
    CHECK_THROWS(solve((y^3) == -2300));
    CHECK_THROWS(solve(9*(x^2)+6*x/0 + 5 == 5));
    CHECK_THROWS(solve(4*y - 4*y - 3i == 0));
    CHECK_THROWS(solve((y^72) == -30));
    CHECK_THROWS(solve((y^33) == 43));
    CHECK_THROWS(solve(((y^6)+8*y)/5 + 6*y/0== 2i));
    CHECK_THROWS(solve((y^9) == -81));
    CHECK_THROWS(solve((y^18) == 2));
    CHECK_THROWS(solve((y^89) == 90));
    CHECK_THROWS(solve(9*(y^2)+5*6*9*10*y/0 == 5i));
    CHECK_THROWS(solve(4*(y^2)+ 1*y/0 + 1i == 0));
}
