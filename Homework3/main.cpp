//
//  Homework3.cpp
//  
//  Description: Program that inserts the number 2777 through 2781 between the 9000-th and 9001 position
//  Author: Gabriel Equitz
//  SFSU id: 915254839
//  CSC340
//  Date : 09/26/2016
//

#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>



using namespace std;

int main () {
    
  /*  int numbStart = 2777; // first number to be inserted
    int numbEnd = 2781; // last number to be inserted
    int insertAtNumber = 9000; // position where to insert the numbers */
    
    int numbStart = 20; // first number to be inserted
    int numbEnd = 30; // last number to be inserted
    int insertAtNumber = 10; // position where to insert the numbers
    int maxNumb = 10000; //maximum vector size
    
    int nextNumber; //variable to store numbers that will be added
    
    //opens "file1.txt"
    fstream aFile("file2.txt", ios::in | ios::out);
    
    // checks if the file opens correctly
    if (!aFile){
        cout << "erro in opening file1.txt";
    } 
    
    else{       
        
        vector <int> tempNumbers(maxNumb);
        
        int count1 = 0;
       
        //saves the numbers to a vector 
        while (aFile.good() ) { 
          
             aFile >> tempNumbers[count1];
             cout << tempNumbers[count1] << endl;
           
            count1++;
            
        }         
        
        //point to the place of inserting 
        aFile.clear();
        aFile.seekp(5*insertAtNumber);   
        
        
        // pushes the numbers from numbStart to numbEnd 
        nextNumber = numbStart;
        while (aFile.good() && nextNumber <= numbEnd){
            aFile.width(4);
            
            aFile << nextNumber << endl;
            nextNumber++;
        } 
        
       
       // copies the tempNumber vector back to the output file beginning at the insertion point
        for (int i =insertAtNumber; i <count1; i++){
            if (tempNumbers[i] != 0){
                aFile.width(4);
                aFile << tempNumbers[i] << endl;
            }
        } 
        
        aFile.close(); // closes file
    } 
    
    return 0;    
}
