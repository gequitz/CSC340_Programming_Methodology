/* 
 * File:   linkedList.cpp
 * Author: Gabriel Equitz
 * sfsu id : 915254839
 * Created on November 27, 2016, 5:56 PM
 */


#include "linkedList_structNode.h"    // header file
#include <iostream>

using namespace std;

List::List():size(0),head(NULL) //initializer or initialization segment
{
}

List::List(const List& aList)
: size(aList.size)
{
    if (aList.head == NULL){
        head = NULL;  // original list is empty
        size = 0;
    }
    else
    {  // copy first node
        head = new ListNode;
        head->item = aList.head->item;
        
        // copy rest of list
        ListNode *newPtr = head;  // new list pointer
        // newPtr points to last node in new list
        // origPtr points to nodes in original list
        for (ListNode *origPtr = aList.head->next;
             origPtr != NULL;
             origPtr = origPtr->next)
        {  newPtr->next = new ListNode;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        }  // end for
        
        newPtr->next = NULL;
    }  // end if
}  // end copy constructor

List::~List()
{
    //while (!isEmpty())
    //  remove(1);
    ListNode *curr=head;
    while (curr!=NULL){
        head = curr->next;
        delete curr;
        curr = head;
    }
    
}  // end destructor

bool List::isEmpty() const
{
    return size == 0;
}  // end isEmpty

int List::getLength() const
{
    return size;
}  // end getLength

List::ListNode *List::find(int index) const
{
    if ( (index < 1) || (index > getLength()) )
        return NULL;
    
    else  // count from the beginning of the list.
    {  ListNode *cur = head;
        for (int skip = 1; skip < index; ++skip)
            cur = cur->next;
        return cur;
    }  // end if
    
}  // end find

void List::retrieve(int index,
                    ListItemType& dataItem) const
throw(ListIndexOutOfRangeException)
{
    if ( (index < 1) || (index > getLength()) )
        throw ListIndexOutOfRangeException(
                                           "ListIndexOutOfRangeException: retrieve index out of range");
    else
    {  // get pointer to node, then data in node
        ListNode *cur = find(index);
        dataItem = cur->item;
    }  // end if
}  // end retrieve

void List::insert(int index, const ListItemType& newItem)
throw(ListIndexOutOfRangeException, ListException)
{
    int newLength = getLength() + 1;
    
    if ( (index < 1) || (index > newLength) )
        throw ListIndexOutOfRangeException(
                                           "ListIndexOutOfRangeException: insert index out of range");
    else
    {  // try to create new node and place newItem in it
        try
        {
            ListNode *newPtr = new ListNode;
            size = newLength;
            newPtr->item = newItem;
            
            // attach new node to list
            if (index == 1)
            {  // insert new node at beginning of list
                newPtr->next = head;
                head = newPtr;
            }
            else
            {  ListNode *prev = find(index-1);
                // insert new node after node
                // to which prev points
                newPtr->next = prev->next;
                prev->next = newPtr;
            }  // end if
        }  // end try
        catch (bad_alloc e)
        {
            throw ListException(
                                "ListException: memory allocation failed on insert");
        }  // end catch
    }  // end if
}  // end insert

void List::remove(int index) throw(ListIndexOutOfRangeException)
{
    ListNode *cur;
    
    if ( (index < 1) || (index > getLength()) )
        throw ListIndexOutOfRangeException(
                                           "ListIndexOutOfRangeException: remove index out of range");
    else
    {  --size;
        if (index == 1)
        {  // delete the first node from the list
            cur = head;  // save pointer to node
            head = head->next;
        }
        
        else
        {  ListNode *prev = find(index - 1);
            // delete the node after the node to which prev points
            cur = prev->next;  // save pointer to node
            prev->next = cur->next;
        }  // end if
        
        // return node to system
        cur->next = NULL;
        delete cur;
        cur = NULL;
    }  // end if
}  // end remove

List List::operator=(const List& rhs){
    // check if the list is empty
    if (!isEmpty()){
        ListNode *currNode = head;
        
        while (currNode != NULL) {
            head = currNode->next;
            delete currNode;
            currNode = head;
        } 
    } 
    // set size  list to rhs size
    size = rhs.getLength();
    
    if (size <= 0){
        head = NULL;
    } 
    
    else {        
        head = new ListNode;
        // copy first item
        head->item = rhs.head->item;
        
        // copy other items
        ListNode *aPtr = head;        
        
        for (ListNode *begPtr = rhs.head->next; begPtr != NULL; begPtr = begPtr->next) {
            aPtr->next = new ListNode;  
            aPtr = aPtr->next;            
            aPtr->item = begPtr->item;
        }         
        aPtr->next = NULL;
    } // end else
    return (*this);
} 


ostream & operator<<(ostream& outL, const List& aList) {
    // create an element  
    ListItemType anElement;
    
    // retrieve the list elements 
    for(int i = 0; i < aList.getLength(); i++){
        aList.retrieve(i + 1, anElement);
        outL << anElement << " ";
    } 
    return outL;
} 

void List::reverseList(List &aList){
    
    int listSize = aList.getLength();
    int indx;
    List saveList;
        
    //  revert the list
    for (int i = 1; i <= listSize; i++){
        indx = 1;
        ListNode *currNode = head;
        ListNode *nextNode = currNode->next;
        
        // advance the index to the end
        while (nextNode != NULL) {
            currNode = nextNode;
            indx++;
            nextNode = currNode->next;
        } 
        
        // move the reversed list to the original one
        saveList.insert(i, currNode->item);
        aList.remove(indx);
    } 
    
    aList = saveList;
} 


