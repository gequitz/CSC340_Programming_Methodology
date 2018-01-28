/*
 *Gabriel Equitz 
 *sfsu id: 915254839
 * employee.h
 */

//File name--employee.h: declare employee as a derived class of Person
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "employee.h"

class Employee:public Person
{
      public:
         ~Employee(); //destructor
         Employee(); //default: yearEmployment = 2000; currentSalary = 50000; baseSalary=40000
         Employee(int new_id, string new_name,int yearEmployment, int currentSalary, int baseSalary ); 
         Employee(const Employee& std); //copy constructor: std -->*this
         void operator=(const Employee& rhs); //rhs --> *this 
         int get_yearEmployment() const; 
         int get_currentSalary() const; 
         int get_baseSalary() const; 
         int get_num_salaryIncrease() const; //return num_salaryIncrease
         double get_salaryIncrease(int i) const; 
         void set_yearEmployment(int ye); 
         void set_currentSalary(int cs);
         void set_baseSalary(int bs); 
         void set_num_salaryIncrease( int num); 
         void set_salaryIncrease(int i, double si); 
      
         friend ostream & operator <<( ostream & out, const Employee& std);
         virtual void output() const; //print out a employee's info.
      private:
         int yearEmployment; 
         int currentSalary;
         int baseSalary;
         int num_salaryIncrease;
         double *salaryIncrease; //array
};

#endif /* EMPLOYEE_H */

