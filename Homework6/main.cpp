
/* 
 * File:   main.cpp
 * Author: Gabriel Equitz, sfsu id: 915254839 )
 * Homework 6 - CSC340 
 * Created on Nov 2, 2016
 */


#include <iostream>
#include <string>
#include <cstdlib>
#include "Recursive.h"

using namespace std;

int main(int argc, char** argv) {
    
    int iSize = 100;
    int option;
    int myArray[iSize];
    Recursive objArray;
    
    cout << "Enter your array size (from 1 to 100): \n";
    cin >> iSize;
    
    //continue asking if the array is out of bounds
        while (iSize < 1 || iSize > 100){
            cout << "Size must be between 1 - 100" <<endl;;
            cout << "Reenter size: ";
            cin >> iSize;
        }
        cout << "Enter the integers of your array (example: 40 52 33): ";
        for (int i = 0; i < iSize; i++)
            cin >> myArray[i];
        
        objArray.theArray(myArray, iSize);
        
        
    
    //options
    while (option != 5){
    cout << "Options: \n"
            "0.Prints the array.\n"
            "1.Outputs the array in reverse order.\n"
            "2.Finds the largest element of the array and its index.\n"
            "3.Finds the k-th smallest element in the array.\n"
            "4.Sorts the array in increasing order using QuickSort\n"
            "5.Exits" << endl;
    cout << "Choose your option: ";
    cin >> option;
    
    //Error if the option is out of range
    while (option < 0 || option > 5){
        cout << "Options must be between 0 and 5: \n"
            "0.Prints the array.\n"
            "1.Outputs the array in reverse order.\n"
            "2.Finds the largest element of the array and its index.\n"
            "3.Finds the k-th smallest element in the array.\n"
            "4.Sorts the array in increasing order using QuickSort\n "
            "5.Exits" << endl;
    cout << "Choose your option: ";
    cin >> option;
    }
    
    //prints the array using overload cout operator
    if (option == 0){
        cout << "Prints the array: ";
                
                cout << "Your array is: " << objArray;
                
    }
    
    //array in reverse order
    if (option == 1){
        cout << "Array in Reverse Order: ";
                objArray.reverseArrayOrder(iSize, myArray);
    }
    
    //largest element of the array and its index
    if (option == 2){
       
        int iMax = 0;
        int iIndex = 0;
        int iTemp = 0;
        
        objArray.maxArrayNum(iMax,  iIndex,iTemp, myArray);
        cout << "Maximum Element : " << iMax << " at Index "  << iIndex <<endl;
    }
    
    //k-th smallest element 
    if(option == 3){
       
        int k; 
        
        int iRight = iSize;
        cout << "What is the k-th smallest number you want to find: ";
        cin >>k;
        
        //Error if the option is out of bounds
        while (k < 0 || k > iSize){
           cout << "Error - out of bounds (enter a number from 0 to " << iSize << "!" << endl;
           cout << "What is the k-th smallest number you want to find: "; 
           cin >>k;
        }
       
        cout << "The smallest kth-element is : " << objArray.kSmallest(k, myArray, 0, iRight-1) << endl;
        
      
    }
    
    //sorts the array using quick sort
    if (option == 4){
       
        int iLeft = 0;
        int iRight = iSize-1;
        
        objArray.quickSort(myArray, iLeft, iRight);
        cout << "Sorted Array : " ;
       
        for (int i =0; i<iSize; i++){
            cout << myArray[i] << " ";
        }
        
        cout << endl;
       
    }
    
    }
    return 0;
}
