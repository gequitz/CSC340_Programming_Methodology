/* 
 * File:   Vector_double.h
 * Author: Gabriel Equitz
 * sfsu id: 915254839
 * Homework 7
 * Date: 11/15/2016 
 */

#ifndef VECTOR_DOUBLE_H
#define VECTOR_DOUBLE_H

#include <iostream>

using namespace std;

class VectorDouble{
private:
    // Pointer  vector 
    double *myArray;
    
    // number of elements of the array
    int numbElements;
        
    // Vector size
    int vectorLength;
    
    
public:
        
    // Default constructor that initializes the array to  100 elements
    VectorDouble();
    
    // Constructor that initializes array to a given size
    VectorDouble(int size);
    
    // Constructor that copies another vector
    VectorDouble(VectorDouble &vector);
    
    // Destructor of VectorDouble class
    ~VectorDouble();
    
    // returns the number of elements of doubles that the vector can store.
    int capacity();
    
    // tests if the vector container is empty.
    bool empty();       
    
    // inserts an element into the vector in a given location
    void insert(int ind1, double value);  
    
    // deletes an element at the end of the vector
    bool pop_back();
    
    // adds an element at the end of the vector
    void push_back(double value);
    
    // specifies a new size for the vector.
    void resize(int newsize);
    
    // discards excess capacity
    void shrink_to_fit();
    
    // returns the number of elements stored in the vector.
    int size();
    
    // Friend of the VectorDouble class to overload the << operator
    friend ostream &operator <<(ostream &out, VectorDouble V);
};


#endif /* VECTOR_DOUBLE_H */

