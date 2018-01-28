/* csc 340*/
/* Gabriel Equitz */
/* sfsu id: 915254839 */

// Polynomial class

#include "Polynomial.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//default constructor
Polynomial::Polynomial()
{
  aDegree= 0;
  aCoefficient[0] = 0.0;
}

//constructor with one parameter that indicates gives error if degree is larger than 150
Polynomial::Polynomial(int degree)

{
    
    if (degree > MAX_DEGREE){
        cout << "error: degree above the limit allowed of " << MAX_DEGREE << endl;
        exit(EXIT_FAILURE);
    }
    else{
      aDegree = degree;
      for (int i=0; i < degree; i++){
         aCoefficient[i]   = 0.0;
      }
        
    }
    
  
}

//constructor that initializes the degree and coefficients
Polynomial::Polynomial(int degree, double coefficients[])
{
  aDegree = degree;
  for(int i=0; i<=degree; i++) {   
      aCoefficient[i] = coefficients[i];     
   }
}

//accessor for getting the degree
int Polynomial::degree()
{
  return aDegree;
}

//mutator that sets the coefficient of the i-th term to aCoeff
void Polynomial::setCoeff(int i, double aCoeff)
{
  aCoefficient[i]=aCoeff;
}

//sets the degree of polynomial
void Polynomial::setDegree(int i)
{
  aDegree=i;
}

//accessor for the coefficient of the term with i-th power
double Polynomial::getCoeff(int i)
{
  return aCoefficient[i];
}

//adds two polynomials
/*Polynomial Polynomial::operator+(const Polynomial rhs) const
{
    int max_degree = max(aDegree, rhs.aDegree);
    double aResult[max_degree+1];
    for(int i=0; i<=max_degree; i++){    
      aResult[i] = aCoefficient[i] + rhs.aCoefficient[i];
    }

    return Polynomial(max_degree, aResult);
}*/

Polynomial operator+(const Polynomial lhs,const Polynomial rhs) 
{
    int max_degree = max(lhs.aDegree, rhs.aDegree);
    double aResult[max_degree+1];
    for(int i=0; i<=max_degree; i++){    
      aResult[i] = lhs.aCoefficient[i] + rhs.aCoefficient[i];
    }

    return Polynomial(max_degree, aResult);
}

//subtracts two polynomials
Polynomial Polynomial::operator-(const Polynomial rhs) const
{
    int max_degree = max(aDegree, rhs.aDegree);
    double aResult[max_degree+1];
    for(int i=0; i<=max_degree; i++) {  
      aResult[i] = aCoefficient[i] - rhs.aCoefficient[i];
    }
    return Polynomial(max_degree, aResult);
}

//negates the polynomial
Polynomial Polynomial::operator-() const
{
    int max_degree = aDegree;
    double aResult[max_degree+1];
    for(int i=0; i<=max_degree; i++) {  
      aResult[i] = -aCoefficient[i] ;
    }
    return Polynomial(max_degree, aResult);
}

// divides polynomial by a constant
Polynomial Polynomial::operator/(double divisor) const
{
    int max_degree = aDegree;
    double aResult[max_degree+1];
    if (divisor == 0.){
     cout << "error : division by zero.  " << endl;     
     for(int i=0; i<=max_degree; i++) {        
        aResult[i] = 0. ;    
      }
    } 
    else{
      for(int i=0; i<=max_degree; i++) {        
        aResult[i] = aCoefficient[i]/divisor ;    
      }
    }
    return Polynomial(max_degree, aResult);
}

// overload operator cout  << to output the polynomial
ostream& operator<<(std::ostream &out, Polynomial p)
{    
  for(int i=0; i<p.degree(); i++)
    {      
      if (p.getCoeff(i) != 0.0)
          out << p.getCoeff(i) << "x^" << i << " + ";
     
      
    }    
  
  //if (p.degree() != 0.0)
    out << p.getCoeff(p.degree()) << "x^" << p.degree() << endl;
  return out; 
} 

//sets the polynomial
void Polynomial::setPolynomial(){
   
  //  cout << "Enter degree of the polynomial (that is, the largest exponent) :\n";
  //  cin >> aDegree;
    double aCoeff;
    int aTerms;
    
  //  for (int i = 0; i < aDegree; i++){        
  //      aCoefficient[i] = 0.0;
  //  } 
    
    cout << "Enter the number of terms of the polynomial :\n";
    cin >> aTerms;
    int i;
    for (int j = 0; j < aTerms; j++){
        cout << "Enter the exponent of one term and then key Enter \n";
        cin >> i;
        cout << "Enter the coefficient that term and then key Enter  \n";
        cin >> aCoeff;        
        aCoefficient[i] =  aCoeff;        
    }   
} 














