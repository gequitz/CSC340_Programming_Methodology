/* 
 * File:   main.cpp
 * Author: Gabriel Equitz
 * sfsu id : 915254839
 * Created on November 27, 2016, 5:56 PM
 */

#include "linkedList_structNode.h"
#include <iostream>
#include <cstdlib>
#include <string>


using namespace std;


int main(int argc, char** argv) {
    int choiceNumb;
    int nSize;
    int aValue;
    List list1, list2;
    string listOptions = 
            "1. Enter your list. \n"
            "2. Retrieve an item from the list (assumes list is of integers,  0  < index <= list size). \n"
            "3. Remove an item from the list (0  < index <= list size). \n"
            "4. Tell the size of the list. \n"                       
            "5. Revert the order of the elements in the list. \n" 
            "6. Copy your list to another one. \n" 
            "(-1 to exit)\n\n"
            "Select your option: ";
    while(choiceNumb != -1){
        cout << endl << listOptions << endl;
        cin >> choiceNumb;
        
        
            if (choiceNumb == 1){
                cout << "Enter the size of your list. ";
                cin >> nSize;
                cout << "Enter the elements of your list. ";
                for (int i =0; i<nSize; i++){
                 cin >> aValue;
                 list1.insert((i + 1), aValue);
                }
                // Printing list1
                cout << "list1 is: " << list1 << endl;
            }
        
            else if (choiceNumb == 2){
                //retrieve an item from the list
                int aIndx;
                int aElement;
                cout << "Enter the index of element. ";
                cin >> aIndx;                
                list1.retrieve(aIndx, aElement);
                cout << "Your element is: " << aElement;
            }
            
            else if (choiceNumb == 3){
                //removes an item from the list
                int aIndx;
                cout << "Enter the index of element. ";
                cin >> aIndx;                
                list1.remove(aIndx);
                cout << "New list: " << list1;
            } 
        
            else if (choiceNumb == 4){
                //tell the list size
                
                cout << "List size is: " << list1.getLength() << endl;
            }
            else if (choiceNumb == 5){
                // Reverse first list and print it
                cout << "Reverse first list and print it\n";
                list1.reverseList(list1);
                cout << "Reversed list1: " << list1;
            }
            else if (choiceNumb == 6){
                //copy list1 to list2
                list2 = list1;
                cout << "list2 is: " << list1 << endl;
            }
        
            
            
    }
  
    
    return 0;
}

