/* 
 * BinaryHeap.h
 *
 * Description: Minimum Binary Heap data collection ADT class. 
 *              Binary implementation. Modified from Lab 8.
 *
 * Class Invariant:  Always a Minimum Binary Heap
 * 
 * Author: Amanda Ngo
 *
 * Last Modification: March 2022
 *
 */  

 
#pragma once

#include <iostream>
#include <cmath>
#include "EmptyDataCollectionException.h"   // To do: Feel free to recycle an exception class from Assignment 3.

using namespace std;

template <class ElementType>
class BinaryHeap {

private:
    // To do: Add the data members here!
	unsigned int INITIAL_CAPACITY = 50;
	unsigned int elementCount;
	unsigned int capacity;
	ElementType *elements;
	
	void reHeapUp(unsigned int indexOfBottom);

	void reHeapDown(unsigned int indexOfRoot);  
   
public:
	// Default Constructor
	BinaryHeap(); 
	
	// To do: If it needs a copy constructor, add it!
	// To do: If it needs a destructor, add it!
	~BinaryHeap();
	
    // Description: Returns the number of elements in the Binary Heap.
    // Postcondition:  The Binary Heap is unchanged by this operation.
	// Time Efficiency: O(1)
    unsigned int getElementCount() const;

	// Description: Inserts newElement into the Binary Heap.
	//              It returns "true" if successful, otherwise "false".        
	// Postcondition: Remains a __________ Binary Heap after the insertion.
	// Time Efficiency: O(log2 n)
	bool insert(ElementType& newElement);
	   
	// Description: Removes (but does not return) the element located at the root.
	// Precondition: This Binary Heap is not empty.
	// Postcondition: Remains a __________ Binary Heap after the removal.	
	// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
	// Time Efficiency: O(log2 n)
	void remove();

	// Description: Retrieves (but does not remove) the element located at the root.
	// Precondition: This Binary Heap is not empty.
	// Postcondition: This Binary Heap is unchanged.
	// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
	// Time Efficiency: O(1) 
	ElementType retrieve() const;
   
}; // end BinaryHeap

#include "BinaryHeap.cpp"