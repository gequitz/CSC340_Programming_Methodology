

/* 
 * File:   LinkedList_StrucNode_Exceptions.h
 * Author: Gabriel Equitz
 * sfsu id : 915254839
 *
 * Created on November 28, 2016, 7:58 PM
 */

#ifndef LINKEDLIST_STRUCTNODE_EXCEPTIONS_H
#define LINKEDLIST_STRUCTNODE_EXCEPTIONS_H


#include <stdexcept>
#include <string>

using namespace std;

class ListIndexOutOfRangeException : public out_of_range
{
public:
    
    /**/
    ListIndexOutOfRangeException(const string & message = "")
    : out_of_range(message.c_str())
    { }  // end constructor
    
}; // end ListIndexOutOfRangeException


class ListException : public logic_error
{
public:
    
    /**/
    ListException(const string & message = "")
    : logic_error(message.c_str())
    { }  // end constructor
    
}; // end ListException


#endif /* LINKEDLIST_STRUCTNODE_EXCEPTIONS_H */

