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

#pragma once
#include <iostream>
#include "EmptyDataCollectionException.h"

using namespace std;

template <class ElementType>
class Queue{
    private:

        static unsigned const INITIAL_CAPACITY = 50;
        ElementType *elements;
        unsigned int elementCount;
        unsigned int capacity;
        unsigned int frontindex;
        unsigned int backindex;

    public:
        /******* Start of Queue Public Interface *******/

        // Constructor and destructor
        Queue();
        ~Queue();

        // Description: Returns "true" if this Queue is empty, otherwise "false".
        // Postcondition: This Queue is unchanged by this operation.
        // Time Efficiency: O(1)
        bool isEmpty() const;

        // for testing purposes: getElementCount
        /* int getElementCount() const; */
    
        // Description: Inserts newElement at the "back" of this Queue 
        //              (not necessarily the "back" of its data structure) and 
        //              returns "true" if successful, otherwise "false".
        // Time Efficiency: O(1)
        bool enqueue(ElementType& newlement);
    
        // Description: Removes (but does not return) the element at the "front" of this Queue 
        //              (not necessarily the "front" of its data structure).
        // Precondition: This Queue is not empty.
        // Exception: Throws EmptyDataCollectionException if this Queue is empty.   
        // Time Efficiency: O(1)
        void dequeue(); 
    
        // Description: Returns (but does not remove) the element at the "front" of this Queue
        //              (not necessarily the "front" of its data structure).
        // Precondition: This Queue is not empty.
        // Postcondition: This Queue is unchanged by this operation.
        // Exception: Throws EmptyDataCollectionException if this Queue is empty.
        // Time Efficiency: O(1)
        ElementType& peek() const;

        // Print Queue
        void printQueue();
};

#include "Queue.cpp"