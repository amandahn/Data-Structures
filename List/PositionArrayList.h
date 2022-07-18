/*
 * PositionArrayList.h
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - Position-oriented list
 *
 * Author: Amanda Ngo
 * Date: July 18, 2022 (Last Modified)
 */

#pragma once

#include <string>
#include <iostream>

using namespace std;

template <class ElementType>
class List  {

      private:

        const int INITIAL_CAPACITY = 5;    // constant INITIAL_CAPACITY
        ElementType* arr;                	   // Data structure of elements
        int elementCount;                  // Number of elements in the data structure
        int capacity;                      // Actual capacity of data structure   

      public:


        // Default constructor
        List();

        // Destructor
        // Description: Destruct a List object, releasing heap-allocated memory.
        ~List();

        // Description: Returns the total element count currently stored in List.
        int  getElementCount() const;

        // Description: Insert an element.
        // Precondition: newElement must not already be in data collection.  
        // Postcondition: newElement inserted and elementCount has been incremented.   
        bool insert(const ElementType& newElement);

        // Description: Remove an element. 
        // Postcondition: toBeRemoved is removed and elementCount has been decremented.	
        bool remove( const ElementType& toBeRemoved );

        // Description: Remove all elements.
        void removeAll();

        // Description: Search for target element.
        //              Returns a pointer to the element if found,
        //              otherwise, returns NULL.
        Patient* search(const ElementType& target);

        // Description: Prints all elements stored in List by descending order of search key.
        void printList();

}; // end PositionArrayList.h

#include "PositionArrayList.cpp"
