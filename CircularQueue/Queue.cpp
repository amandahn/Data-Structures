/* 
 * Queue.cpp
 *
 * Description: Implementation of an int sequence with enqueue/dequeue ...
 * Class Invariant: ... in FIFO order
 *
 * Author: Amanda Ngo
 * Date: March 2022
 * 
 */

#include "Queue.h"

using namespace std;

// Description: Default Constructor
template<class ElementType>
Queue<ElementType>::Queue(){
    elements = new ElementType[INITIAL_CAPACITY];
    elementCount = 0;
    capacity = 50;
    frontindex = 0;
    backindex = 0;
}

// Destructor
template<class ElementType>
Queue<ElementType>::~Queue(){
    delete[] elements;
}

// Description: Returns "true" if this Queue is empty, otherwise "false".
// Postcondition: This Queue is unchanged by this operation.
// Time Efficiency: O(1)
template<class ElementType>
bool Queue<ElementType>::isEmpty() const{
    if(elementCount == 0){
        return true;
    }
    return false;
}

// Description: Inserts newElement at the "back" of this Queue 
//              (not necessarily the "back" of its data structure) and 
//              returns "true" if successful, otherwise "false".
// Time Efficiency: O(1)
template<class ElementType>
bool Queue<ElementType>::enqueue(ElementType& newElement){
    elementCount++;
    elements[backindex] = newElement;
    backindex = (backindex + 1)%capacity;
    return true;
}

// Description: Removes (but does not return) the element at the "front" of this Queue 
//              (not necessarily the "front" of its data structure).
// Precondition: This Queue is not empty.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.   
// Time Efficiency: O(1)
template<class ElementType>
void Queue<ElementType>::dequeue(){
    if(elementCount == 0){
        throw EmptyDataCollectionException("Queue is empty.");
    }
    elementCount--;
    frontindex = (frontindex + 1)%capacity;
}

// Description: Returns (but does not remove) the element at the "front" of this Queue
//              (not necessarily the "front" of its data structure).
// Precondition: This Queue is not empty.
// Postcondition: This Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
template<class ElementType>
ElementType& Queue<ElementType>::peek() const{
    if(elementCount == 0){
        throw EmptyDataCollectionException("Queue is empty.");
    }
    return elements[frontindex];
}

// Description: Prints the contents of Queue
// Precondition: This Queue is not empty
// Postcondition: This Queue is unchanged by this operation
// Exception: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(n)
template<class ElementType>
void Queue<ElementType>::printQueue(){
    if(elementCount == 0){
        throw EmptyDataCollectionException("Queue is empty.");
    }
    else if(frontindex < backindex){
        for(unsigned int i=frontindex; i<backindex; i++){
            cout << elements[i] << endl;
        }
    }
    else{
        for(unsigned int i=frontindex; i<capacity; i++){
            cout << elements[i] << endl;
        }
        for(unsigned int i=0; i<backindex; i++){
            cout << elements[i] << endl;
        }
    }
}