//
// Created by Amnon Tamsut
// ID 203215215
// I have a special permission to submit without a partner
//
#include <iostream>
#include <sstream>      // std::ostringstream

#include "Rational.h"

void Rational::print() {
    this->nom.print();
    cout<< "--------------------------"<<endl;
    this->denom.print();
}

Rational::Rational(const Polynomial& p1, const Polynomial& p2) {
    this->nom = p1;
    this ->denom = p2;

}

Rational::Rational() {

    Polynomial numerator = Polynomial();
    Polynomial denomenator = Polynomial();

    this->nom = numerator;
    this->denom = denomenator;

}

Polynomial Rational::getNom() {
    return this->nom;
}

Polynomial Rational::getDenom() {
    return this->denom;
}

//finding common denomenator by using:
//      p1/p2 + p3/p4 =
//
//      p1*p4 + p3*p2
//      -------------
//          p2*p4
//
Rational Rational::operator+(const Rational &rational) const {

    Rational endRational;



    //p1*p4 + p3*p2
    endRational.nom = (this->nom*rational.denom) + (rational.nom*this->denom);
    endRational.denom = this->denom*rational.denom;


    return endRational;
}


//finding common denominator by using:
//      p1/p2 - p3/p4 =
//
//      p1*p4 - p3*p2
//      -------------
//          p2*p4
//
Rational Rational::operator-(const Rational &rational) const {
    Rational endRational;



    //p1*p4 - p3*p2
    endRational.nom = (this->nom*rational.denom) - (rational.nom*this->denom);
    endRational.denom = this->denom*rational.denom;


    return endRational;
}

Rational Rational::operator*(const Rational &rational) const {

    Rational endRational;

    endRational.nom = this->nom*rational.nom;
    endRational.denom = this->denom*rational.denom;


    return endRational;
}

Rational &Rational::operator=(const Rational &rational) {

    this->nom = rational.nom;
    this->denom = rational.denom;
    return *this;
}

ostream& operator << (ostream& out, const Rational& r)
{
    out << r.getRationalRep();
    return out;
}


std::string Rational::getRationalRep() const {

    std::string str;
    std::ostringstream out;
    std::ostringstream temp;


    out<< this->nom;
    out<< "--------------------------"<<endl;

    temp<< this->denom;

    if(temp.str() == "0" || temp.str() == "0\n") {
        out<< "1";
    }else{
        out << temp.str();
    }
    str = out.str();
    return str;

}

