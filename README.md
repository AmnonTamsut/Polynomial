
# Rational Polynomial Library

This project implements a `Rational` class that models rational expressions using polynomials. The project includes operators to handle arithmetic operations like addition, subtraction, and multiplication for rational numbers, as well as methods for printing and displaying rational expressions.

## Table of Contents
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Classes Overview](#classes-overview)
  - [Rational Class](#rational-class)
  - [Polynomial Class](#polynomial-class)
- [Example](#example)
- [Contributing](#contributing)
- [License](#license)

## Features
- **Polynomials Support**: Define, add, subtract, and multiply polynomials.
- **Rational Arithmetic**: Supports arithmetic operations (`+`, `-`, `*`) for rational expressions.
- **Custom Printing**: Provides a structured view of rational expressions and polynomials.
- **Global Degree Tracking**: Tracks the maximum degree of all polynomials in the system.

## Installation

Clone the repository to your local machine using:
```bash
git clone https://github.com/your-username/rational-polynomial-library.git
```

Make sure you have a C++ compiler installed that supports C++11 or later.

### Compile

To compile the project, use:
```bash
g++ -o RationalProgram Polynomial.cpp Rational.cpp main.cpp
```

## Usage

Once compiled, run the program with:
```bash
./RationalProgram
```

You can create and manipulate rational numbers as follows:

```cpp
double coeffs1[] = {1, 2, 3};  // Coefficients for the first polynomial
double coeffs2[] = {2, 4};     // Coefficients for the second polynomial
Polynomial p1(coeffs1, 2);     // 1 + 2x + 3x^2
Polynomial p2(coeffs2, 1);     // 2 + 4x

Rational r1(p1, p2);           // Rational expression p1 / p2
r1.print();
```

## Classes Overview

### Rational Class
This class represents a rational expression of the form `P(x) / Q(x)`, where `P` and `Q` are polynomials.

#### Public Methods
- **Constructor**: `Rational(const Polynomial& p1, const Polynomial& p2)` - Initializes a rational expression with two polynomials.
- **Addition**: `Rational operator+(const Rational& r) const` - Adds two rational expressions.
- **Subtraction**: `Rational operator-(const Rational& r) const` - Subtracts two rational expressions.
- **Multiplication**: `Rational operator*(const Rational& r) const` - Multiplies two rational expressions.
- **Get Numerator**: `Polynomial getNom()` - Returns the numerator polynomial.
- **Get Denominator**: `Polynomial getDenom()` - Returns the denominator polynomial.
- **Print**: `void print()` - Prints the rational expression.
- **Assignment**: `Rational& operator=(const Rational& r)` - Assigns one rational expression to another.

#### Friends
- **Stream Output**: `friend ostream& operator<<(ostream& out, const Rational& r)` - Allows printing of the rational expression using `<<`.

### Polynomial Class
This class represents a polynomial.

#### Public Methods
- **Constructor**: `Polynomial(double* coeff, int degree)` - Initializes a polynomial from an array of coefficients.
- **Get Degree**: `int getDegree(bool what) const` - Returns the degree of the polynomial.
- **Get Coefficient**: `double getCoeff(int index) const` - Returns the coefficient for a specific term.
- **Set Coefficient**: `void setCoeff(int index, double coeff)` - Sets the coefficient for a specific term.
- **Print**: `void print()` - Prints the polynomial in a readable format.
- **Find Max Power**: `void findMaxPower()` - Updates the degree of the polynomial based on non-zero coefficients.

#### Operators
- **Addition**: `Polynomial operator+(const Polynomial& p) const` - Adds two polynomials.
- **Subtraction**: `Polynomial operator-(const Polynomial& p) const` - Subtracts two polynomials.
- **Multiplication**: `Polynomial operator*(const Polynomial& p) const` - Multiplies two polynomials.
- **Assignment**: `Polynomial& operator=(const Polynomial& p)` - Assigns one polynomial to another.
- **Stream Output**: `friend ostream& operator<<(ostream& out, const Polynomial& p)` - Allows printing of the polynomial using `<<`.

## Example

```cpp
#include "Polynomial.h"
#include "Rational.h"

int main() {
    // Example of creating two polynomials
    double coefficients1[] = {1, 0, 3};  // Represents 1 + 0x + 3x^2
    double coefficients2[] = {2, 4};     // Represents 2 + 4x

    Polynomial p1(coefficients1, 2);
    Polynomial p2(coefficients2, 1);

    // Creating a rational number r1 = p1 / p2
    Rational r1(p1, p2);

    // Print the rational expression
    r1.print();

    // Perform addition of two rational numbers
    Rational r2 = r1 + Rational(p1, p2);
    r2.print();

    return 0;
}
```

## Contributing

Contributions are welcome! If you find a bug or have a feature request, feel free to open an issue. If you'd like to contribute code, please fork the repository, create a new branch, and submit a pull request.

## License

This project is licensed under the MIT License.
