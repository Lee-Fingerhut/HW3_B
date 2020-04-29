//
//  solver.hpp
//  solver-a
//
//  Created bnum Lee Fingerhut on 21/04/2020.
//  Copnumright © 2020 Lee Fingerhut. All rights reserved.
//

#include <iostream>
#include <complex>
using namespace std;
namespace solver{

class RealVariable{
public:
    double quad;
    double linear;
    double number;
    
    RealVariable(){
        quad = 0;
        linear = 1;
        number = 0;
    }
    RealVariable(double quad, double linear, double number){
        this->quad = quad;
        this->linear = linear;
        this->number = number;
    }
    friend RealVariable operator + (const RealVariable& x, const RealVariable& other);
    friend RealVariable operator + (const RealVariable& x, double num);
    friend RealVariable operator + (double num, const RealVariable& x);
    friend RealVariable operator - (const RealVariable& x, const RealVariable& other);
    friend RealVariable operator - (const RealVariable& x, double num);
    friend RealVariable operator - (double num, const RealVariable& x);
    friend RealVariable operator * (const RealVariable& x, const RealVariable& other);
    friend RealVariable operator * (const RealVariable& x, double num);
    friend RealVariable operator * (double num, const RealVariable& x);
    friend RealVariable operator / (const RealVariable& x, double num);
    friend RealVariable operator ^ (const RealVariable& x, const int num);
    friend RealVariable operator == (const RealVariable& x, const RealVariable& other);
    friend RealVariable operator == (const RealVariable& x,double num);
    friend RealVariable operator == (double num ,const RealVariable& x);
};
double solve(const RealVariable& x);

class ComplexVariable{
public:
    std::complex<double> quad;
    std::complex<double> linear;
    std::complex<double> number;
    
    ComplexVariable(){
        quad = 0;
        linear = 1;
        number = 0;
    }
    
    ComplexVariable( std::complex<double> quad, std::complex<double> linear, std::complex<double> number){
        this->quad = quad;
        this->linear = linear;
        this->number = number;
    }
    friend ComplexVariable operator + (const ComplexVariable& x, const ComplexVariable& other);
    friend ComplexVariable operator + (const ComplexVariable& x, complex<double> num);
    friend ComplexVariable operator + (complex<double> num, const ComplexVariable& x);
    friend ComplexVariable operator - (const ComplexVariable& x, const ComplexVariable& other);
    friend ComplexVariable operator - (const ComplexVariable& x, complex<double> num);
    friend ComplexVariable operator - (complex<double> num, const ComplexVariable& x);
    friend ComplexVariable operator * (const ComplexVariable& x, const ComplexVariable& other);
    friend ComplexVariable operator * (const ComplexVariable& x, complex<double> num);
    friend ComplexVariable operator * (complex<double> num, const ComplexVariable& x);
    friend ComplexVariable operator / (const ComplexVariable& x, complex<double> num);
    friend ComplexVariable operator ^ (const ComplexVariable& x, const int num);
    friend ComplexVariable operator == (const ComplexVariable& x, const ComplexVariable& other);
    friend ComplexVariable operator == (const ComplexVariable& x, complex<double> num);
    friend ComplexVariable operator == (complex<double> num , const ComplexVariable& x);
};
complex<double> solve(const ComplexVariable& x);
}
