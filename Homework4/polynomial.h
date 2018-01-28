/* csc 340*/
/* Gabriel Equitz */
/* sfsu id: 915254839 */

// header function for Polynomial
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H


#include <iostream>

//using namespace std;

class Polynomial
{    
 public:
   static const int MAX_DEGREE = 200;  
   Polynomial();
   Polynomial(int degree);
   Polynomial(int degree, double coefficients[]);
  // Polynomial operator+(const Polynomial other) const ;
   friend Polynomial operator+(const Polynomial lhs,const Polynomial rhs)  ;
   Polynomial operator-(const Polynomial other) const;
   Polynomial operator-() const;
   Polynomial operator/(double divisor) const;
  
   friend std::ostream& operator<<(std::ostream &cout, Polynomial p);
   
   int degree();
   double getCoeff(int i);
   void setCoeff(int i, double aCoeff);
   void setDegree(int i);
   void setPolynomial();
  
 private:
   int aDegree;
   double aCoefficient[MAX_DEGREE+1];
   
   
};

//ostream& operator<<(std::ostream &cout, Polynomial p);

#endif /* POLYNOMIAL_H */




















