
/* 
 * File:   main.cpp
 * Author: Gabriel Equitz
 * sfsu id: 915254839
 *
 * Date: 11/15/2016 
 */

#include <cstdlib>
#include <string>
#include "Vector_double.h"

using namespace std;

int main(int argc, char** argv) {
    VectorDouble myVector;
    VectorDouble myVector1;
    int index;
    int choiceNumb = 0;
    double aValue;
    int nSize;
    string vecOptions = 
            "1. Enter your vector. \n"
            "2. Check the capacity of the vector. \n"
            "3. Check if the vector is empty \n"
            "4. Insert an element at a given index. \n"            
            "5. Delete an element from the end of the vector (Pop_back). \n"            
            "6. Insert an element at the end of the vector (Push_back). \n"
            "7. Resize the Vector \n"
            "8. Shrink to fit \n" 
            "9. Check size of the vector \n"                       
            "10. Display the vector\n"
            "(-1 to exit)\n\n"
            "Select your option: ";
    
    while(choiceNumb != -1){
        cout << endl << vecOptions << endl;
        cin >> choiceNumb;
        
        
            if (choiceNumb == 1){
                cout << "Enter the size of your array. ";
                cin >> nSize;
                cout << "Enter the elements of your array. ";
                for (int i =0; i<nSize; i++){
                 cin >> aValue;
                 myVector.push_back(aValue);
                }
            }
            
                
            else if (choiceNumb == 2){
                cout << "The capacity of the vector is " << myVector.capacity() << endl;
            }
                
            else if (choiceNumb == 3){
                if(myVector.empty()){
                    cout << "The vector is empty." << endl;
                }
                else{
                    cout << "The vector is not empty." << endl;
                }
            }
                
            else if (choiceNumb == 4){
                
            
                cout << "Enter index: ";
                cin >> index;
                cout << "Enter the  value of the element you want to add: ";
                cin >> aValue;
                
                myVector.insert(index, aValue);
            }
                
            else if (choiceNumb == 5){
                if(myVector.pop_back()){
                    cout << "Item removed successfully." << endl;
                }
                else{
                    cout << "Vector is empty. Cannot remove." << endl;
                }
            }
            else if (choiceNumb == 6){                
            
                
                cout << "Enter the  value of the element you want to insert at the end: ";
                cin >> aValue;                
                myVector.push_back(aValue);
            }
                
            else if (choiceNumb == 7){
                cout << "Enter size of the Vector to resize to: ";
                cin >> choiceNumb;
                myVector.resize(choiceNumb);
            }
                
            else if (choiceNumb == 8){
                myVector.shrink_to_fit();
                cout << "Vector has been shrunk. " << endl;
            }
             
             else if (choiceNumb == 9){
                cout << "The vector size is " << myVector.size() << endl;
            }
            else if (choiceNumb == 10){
                cout << "Your vector is: " << myVector << endl;
            }
                
            else if (choiceNumb == -1){
                return 0;
            }    
            else
                cout << "Please choose a valid option. " << endl;                
        
    }
    return 0;
}


