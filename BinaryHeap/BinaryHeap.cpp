/* 
 * BinaryHeap.cpp
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

#include "BinaryHeap.h"  // Header file

using namespace std;

// Default Constructor
template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap() {
   elementCount = 0;
   capacity = INITIAL_CAPACITY;
   elements = new ElementType[INITIAL_CAPACITY];
   
} // end of default constructor

// Destructor
template <class ElementType>
BinaryHeap<ElementType>::~BinaryHeap(){
    delete[] elements;
}
	
// Description: Returns the number of elements in the Binary Heap.
// Postcondition:  The Binary Heap is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
unsigned int BinaryHeap<ElementType>::getElementCount() const {
   return elementCount;
}  // end getElementCount


// Description: Inserts newElement into the Binary Heap.
//              It returns "true" if successful, otherwise "false".        
// Postcondition: Remains a Minimum Binary Heap after the insertion.
// Time Efficiency: O(log2 n)
template <class ElementType>
bool BinaryHeap<ElementType>::insert(ElementType& newElement) {
	unsigned int indexOfRoot = 0;
	unsigned int indexOfBack = elementCount;
    bool ableToInsert = false;
	if(elementCount == 0){
		elements[0] = newElement;
		elementCount++;
		return true;
	}
	elementCount++;
	elements[indexOfBack] = newElement;
    reHeapUp(indexOfBack);
	if(elements[indexOfRoot] <= elements[indexOfBack]){
    	ableToInsert = true;
	}
	
    return ableToInsert;

} // end insert


// Utility method - Recursively put the array back into a Minimum Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapUp(unsigned int indexOfBottom) {
	unsigned int indexOfRoot = 0;
    if(indexOfBottom != indexOfRoot){

        int indexOfParent = floor((indexOfBottom - 1)/2);

        if(elements[indexOfBottom] <= elements[indexOfParent]){
            ElementType temp = elements[indexOfParent];
	        elements[indexOfParent] = elements[indexOfBottom];
	        elements[indexOfBottom] = temp;
            reHeapUp(indexOfParent);
        }
    }
	return;
	
} // end reHeapUp


// Description: Removes (but does not return) the element located at the root.
// Precondition: This Binary Heap is not empty.
// Postcondition: Remains a Minimum Binary Heap after the removal.	
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void BinaryHeap<ElementType>::remove() {
	unsigned int indexOfRoot = 0;
	if(elementCount == 0){
		throw(EmptyDataCollectionException("remove() called with an empty BinaryHeap."));
	}
	elements[indexOfRoot] = elements[elementCount-1];
    reHeapDown(indexOfRoot);
    elementCount--;

	return;
	
}  // end remove


// Utility method - Recursively put the array back into a Minimum Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapDown(unsigned int indexOfRoot) {

	unsigned int indexOfMinChild = indexOfRoot;
	
	// Find indices of children.
	unsigned int indexOfLeftChild = 2*indexOfRoot+1;
	unsigned int indexOfRightChild = 2*indexOfRoot+2;

    // Base case: elements[indexOfRoot] is a leaf as it has no children
	if (indexOfLeftChild > elementCount-1) return;

	// If we need to swap, select the smallest child
    // if (elements[indexOfRoot] > elements[indexOfLeftChild])
	if ( ! (elements[indexOfRoot] <= elements[indexOfLeftChild]) )
    	indexOfMinChild = indexOfLeftChild;

    // Check if there is a right child, is it the smallest?
    if (indexOfRightChild < elementCount) {
		// if (elements[indexOfMinChild] > elements[indexOfRightChild])
		if ( ! (elements[indexOfMinChild] <= elements[indexOfRightChild]) )
		    indexOfMinChild = indexOfRightChild;
	}

	// Swap parent with smallest of children.
	if (indexOfMinChild != indexOfRoot) {
		
	   ElementType temp = elements[indexOfRoot];
	   elements[indexOfRoot] = elements[indexOfMinChild];
	   elements[indexOfMinChild] = temp;
	   
	   // Recursively put the array back into a heap
	   reHeapDown(indexOfMinChild);
    }

	return;
	
} // end reHeapDown


// Description: Retrieves (but does not remove) the element located at the root.
// Precondition: This Binary Heap is not empty.
// Postcondition: This Binary Heap is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(1) 
template <class ElementType>
ElementType BinaryHeap<ElementType>::retrieve() const {
   
   // Enforce precondition
   if ( elementCount > 0 )
      return elements[0];
   else
      throw(EmptyDataCollectionException("retrieve() called with an empty BinaryHeap.")); 

}  // end retrieve


//  End of implementation file.