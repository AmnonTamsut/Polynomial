//
// Created by Amnon Tamsut
// ID 203215215
// I have a special permission to submit without a partner
//


#include <iostream>
#include "Polynomial.h"
#include <vector>
#include <sstream>      // std::ostringstream
#include <string.h>
using namespace std;


//Using maxDegree to find the total max degree of all the polynomials.
int Polynomial::maxGlobalDegree = 0;


Polynomial::Polynomial() {

    initPolynomial(nullptr, 0);
}

Polynomial::Polynomial(int x) {
    initPolynomial(nullptr, x);
}

Polynomial::Polynomial(double *coeff, int degree) {
    initPolynomial(coeff, degree);
}


//Initializes a polynomial
void Polynomial::initPolynomial(double *coeff, int degree) {

    //if (degree > maxDegree) maxDegree = degree;


    this->polynomialCoeff.resize(degree + 1);

    if (!coeff) {
        std::fill(this->polynomialCoeff.begin(), this->polynomialCoeff.end(), 0);
    } else {
        this->polynomialCoeff.assign(coeff, coeff + (degree + 1));
    }


    this->findMaxPower();
}

//getters and setters
int Polynomial::getDegree(bool what) const {

    if (!what) return this->polynomialCoeff.size() - 1;

    return this->maxLocalDegree;
}

double Polynomial::getCoeff(int index) const {
    double inValid = -1234.12;
    if(this->polynomialCoeff.size() <= index || index < 0)
        return inValid;

    return this->polynomialCoeff.at(index);
}

void Polynomial::setCoeff(int index, double coeff) {
    unsigned long sizeTemp = 0;

    //edge case - when the requested index is invalid
    if (this->polynomialCoeff.size() < index || this->polynomialCoeff.size() == index) {
        sizeTemp = this->polynomialCoeff.size();
        this->polynomialCoeff.resize(index + 1);
        std::fill(this->polynomialCoeff.begin() + sizeTemp, this->polynomialCoeff.end(), 0);
    }
    this->polynomialCoeff.at(index) = coeff;
    this->findMaxPower();

}

//retrieves max local degree for all polynomials
int Polynomial::getMaxDegree() {
    return maxGlobalDegree;
}

//retrieves max local degree for a single polynomial
int Polynomial::getMaxLocalDegree() const {
    return maxLocalDegree;
}



//prints the polynomial in the following format:
//      polynomial = 0.1+0.2X^1+0X^2+11.5X^3+1.3X^4
void Polynomial::print() {
    cout << "polynomial = " << getPolynomRep() << endl;
}

//finds max power from all polynomials & local one
void Polynomial::findMaxPower() {
//    this->maxLocalDegree = 0;
    int local = 0;
    for (int i = 0; i < this->polynomialCoeff.size(); i++) {

        if (this->getCoeff(i) != 0) this->maxLocalDegree = i;

    }

    if (maxGlobalDegree < this->maxLocalDegree) maxGlobalDegree = this->maxLocalDegree;

}

Polynomial Polynomial::operator+(const Polynomial& poly) const
{
    int i = 0;
    int maxDegreeTemp = std::max(this->getMaxLocalDegree(), poly.getMaxLocalDegree()),
            minDegree = std::min(this->getMaxLocalDegree(), poly.getMaxLocalDegree());
    Polynomial maxPoly = maxDegreeTemp == this->getMaxLocalDegree() ? *this : poly;
    Polynomial solution(maxDegreeTemp);

    //substracting coefficients with their corresponding counterpart
    for (i = 0; i <= minDegree; i++)
    {
        solution.setCoeff(i, this->getCoeff(i) + poly.getCoeff(i));
    }
    for (; i <= maxDegreeTemp; i++)
    {
        solution.setCoeff(i, maxPoly.getCoeff(i));
    }


    return solution;
}

Polynomial Polynomial::operator-(const Polynomial& poly) const
{
    int i = 0;
    int maxDegreeTemp = std::max(this->getMaxLocalDegree(), poly.getMaxLocalDegree()),
            minDegree = std::min(this->getMaxLocalDegree(), poly.getMaxLocalDegree());
    Polynomial maxPoly = maxDegreeTemp == this->getMaxLocalDegree() ? *this : poly;
    Polynomial solution(maxDegreeTemp);

    //substracting coefficients with their corresponding counterpart
    for (i = 0; i <= minDegree; i++)
    {
        solution.setCoeff(i, this->getCoeff(i) - poly.getCoeff(i));
    }
    for (; i <= maxDegreeTemp; i++)
    {
        solution.setCoeff(i, maxPoly.getCoeff(i));
    }


    return solution;
}

Polynomial Polynomial::operator*(const Polynomial& poly) const
{

    Polynomial solution = Polynomial(this->getMaxLocalDegree()+poly.getMaxLocalDegree());

    for (int i = 0; i <= this->getMaxLocalDegree(); i++)
    {
        for (int j = 0; j <= poly.getMaxLocalDegree(); j++)
        {
            solution.setCoeff(i + j, solution.getCoeff(i+j) + (this->getCoeff(i) * poly.getCoeff(j)));
        }
    }

    return solution;
}


Polynomial operator*(double lhs, const Polynomial& rhs)
{

    Polynomial solution;

    for (int i = 0; i <= rhs.getMaxLocalDegree(); i++)
    {
        solution.setCoeff(i, lhs * rhs.getCoeff(i));
    }
    return solution;
}

Polynomial operator*(const Polynomial& rhs,double lhs)
{
    Polynomial solution;
    for (int i = 0; i <= rhs.getMaxLocalDegree(); i++)
    {
        solution.setCoeff(i, lhs * rhs.getCoeff(i));
    }
    return solution;
}

double& Polynomial::operator[](int index)
{

    double inValid = -1234.12;
    if (this->maxLocalDegree < index || index < 0)
        return inValid;

    return this->polynomialCoeff.at(index);

}
std::string Polynomial::getPolynomRep() const
{
    std::ostringstream out;
    out << this->polynomialCoeff.at(0);
    if (this->polynomialCoeff.size() != 1 && this->maxLocalDegree != 0) {
        out << "+";
        for (int i = 1; i <= this->getMaxLocalDegree(); ++i) {
            out <<"("<< this->polynomialCoeff.at(i) << ")*X^" << i;
            if (i != this->getMaxLocalDegree()) {
                out << "+";
            }
        }
    }
    out << endl;
    return out.str();
}
ostream& operator << (ostream& out, const Polynomial& p)
{
    out << p.getPolynomRep();
    return out;
}



Polynomial& Polynomial::operator=(const Polynomial& p)
{
    int max = std::max(this->polynomialCoeff.size(),p.polynomialCoeff.size());
    this->polynomialCoeff.resize(max);
    for (int i = 0; i < p.polynomialCoeff.size(); ++i) {
        this->setCoeff(i,p.getCoeff(i));
    }

    findMaxPower();
    return *this;
}
