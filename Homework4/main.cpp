/* csc 340*/
/* Gabriel Equitz */
/* sfsu id: 915254839 */


// Polynomial main

#include "Polynomial.h"
#include <iostream>
#include <cstdlib>


using namespace std;


int main(int argc, char** argv) {
   
    
  int optionNumb = 0;
  int aDegree;
  int aChoice;
  
  
  cout << "To use pre-built tests, type 1 and Enter, otherwise type 2 and Enter " << endl;
  
  cin >> aChoice;
  
  if (aChoice == 1) {
      Polynomial p1, p2(3);
      
      cout << "Testing the default constructor that has no argument " << endl ;     
      cout << " p1 = " << p1  << endl;
      
     
      
      cout << "\nTesting the default constructor that has an integer argument " << endl ;      
      cout << " p2 = " << p2  << endl;
      
      double p3_coeffs[] = {1.0, 3.0, -2.0};
      double p4_coeffs[] = {2.0, -5.0, 3.0, 4.0, 7.0};     
  
      
      Polynomial p3(2,p3_coeffs);
      
      cout << "\nTest to get the coefficient of a term of the polynomial " << endl;
      cout << " term  =  " << "2" << endl;
      cout << " Polynomial  =  " << p3 << endl;
      cout << " Coefficient  =  " << p3.getCoeff(2) << endl;
      
      Polynomial p4(4,p4_coeffs);    
              
      
            
      cout << "\nTesting the sum of two polynomials" << endl;
      cout << "First Polynomial: p3 =  " << p3 << endl;
      cout << "Second  Polynomial:  p4 =  " << p4 << endl;      
      cout << "Sum of the two polynomials " << endl;
      cout << "p3 + p4 = " << p3 + p4;
      
      
      cout << "\nTesting the subtraction of two polynomials" << endl;
      cout << "First Polynomial: p3 =  " << p3 << endl;
      cout << "Second  Polynomial:  p4 =  " << p4 << endl;      
      cout << "Subtraction of the two polynomials " << endl;
      cout << "p3 - p4 = " << p3 - p4;
      
      cout << "\nTesting the negation of a polynomial" << endl;
      cout << "Polynomial: p3 =  " << p3 << endl;          
      cout << "Negation of the polynomial " << endl;
      cout << "-p3 = " << -p3;
      
      cout << "\nTesting the division of a polynomial by a constant = 3.0" << endl;
      cout << "Polynomial: p3 =  " << p3 << endl;          
      cout << "Division of the polynomial by 3 " << endl;
      cout << "p3/3.0 = " << p3/3.0;
      
      cout << "\nTesting changing the coefficient of a term in the polynomial" << endl;
      cout << "Changing the coefficient of degree 2 do 5.7: p3 =  " << p3 << endl;
      p3.setCoeff(2, 5.7);
      cout << "New polynomial: " << p3 << endl;   
      
  }
  
  else {
  
  string aOptions = 
          "\n Enter -1 to exit or select one of the options below (1, 2, etc.)."
          "\n1 Test initialization of polynomial to 0.\n"
          "\n2 Test for initialization of the polynomial with given degree.\n"
          "\n3 Enter your polynomial.\n"
          "\n Get the coefficient of a term in your polynomial."
          "\n Change the coefficient of a term in your polynomial."
          "\n Negate the coefficients of your polynomial."
          "\n Divide your polynomial by a constant.\n"
          "\n4 Enter two polynomials to sum and to subtract them.\n"  ;      
          
         
    
  // use -1 as a sentinel to stop the program
    while(optionNumb != -1){
        cout << aOptions << endl;
        cin >> optionNumb;
        
        // will initialize a polynomial to the default of zero
        if (optionNumb == 1){
            cout << "\nTesting the default constructor" << endl;
            Polynomial myPoly;
            cout << myPoly << endl;
        } 
        else if (optionNumb == 2) {      
            int myDegree;
            cout << "\nTesting the constructor with an arbitrary degree. " << endl;
            cout << "\nEnter integer argument, that is, the degree of the polynomial." << endl;
            cin >>  myDegree;
            Polynomial myPoly1(myDegree);
            cout << myPoly1 << endl;
        } 
        
        else if (optionNumb == 3) {  
            int aDegree;
            cout << "\nTest to input a polynomial" << endl;
              cout << "\nEnter degree of the polynomial (that is, the largest exponent) :";
              cin >> aDegree;
            
          
            Polynomial myPoly2(aDegree);
            myPoly2.setPolynomial();
            cout << "\nPolynomial : " << myPoly2;
            
            cout << "\nTest to negate the coefficients of your polynomial" << endl;
            cout << "\nCurrent Polynomial : " << myPoly2;
            cout << "\nNegated Polynomial : " << -myPoly2;
            
            cout << "\nTest to get the coefficient of a term in your polynomial" << endl;
            int aExponent;
            double aCoefficient;
            
            cout << "\nEnter the degree of the term you want to get the coefficient for. " << endl;
            cin >> aExponent;                      
            cout << "\nPolynomial : " << myPoly2.getCoeff(aExponent);  ;
        
            cout << "\nTest to change the coefficient of a term in your polynomial" << endl;        
            
            cout << "Enter the degree of the term you want to change " << endl;
            cin >> aExponent;
            cout << "Enter the new coefficient " << endl;
            cin >> aCoefficient;
            
            myPoly2.setCoeff(aExponent, aCoefficient);
            cout << "Polynomial : " << myPoly2;
            
            cout << "\nTest to divide your polynomial by a constant" << endl;            
            double aConstant;
            cout << "Enter the constant you want to divide your polynomial " << endl;
            cin >> aConstant;
            
            cout << "Polynomial : " << myPoly2/aConstant;
            
        }
        else if (optionNumb == 4) {      
            int aDegree;
            cout << "\nTest sum two polynomials " << endl;
            cout << "Enter degree of the first polynomial (that is, the largest exponent) :\n";
            cin >> aDegree;           
          
            Polynomial myPoly3(aDegree);
            myPoly3.setPolynomial();
            cout << "First Polynomial : " << myPoly3;
            
            
            cout << "\n Enter degree of the second polynomial (that is, the largest exponent) :\n";
            cin >> aDegree;           
          
            Polynomial myPoly4(aDegree);
            myPoly4.setPolynomial();
            cout << "\n Second Polynomial : " << myPoly4;
            
            cout << "\n Sum of the two polynomials: " <<  myPoly3 + myPoly4;
            cout << "\n Subtraction of the two polynomials: " << myPoly3 - myPoly4;
        } 
        
       
    }
  }
  
  return 0;
  
}
   
   

