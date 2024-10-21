//
// Created by Amnon Tamsut
// ID 203215215
// I have a special permission to submit without a partner
//

#ifndef INC_1_POLYNOMIAL_H
#define INC_1_POLYNOMIAL_H
using namespace std;
#include <vector>



class Polynomial {
public:
    //Constructors
    Polynomial();
    explicit Polynomial(int x);
    Polynomial(double* coeff, int degree);



    //Getter & Setters
    static int getMaxDegree();
    int getDegree(bool what) const;
    double getCoeff(int index) const;

    void setCoeff(int index, double coeff);


    void initPolynomial(double* coeff, int degree);

    void print();
    void findMaxPower();

    Polynomial operator+(const Polynomial& poly) const;
    Polynomial operator-(const Polynomial& poly) const;
    Polynomial operator*(const Polynomial& poly) const;

    Polynomial& operator=(const Polynomial& poly);


    int getMaxLocalDegree() const;

    double& operator[](int index);

    friend Polynomial operator*(double lhs, const Polynomial &rhs);
    friend Polynomial operator*(const Polynomial& rhs,double lhs);
    friend ostream& operator << (ostream& out, const Polynomial& p);


private:
    int maxLocalDegree;

    vector<double> polynomialCoeff;

    std::string getPolynomRep() const;


    static int maxGlobalDegree;
};


#endif //INC_1_POLYNOMIAL_H
