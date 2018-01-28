/* 
 * File:   VectorDouble.cpp
 * Author: Gabriel Equitz
 * sfsu id: 915254839
 *
 * Date: 11/15/2016 
 */

#include "Vector_double.h"

// constructor that initializes the vector length to a default of 100
VectorDouble::VectorDouble(){
    vectorLength = 100;
    numbElements = 0;
    myArray = new double[vectorLength];
}

// Initiates the vector to a specified size
VectorDouble::VectorDouble(int size){
    numbElements = 0;
    vectorLength = size;    
    myArray = new double[vectorLength];
}

// copy constructor (copies a vector to another one)
VectorDouble::VectorDouble(VectorDouble &Vec){
    numbElements = Vec.numbElements;
    vectorLength = Vec.vectorLength;    
    myArray = new double[vectorLength];
    for(int i = 0; i < numbElements; ++i){
        myArray[i] = Vec.myArray[i];
    } 
}

// Destructor
VectorDouble::~VectorDouble(){
    delete myArray;
}

// returns  maximum number elements that the vector can store
int VectorDouble::capacity(){
    return vectorLength;
}

// tests if the vector container is empty
bool VectorDouble::empty(){
    return numbElements == 0;
}

// Adds a number to the end of the vector
void VectorDouble::insert(int aIndex, double value){
    
    
    // if vector is full, resize by 1
    if(numbElements == vectorLength){
        resize( vectorLength  + 1);
    } 
    
    // copy the elements of the arrays shifting one unit
    for(int i = numbElements; i > aIndex; --i){
        myArray[i] = myArray[i - 1];
    } 
    //insert the element at the index
    myArray[aIndex] = value;
    numbElements++;
    
    // if the aIndex is greater than the number of elements print an error message and exit
    if(aIndex > numbElements){      
        
        return;
    } 
}

// deletes the element at the end of the vector
bool VectorDouble::pop_back(){
    if(numbElements > 0){
        numbElements--;
        return true;
    } 
    else{
        return false;
    } 
}

// adds an element to the end of the vector
void VectorDouble::push_back(double aValue){
    if(numbElements == vectorLength){
        resize(vectorLength + 1);
    } 
    myArray[numbElements++] = aValue;
}

// resizes the vector
void VectorDouble::resize(int aSize){
    vectorLength = aSize;
    if(numbElements > vectorLength){
        numbElements = vectorLength;
    } 
    double *aArray = new double[vectorLength];
    for(int i = 0; i < numbElements; ++i){
        aArray[i] = myArray[i];
    } 
    myArray = aArray;
    delete aArray;   
    aArray = NULL;   
               
}

// shrink to fit (discard excess capacity)
void VectorDouble::shrink_to_fit(){
    resize(numbElements);
}

// returns the number of elements stored in the vector
int VectorDouble::size(){
    return numbElements;
}

ostream &operator <<(ostream& outV, VectorDouble Vec){
    for(int i = 0; i < Vec.numbElements; ++i){
        outV << Vec.myArray[i] << " ";
    } 
    cout << endl;
    return outV;
}




