
//  solver.cpp
//  solver-a
//
//  Created bnum Lee Fingerhut on 21/04/2020.
//  Copnumright © 2020 Lee Fingerhut. All rights reserved.
//

#include "solver.hpp"
#include <complex>
#include <cmath>
#include <iostream>
#include <exception>

using namespace std;
using namespace solver;

//************************* exceptions *******************************
class exnotreal: public exception {
    virtual const char* what() const throw() {
        return "There is no real solution";
    }
} mexnotreal;

class exnotq: public exception {
    virtual const char* what() const throw() {
        return "not a quadratic expression";
    }
} myexnotq;

class exnot2: public exception {
    virtual const char* what() const throw() {
        return "power > 2";
    }
} myexnot2;

class exzero: public exception {
    virtual const char* what() const throw() {
        return "You cannot divide by zero";
    }
} myexzero;

//************************* solve *******************************
double solver::solve(const RealVariable& x){
    if(x.quad == 0 && x.linear == 0 && x.number != 0){
        throw mexnotreal;
    }
    if(x.quad == 0 && x.linear != 0){
        
        return (-x.number/x.linear);
    }
    double delta = ((x.linear*x.linear) - (4*x.quad*x.number));
    if(delta < 0){
        throw mexnotreal;
    }
    return (-x.linear + sqrt(delta))/(2*x.quad);
}

complex<double> solver::solve(const ComplexVariable& x){
    if(x.quad == std::complex<double>(0.0,0.0) && x.linear == std::complex<double>(0.0,0.0) && x.number != std::complex<double>(0.0,0.0)){
        throw mexnotreal;
    }
    if(x.quad == std::complex<double>(0.0,0.0) && x.linear != std::complex<double>(0.0,0.0)){
        
        return ((std::complex<double>(-1.0,0.0) * x.number )/x.linear);
    }
    complex<double> delta = (x.linear * x.linear - std::complex<double>(4.0,0.0) * x.quad  * x.number);
    return (std::complex<double>(-1.0,0.0) * x.linear + sqrt(delta))/(std::complex<double>(2.0,0.0) * x.quad);
}

//************************* + *******************************
RealVariable solver::operator + (const RealVariable& x, const RealVariable& other){
    RealVariable rc = RealVariable();
    rc.quad   = x.quad   + other.quad;
    rc.linear = x.linear + other.linear;
    rc.number = x.number + other.number;
    return rc;
}

RealVariable solver::operator + (const RealVariable& x, double num){
    RealVariable rc = RealVariable();
    rc.quad   = x.quad;
    rc.linear = x.linear;
    rc.number = x.number + num;
    return rc;
}

RealVariable solver::operator + (double num, const RealVariable& x){
    RealVariable rc = RealVariable();
    rc.quad   = x.quad;
    rc.linear = x.linear;
    rc.number = x.number + num;
    return rc;
}
//************************* - *******************************
RealVariable solver::operator - (const RealVariable& x, const RealVariable& other){
    RealVariable rc = RealVariable();
    rc.quad   = x.quad   - other.quad;
    rc.linear = x.linear - other.linear;
    rc.number = x.number - other.number;
    return rc;
}

RealVariable solver::operator - (const RealVariable& x, double num){
    RealVariable rc = RealVariable();
    rc.quad   = x.quad;
    rc.linear = x.linear;
    rc.number = x.number - num;
    return rc;
}

RealVariable solver::operator - (double num, const RealVariable& x){
    RealVariable rc = RealVariable();
    rc.quad   = x.quad;
    rc.linear = x.linear;
    rc.number = num - x.number;
    return rc;
}

//************************* * *******************************
RealVariable solver::operator * (const RealVariable& x, const RealVariable& other){
    RealVariable rc = RealVariable();
    if((x.quad && other.quad) || (x.quad && other.linear) || (x.linear && other.quad)){
        throw myexnotq;
    }
    rc.quad   = x.quad   * other.number + x.linear * other.linear + x.number * other.quad;
    rc.linear = x.linear * other.number + x.number * other.linear;
    rc.number = x.number * other.number;
    return rc;
}
RealVariable solver::operator * (const RealVariable& x, double num){
    RealVariable rc = RealVariable();
    rc.quad   = x.quad    * num;
    rc.linear = x.linear  * num;
    rc.number =  x.number * num;
    return rc;
}

RealVariable solver::operator * (double num, const RealVariable& x){
    return RealVariable(x.quad * num, x.linear * num, x.number * num);
}

RealVariable solver::operator / (const RealVariable& x, double num){
    
    if(num == 0){
        throw myexzero;
    }
    RealVariable rc = RealVariable();
    rc.quad   = x.quad / num;
    rc.linear = x.linear / num;
    rc.number = x.number / num;
    return rc;
}

//************************* ^ *******************************
RealVariable solver::operator ^ (const RealVariable& x, const int num){
    if(num > 2 || num < 0){
        throw myexnot2;
    }
    RealVariable rc = RealVariable();
    if (num == 0){
        rc.quad   = 0;
        rc.linear = 0;
        rc.number = 1;
    }
    if (num == 1){
        rc.quad   = 0;
        rc.linear = 1;
        rc.number = 0;
    }
    if (num == 2){
        rc.quad   = 1;
        rc.linear = 0;
        rc.number = 0;
    }
    return rc;
}
/*   for(int i = 0; i < num; i++){
 rc.quad *= x.quad;
 rc.linear *= x.linear;
 rc.number *= x.number;
 }
 return rc;*/
