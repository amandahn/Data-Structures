/*
 * BST.cpp
 * 
 * Description: Binary Search Tree data collection ADT class.
 *              Link-based implementation.
 *              Duplicated elements are not allowed.
 *
 * Class invariant: It is always a BST.
 * 
 * Author: Inspired from our textbook, Amanda Ngo
 * Date of last modification: March 10, 2022
 */

#include "BST.h"
	
// You can modify the implementation of these methods, but cannot modify their proptotype.
// However, if you modify the implementation of these methods, your code must still 
// satisfy the documentation contract above each of these methods.

/* Constructors and destructor */

	// Default constructor
    template<class ElementType>
	BST<ElementType>::BST() {
		root = NULL;
		elementCount = 0;
	}
	
	// Parameterized constructor
    template<class ElementType>      
    BST<ElementType>::BST(ElementType& element) {
		root = new BSTNode<ElementType>(element);
		elementCount = 1;	
	}               

    // Copy constructor 
	// Precondition: aBST is not empty
	// Postcondition: Creates a new BST which is a copy of aBST
    template<class ElementType>  
	BST<ElementType>::BST(const BST<ElementType>& aBST)  
	{
		if (aBST.getElementCount() == 0) {
			throw EmptyDataCollectionException("Binary search tree is empty.");
		}
		else{
			copyR(aBST.root);
			elementCount = aBST->getElementCount();
		}
	}
	// copyR
	// Description: Recursive helper for the constructor. Inserts the current
	//				element into the BST. Checks if a left or right element needs
	//				to be added into the BST, and calls itself accordingly if so.
	template<class ElementType>
	void BST<ElementType>::copyR(BSTNode<ElementType>* current){
		insert(current->element);
		if(current->hasLeft()){
			copyR(current->left);
		}
		if(current->hasRight()){
			copyR(current->right);
		}
	}


	// Destructor
	// Precondition: BST is not empty
	// Postcondition: All elements in the BST are deleted 
    template<class ElementType> 
	BST<ElementType>::~BST() {
		if(elementCount > 0){
			destructorR(root);
		}
    }

	// destructorR
	// Description: Recursive helper for the destructor. Deletes the current
	//				element after checking and calling destructorR if left or
	//				right elements exist
	template<class ElementType> 
	void BST<ElementType>::destructorR(BSTNode<ElementType>* current){
		if(current->hasLeft()){
			destructorR(current->left);
		}
		if(current->hasRight()){
			destructorR(current->right);
		}
		delete current;
		current = NULL;
	}                 
	
	
/* Getters and setters */

    // Description: Returns the number of elements currently stored in the binary search tree.	
	// Time efficiency: O(1)
    template<class ElementType>	
	unsigned int BST<ElementType>::getElementCount() const {		

		return this->elementCount;
	}
	

