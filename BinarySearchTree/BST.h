/*
 * BST.h
 *  
 * Description: Binary Search Tree data collection ADT class.
 *              Link-based implementation.
 *              Duplicated elements are not allowed.
 *
 * Class invariant: It is always a BST.
 * 
 * Author: Inspired from our textbook
 * Date of last modification: March 10, 2022
 * 
 */

#pragma once

#include "BSTNode.h" 
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"


template <class ElementType>
class BST {
	
private:

	// You cannot change the following data members of this class.
	BSTNode<ElementType>* root; 
    unsigned int elementCount;           

    /* Utility methods */

	// Feel free to add private methods to this class.
	
	// Description: Recursive insertion into a binary search tree.
	//              Returns true when "anElement" has been successfully inserted into the 
	//              binary search tree. Otherwise, returns false.
    bool insertR(const ElementType& element, BSTNode<ElementType>* current); 

    // Description: Recursive retrieval from a binary search tree.
	// Exception: Throws the exception "ElementDoesNotExistException" 
	//            if "targetElement" is not found in the binary search tree.
    ElementType& retrieveR(const ElementType& targetElement, BSTNode<ElementType>* current) const;

	// Description: Recursive in order traversal of a binary search tree.	
	void traverseInOrderR(void visit(const ElementType&), BSTNode<ElementType>* current) const;

	void copyR(BSTNode<ElementType>* current);

	void destructorR(BSTNode<ElementType>* current);	 
public:

	// You cannot change the prototype of the public methods of this class.
	// Remember, if you add public methods to this class, our test driver 
	// - the one we will use to mark this assignment - will not know about them
	// since we will use these public method prototypes to create our test driver.

    /* Constructors and destructor */
	BST();                               // Default constructor
    BST(ElementType& element);           // Parameterized constructor 
	BST(const BST<ElementType>& aBST);   // Copy constructor 
    ~BST();                              // Destructor 
	
	/* Getters and setters */
	unsigned int getElementCount() const;
/*
	getRoot() and setRoot(...) <- are not acceptable getter/setter - can you see why?
	setElementCount(...) <- is not an acceptable setter - can you see why?
*/

    /* BST Operations */

    // Description: Inserts an element into the binary search tree.
	//              This is a wrapper method which calls the recursive insertR( ).
	// Precondition: "newElement" does not already exist in the binary search tree.
    // Exception: Throws the exception "ElementAlreadyExistsException" 
	//            if "newElement" already exists in the binary search tree.
	// Time efficiency: O(log2 n)	
	void insert(const ElementType& newElement);	
	
    // Description: Retrieves "targetElement" from the binary search tree.
	//              This is a wrapper method which calls the recursive retrieveR( ).
	// Precondition: Binary search tree is not empty.
    // Exception: Throws the exception "EmptyDataCollectionException" 
	//            if the binary search tree is empty.
	// Exception: Throws (propagates) the exception "ElementDoesNotExistException" 
	//            thrown from the retrieveR(...)
	//            if "targetElement" is not in the binary search tree.
	// Time efficiency: O(log2 n)
	ElementType& retrieve(const ElementType& targetElement) const;
	
    // Description: Traverses the binary search tree in order.
	//              This is a wrapper method which calls the recursive traverseInOrderR( ).
	//              The action to be done on each element during the traverse is the function "visit".
	// Precondition: Binary search tree is not empty.
    // Exception: Throws the exception "EmptyDataCollectionException" 
	//            if the binary search tree is empty.
	// Time efficiency: O(n)	
	void traverseInOrder(void visit(const ElementType&)) const;
	
	
}; // end BST

#include "BST.cpp"  // Including "BST.cpp" (instead of copying the content of BST.cpp) is another way of creating templates.