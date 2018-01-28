/*
 *Gabriel Equitz 
 *sfsu id: 915254839
 * employee.cpp
 */


//File name--student.cpp: implementation file for the Employee class
#include "person.h"
#include "employee.h"
#include <stdlib.h>

//destructor
Employee::~Employee()
{
   if (salaryIncrease != NULL ){
      delete [] salaryIncrease;
   }
}

//default constructor
Employee::Employee():Person()
{
   //call the constructor of the base class to initialize the inherited members
   
   
   yearEmployment = 2000; 
   currentSalary = 50000;
   baseSalary = 40000;
   num_salaryIncrease = 3;
   salaryIncrease = NULL; //array
}

//a second constructor
Employee::Employee(int new_id, string new_name,  int yE, int cS, int bS):Person(new_id, new_name),yearEmployment(yE),currentSalary(cS),baseSalary(bS),num_salaryIncrease(0),salaryIncrease(NULL) 
{
 //call the corresponding constructor in the 
 //base class to initialize the inherited members
 /*  
   yearEmployment = yE;
   baseSalary = bS;
   currentSalary = cS;
   num_salaryIncrease = 0;
   salaryIncrease = NULL;   
 */
}

//copy constructor
Employee::Employee(const Employee & std):Person(std) //call the copy constructor of the base class
{
   
    yearEmployment = std.yearEmployment;
    currentSalary = std.currentSalary;
    baseSalary = std.baseSalary;
    num_salaryIncrease = std.num_salaryIncrease;
    if (num_salaryIncrease <= 0)
       salaryIncrease = NULL;
    else{ //allocate space to *grades and copy the grades from std
       (*this).salaryIncrease = new double [ num_salaryIncrease ];
       if (salaryIncrease == NULL ){
           cerr<< "Student:Student(const Student &): Memory allocation error\n";
           exit( -1 );
       }
       for (int i=0; i<num_salaryIncrease; i++)
           salaryIncrease[ i ] = std.salaryIncrease[ i ];
    }
}


int Employee::get_yearEmployment() const
{
    return yearEmployment;
}

int Employee::get_currentSalary() const
{
    return currentSalary;
}

int Employee::get_baseSalary() const
{
    return baseSalary;
}

int Employee::get_num_salaryIncrease() const
{
    return num_salaryIncrease;
}

double Employee::get_salaryIncrease( int i) const
{
    if (i<1 || i>num_salaryIncrease) 
       return -1.0; //non-existent salary increase
    else
        return salaryIncrease[ i-1 ];
}

void Employee::set_yearEmployment(int yE)
{
   yearEmployment = yE;
}

void Employee::set_currentSalary(int cS)
{
   currentSalary = cS;
}



void Employee::set_baseSalary(int bS)
{
   baseSalary = bS;
}

void Employee::set_num_salaryIncrease(int num)
{
   num_salaryIncrease = num;
   if (num > 0){
      salaryIncrease = new double [ num ];
      if (salaryIncrease == NULL ){
         cerr<< "Employee:set_num_salaryIncrease(int ): Memory allocation error\n";
         exit( -1 );
      }
      for (int i=0; i<num; i++)
         salaryIncrease[ i ] =0.;
   }
}

void Employee::set_salaryIncrease(int i, double sI)
{
    if (i>=1 && i<=num_salaryIncrease) 
       salaryIncrease[ i-1 ] = sI;
}

void Employee::operator=( const Employee & rhs)
{
     (*this).Person::operator=(rhs);
     currentSalary = rhs.currentSalary;
     baseSalary = rhs.baseSalary;
     yearEmployment = rhs.yearEmployment;
     if (num_salaryIncrease != rhs.num_salaryIncrease){
        delete [] salaryIncrease;
        num_salaryIncrease = rhs.num_salaryIncrease;
        salaryIncrease = new double[ num_salaryIncrease ];
        if (salaryIncrease == NULL){
           cerr<< "Employee:operator=(const Employee &): Memory allocation error\n";
           exit( -1 );
        }
        for (int i=0; i<num_salaryIncrease; i++)
           salaryIncrease[ i ] = rhs.salaryIncrease[ i ];
     }  
}

ostream& operator<<(ostream& out, const Employee& std)
{
   
   
   out << "------------------------------\n";
   out << "id=" << std.get_id() <<endl;
   out   << "name=" << std.get_name() << endl;
   
   out << "#emails=" <<std.get_num_emails()<<endl;
   out << " 1st email=" << std.getEmail(0)<<endl;
   out << "Year Employment="<< std.yearEmployment <<endl;
   out << "Base Salary="<<std.baseSalary<<endl;
   out << "Current Salary ="<<std.currentSalary<<endl;
   out << "#Salary Increase ="<< std.num_salaryIncrease <<endl; 
   for (int i=1; i<=std.get_num_salaryIncrease(); i++)
        out << "salaryIncrease[" << i <<"]=" << std.salaryIncrease[i-1] <<" ";
   out <<endl;
   out << "------------------------------\n";  
   
   return out;    
}


void Employee::output() const
{
     
      
   cout << "------------------------------\n";
   cout << "id=" << get_id() <<endl;
   cout   << "name=" <<  get_name() << endl;//private-is-private rule 
   
   cout << "#emails = " <<get_num_emails()<<endl;
   cout << " 1st email = " << getEmail(0)<<endl;
   cout << "Year Employment = "<<yearEmployment<<endl;
   cout << "Base Salary = "<<baseSalary<<endl;
   cout << "Current Salary = "<<currentSalary<<endl;
   cout << "Number Salary Increase = "<< num_salaryIncrease <<endl; 
   for (int i=1; i<=num_salaryIncrease; i++)
        cout << "Salary Increase [" << i <<"]=" << salaryIncrease[i-1] <<" ";
   cout <<endl;
   cout << "------------------------------\n";  
   
}


