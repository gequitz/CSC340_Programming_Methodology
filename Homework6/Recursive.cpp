/* Gabriel Equitz, sfsu id: 915254839*/
/* csc 340 - homework 6*/

#include <iostream>
#include <string>
#include <cstdlib>
#include "Recursive.h"

using namespace std;

//Default constructor (initializes the elements of the aArray to zero)
Recursive::Recursive(){    
    aSize = 100;
    aArray[aSize];
    for (int i = 0; i < aSize; i++)
        aArray[i] = 0;
}

//Initializes the array according to the specified values
void Recursive::theArray(int myArray[], int nSize){
    aSize = nSize;
    for (int i = 0; i < nSize; i++)
        aArray[i] = myArray[i];
}

//Reverses the array 
void Recursive::reverseArrayOrder(int indx, int myArray[]){
    indx = indx - 1;
    if(indx == 0)
        cout << myArray[0] <<endl;
    else if (indx > 0){
        cout << myArray[indx] << " ";
        reverseArrayOrder(indx, myArray);
    }
}

//finds the maximum number in an array and the index of the maximum
void Recursive::maxArrayNum(int& max,  int& maxIndex,int index, int myArray[]){
    if(index<aSize){
        if(max<myArray[index]){
            max = myArray[index];
            maxIndex = index;
        }
        maxArrayNum(max ,  maxIndex,index+1, myArray);
    }   
}

//sorts the array using quick sort
void Recursive::quickSort(int myArr[], int lft, int rght) {
      int i = lft, j = rght; int tmp; int pivot = myArr[(lft + rght) / 2];
      
      while (i <= j) {
            while (myArr[i] < pivot)           
                  i++;
            while (myArr[j] > pivot)           
                  j--;
            if (i <= j) {
                  tmp = myArr[i];
                  myArr[i] = myArr[j];
                  myArr[j] = tmp;
                  i++;
                  j--;
            }
      }; 
      
      if (lft < j)
            quickSort(myArr, lft, j);
      if (i < rght)
            quickSort(myArr, i, rght);
      
     
}

void Recursive::swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
    
}

// finds k-smallest
int Recursive::kSmallest(int k,int myArr[], int l,int r)
{
    // k is smaller than the size of the myArray
	if (k > 0 && k <= r + 1)
	{
		// Partition the myArray 
		int p = aPartitionFunction(myArr, l, r);

		// If position is same as k return the pivot position
		if (p == k-1)
			return myArr[p];
		if (p > k-1) 
			return kSmallest(k, myArr, l, p-1);// If p>k-1, use recursion in the sub-Array
		
		return kSmallest(k,myArr, p+1, r); // If p<=k-1, use recursion in the sub-yArray
	}
	
    // If k is larger than number of elements in Array return the Array size
    return aSize;
}



// partition function
int Recursive::aPartitionFunction(int myArr[],int left,int right)
{
    int y = myArr[right], i = left;
	for (int j=left; j <= right-1; j++)
	{
		if (myArr[j] <= y)
		{
			swap(&myArr[i], &myArr[j]);
			i++;
		}
	}
	swap(&myArr[i],&myArr[right]);
	return i;
}




// Friend of Recursive that overloads the cout  << operator
ostream& operator<< (ostream& outA, Recursive a){
    
    for (int i = 0; i < a.aSize; i++){
        
            outA << a.aArray[i] << " ";   
       
    }
    outA <<  endl ;

    return outA;
} 

  