//}

//************************* == *******************************
RealVariable solver::operator == (const RealVariable& x, double num){
    return RealVariable(x.quad, x.linear, x.number - num);;
}
RealVariable solver::operator == (const RealVariable& x, const RealVariable& other){
    return RealVariable(x.quad - other.quad, x.linear - other.linear, x.number - other.number);
}
RealVariable solver::operator == (double num ,const RealVariable& x){
    return RealVariable(x.quad, x.linear, x.number - num);
}

//************************* + *******************************
ComplexVariable solver::operator + (const ComplexVariable& x, const ComplexVariable& other){
    ComplexVariable nc = ComplexVariable();
    nc.quad = x.quad + other.quad;
    nc.linear = x.linear + other.linear;
    nc.number = x.number + other.number;
    return nc;
}
ComplexVariable solver::operator + (const ComplexVariable& x, complex<double> num){
    ComplexVariable nc = ComplexVariable();
    nc.quad = x.quad;
    nc.linear = x.linear;
    nc.number = x.number + num;
    return nc;
}
ComplexVariable solver::operator + (complex<double> num, const ComplexVariable& x){
    ComplexVariable nc = ComplexVariable();
    nc.quad = x.quad;
    nc.linear = x.linear;
    nc.number = num + x.number;
    return nc;
}
//************************* - *******************************
ComplexVariable solver::operator - (const ComplexVariable& x, const ComplexVariable& other){
    ComplexVariable nc = ComplexVariable();
    nc.quad = x.quad - other.quad;
    nc.linear = x.linear - other.linear;
    nc.number = x.number - other.number;
    return nc;
}
ComplexVariable solver::operator - (const ComplexVariable& x, complex<double> num){
    ComplexVariable nc = ComplexVariable();
    nc.quad = x.quad;
    nc.linear = x.linear;
    nc.number = x.number - num;
    return nc;
}
ComplexVariable solver::operator - (complex<double> num, const ComplexVariable& x){
    ComplexVariable nc = ComplexVariable();
    nc.quad =  x.quad;
    nc.linear = x.linear;
    nc.number = num - x.number;
    return nc;
}
//************************* * *******************************
ComplexVariable solver::operator * (const ComplexVariable& x, const ComplexVariable& other){
    ComplexVariable nc = ComplexVariable();
    if((x.quad == std::complex<double>(0.0,0.0) && other.quad == std::complex<double>(0.0,0.0)) || (x.quad == std::complex<double>(0.0,0.0) && other.linear == std::complex<double>(0.0,0.0)) || (x.linear == std::complex<double>(0.0,0.0) && other.quad == std::complex<double>(0.0,0.0))){
        throw myexnotq;
    }
    nc.quad   = x.quad   * other.quad;
    nc.linear = x.linear * other.linear;
    nc.number = x.number * other.number;
    return nc;
}
ComplexVariable solver::operator * (const ComplexVariable& x, complex<double> num){
    ComplexVariable nc = ComplexVariable();
    nc.quad   = x.quad * num;
    nc.linear = x.linear * num;
    nc.number =  x.number * num;
    return nc;
}
ComplexVariable solver::operator * (complex<double> num, const ComplexVariable& x){
    ComplexVariable nc = ComplexVariable();
    nc.quad   = x.quad   * num;
    nc.linear = x.linear * num;
    nc.number = x.number * num;
    return nc;
}
//************************* / *******************************
ComplexVariable solver::operator / (const ComplexVariable& x, complex<double> num){
    if(num == std::complex<double>(0.0,0.0)){
        throw myexzero;
    }
    ComplexVariable nc = ComplexVariable();
    nc.quad   = x.quad   / num;
    nc.linear = x.linear / num;
    nc.number = x.number / num;
    return nc;
}

//************************* ^ *******************************
ComplexVariable solver::operator ^ (const ComplexVariable& x, const int num){
    if(num > 2 || num < 0){
        throw myexnot2;
    }
    ComplexVariable nc = ComplexVariable();
    if (num == 0){
        nc.quad   = 0;
        nc.linear = 0;
        nc.number = 1;
    }
    if (num == 1){
        nc.quad   = 0;
        nc.linear = 1;
        nc.number = 0;
    }
    if (num == 2){
        nc.quad   = 1;
        nc.linear = 0;
        nc.number = 0;
    }
    return nc;
}

//************************* == *******************************
ComplexVariable solver::operator == (const ComplexVariable& x, const ComplexVariable& other){
    return ComplexVariable(x.quad - other.quad, x.linear - other.linear, x.number - other.number);;
}
ComplexVariable solver::operator == (const ComplexVariable& x, complex<double> num){
    return ComplexVariable(x.quad, x.linear, x.number - num);;
}
ComplexVariable solver::operator == (complex<double> num , const ComplexVariable& x){
    return ComplexVariable(x.quad, x.linear, x.number - num);
}


