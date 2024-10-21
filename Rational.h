//
// Created by Amnon Tamsut
// ID 203215215
// I have a special permission to submit without a partner
//


#ifndef INC_1_RATIONAL_H
#define INC_1_RATIONAL_H


#include "Polynomial.h"

class Rational {
public:
    void print();
    Rational(const Polynomial& p1, const Polynomial& p2);
    Rational operator+(const Rational& rational) const;
    Rational operator-(const Rational& rational) const;
    Rational operator*(const Rational& rational) const;

    Rational& operator=(const Rational& rational);
    friend ostream& operator << (ostream& out, const Rational& rational);




    Rational();
    Polynomial getNom();
    Polynomial getDenom();



private:
    Polynomial nom;
    Polynomial denom;
    std::string getRationalRep() const;




};


#endif //INC_1_RATIONAL_H