/* BST Operations */

    // Description: Inserts an element into the binary search tree.
	//              This is a wrapper method which calls the recursive insertR( ).
	// Precondition: "newElement" does not already exist in the binary search tree.
    // Exception: Throws the exception "ElementAlreadyExistsException" 
	//            if "newElement" already exists in the binary search tree.
	// Time efficiency: O(log2 n)	
    template<class ElementType>
	void BST<ElementType>::insert(const ElementType& newElement) {
		
	    // Binary search tree is empty, so add the new element as the root
		if (elementCount == 0) {
			root = new BSTNode<ElementType>(newElement);
			elementCount++;
		}
		else if ( !insertR(newElement,root) ) {
  	        throw ElementAlreadyExistsException("Element already exists in the data collection.\n");
		}
		
  	}

    // Description: Recursive insertion into a binary search tree.
	//              Returns true when "anElement" has been successfully inserted into the 
	//              binary search tree. Otherwise, returns false.
    template<class ElementType>
	bool BST<ElementType>::insertR(const ElementType& anElement, BSTNode<ElementType>* current) { 
		// If element already exists in the BST...
		if(current->element == anElement){
			return false;
		}
		// CASE 1: anElement is greater than element checked
		// 		   so it continues down the left branch. Calls itself if
		//		   current already has a left element, inserts itself otherwise.
		else if(current->element > anElement){
			if(current->hasLeft()){
				return insertR(anElement,current->left);
			}
			else{
				BSTNode<ElementType>* newNode = new BSTNode<ElementType>(anElement);
				current->left = newNode;
				elementCount++;
			}
		}
		// CASE 2: anElement is less than the element checked
		//  	   so it continues down the right branch. Calls itself if
		//		   current already has a right element, inserts itself otherwise.
		else{
			if(current->hasRight()){					
				return insertR(anElement,current->right);
			}
			else{
				BSTNode<ElementType>* newNode = new BSTNode<ElementType>(anElement);
				current->right = newNode;
				elementCount++;			
			}
		}
		return true;
	}

	
    // Description: Retrieves "targetElement" from the binary search tree.
	//              This is a wrapper method which calls the recursive retrieveR( ).
	// Precondition: Binary search tree is not empty.
    // Exception: Throws the exception "EmptyDataCollectionException" 
	//            if the binary search tree is empty.
	// Exception: Throws (propagates) the exception "ElementDoesNotExistException" 
	//            thrown from the retrieveR(...)
	//            if "targetElement" is not in the binary search tree.
	// Time efficiency: O(log2 n)
    template<class ElementType>
    ElementType& BST<ElementType>::retrieve(const ElementType& targetElement) const {
        
	    // Check precondition: If binary search tree is empty
		if (elementCount == 0){ 
			throw EmptyDataCollectionException("Binary search tree is empty.\n");
		}
		// Otherwise, search for it		
		ElementType& translated = retrieveR(targetElement, root);

		return translated;
	}

    // Description: Recursive retrieval from a binary search tree.
	// Exception: Throws the exception "ElementDoesNotExistException" 
	//            if "targetElement" is not found in the binary search tree.
    template<class ElementType>
    ElementType& BST<ElementType>::retrieveR(const ElementType& targetElement, BSTNode<ElementType>* current) const {
		// If the current element is the target element, return current->element
		if(current->element == targetElement){
			return current->element;
		}
		// If the current element is larger than the target element and a left
		// element exists, continue down the left branch
		else if(current->element > targetElement){
			if(current-> hasLeft()){
				return retrieveR(targetElement, current->left);
			}
		}
		// Otherwise, if a right element exists, continue down the right branch
		else{
			if(current-> hasRight()){
				return retrieveR(targetElement, current->right);
			}
		}
		// If none of these conditions apply, throw ELementDoesNotExist exception
		throw ElementDoesNotExistException("Element was unable to be located");
	} // end of retrieveR
				
	
    // Description: Traverses the binary search tree in order.
	//              This is a wrapper method which calls the recursive traverseInOrderR( ).
	//              The action to be done on each element during the traverse is the function "visit".
	// Precondition: Binary search tree is not empty.
    // Exception: Throws the exception "EmptyDataCollectionException" 
	//            if the binary search tree is empty.
	// Time efficiency: O(n)		
    template<class ElementType>
	void BST<ElementType>::traverseInOrder(void visit(const ElementType&)) const {
		
		// Check precondition: If binary search tree is empty
		if (elementCount == 0)  
			throw EmptyDataCollectionException("Binary search tree is empty.");
		else {
			traverseInOrderR(visit,root);
		}
	}

    // Description: Recursive in order traversal of a binary search tree.	
	template<class ElementType>
	void BST<ElementType>::traverseInOrderR(void visit(const ElementType&), BSTNode<ElementType>* current) const {

		// If a left element exists, visit the left element
		if(current->hasLeft()){
			traverseInOrderR(visit,current->left);
		}
		// Visit the current element before checking if the right element exists
		visit(current->element);
		// If a right element exists, visit the right element 
		if(current -> hasRight()){
			traverseInOrderR(visit,current->right);
		}
	}
	