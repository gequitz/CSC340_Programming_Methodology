/* Gabriel Equitz, sfsu id: 915254839*/
/* csc340 - homework 6*/

#ifndef RECURSIVE_H
#define RECURSIVE_H

#include <cstdlib>
#include <iostream>
#include <string>


using namespace std;

class Recursive{
    //private  functions and variables 
    private: 
        int aSize;
        int aArray[100];
        
        int aPartitionFunction(int arr[], int p, int r);
        
        void swap(int *x, int *y);
    
    // public functions 
    public:
        //default constructor
        Recursive();
        
        //public functions
        void theArray(int myArray[], int nSize);
        void reverseArrayOrder(int index, int myArray[]);
        void maxArrayNum(int& max,  int& maxIndex,int index, int myArray[]); 
        void quickSort(int myArray[], int left, int right);
        int kSmallest(int k, int arr[], int left, int right);
        
        
         friend ostream& operator<<(ostream& outS, const Recursive a); //good
         
        
};


#endif /* RECURSIVE_H */

