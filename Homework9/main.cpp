/*
 *Gabriel Equitz 
 *sfsu id: 915254839
 * main_employee
 */

#include "person.h"
#include "employee.h"
#include <cstdlib>


using namespace std;


int main(int argc, char** argv) {
    
    
    cout << "Using pre-built tests " << endl;
    cout << "Modifications can be done in the code if further tests are needed. " << endl;
    
    
    // basic inputs for person and student
    int aId = 101;    
    string  aName = "Mary";
    int aYearEmployment = 2010;
    int aCurrentSalary = 35000;
    int aBaseSalary = 20000;
    
    Person mary_p( aId, aName);  //Mary as a person
    
    cout << "Testing output function " << endl;
    cout << "Mary as a person " << endl;
        
    mary_p.output(); //person version
    
    
    cout << "Testing the constructor for student and the output function" << endl;
    Employee mary_e( aId, aName,  aYearEmployment, aCurrentSalary, aBaseSalary); //Mary as a Student
    mary_e.output(); //student version
        
    cout << "Testing cout function" << endl;
    cout << "Mary as an employee " << endl;
    
    cout << mary_e ;  
    
    
    //testing the mutators
    cout << "Testing the mutators " << endl;
    
    //set email, year of employment, base salary, current salary,
    // number of salary increase and salary increase
    mary_e.add_email("mary@gmail.com");   
    mary_e.set_yearEmployment(2009);
    mary_e.set_baseSalary(34000);
    mary_e.set_currentSalary(55000);
    mary_e.set_num_salaryIncrease(3);
    mary_e.set_salaryIncrease(1, 0.1);
    mary_e.set_salaryIncrease(2, 0.15);
    mary_e.set_salaryIncrease(3, 0.12);
    
    cout << mary_e;
    
    cout << "Testing the accessors for Mary's employee" << endl;
    
    cout << "Mary's Id " <<  mary_e.get_id() << endl;
    cout << "Mary's Name " <<  mary_e.get_name() << endl;
    cout << "Mary's First Email " <<  mary_e.getEmail(0) << endl;
    cout << "Mary's Year of Employment  " <<  mary_e.get_yearEmployment() << endl;
    cout << "Mary's Base Salary " <<  mary_e.get_baseSalary() << endl;
    cout << "Mary's Current Salary " <<  mary_e.get_currentSalary() << endl;
    cout << "Mary's Number of Salary Increase " <<  mary_e.get_num_salaryIncrease() << endl;
    int temp1 = mary_e.get_num_salaryIncrease() ;
    for (int i=0 ;i < temp1; i++)
     cout << "Mary's Salary Increase " <<  mary_e.get_salaryIncrease(i+1) << endl;
    
    cout << "------------------------" << endl;
    //copy mary_e to mary_b to test polymorphism
    cout << "Test copying  mary_e to another employee Mary_b" << endl;
    Employee mary_b = mary_e;
    
    cout << "cout Mary_b (copy of mary_e) " << endl;
    mary_b.output();
    
    cout << "copying mary_e to person1 (using pointers) "  << endl;  
    Person & person1 = mary_e;    
   
    cout << " person1 output " << endl;
    person1.output();  // person output
    
    cout << "output of mary_p and mary_e as persons" << endl;
    mary_p.output(); 
    mary_e.Person::output();//person version 
    
    
                
    return 0;
}

