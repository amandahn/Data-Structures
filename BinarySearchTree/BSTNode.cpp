/*
 * BSTNode.cpp
 * 
 * Description: Models a node required to build a link-based binary search tree (BST).
 * 
 * Author: AL 
 * Date of last modification: Feb. 2022
 */

#include "BSTNode.h"


// Constructors
template <class ElementType>
BSTNode<ElementType>::BSTNode() {
	left = NULL;
	right = NULL;
}

template <class ElementType>
BSTNode<ElementType>::BSTNode(ElementType element) {
	this->element = element;
	left = NULL;
	right = NULL;
}

template <class ElementType>
BSTNode<ElementType>::BSTNode(ElementType element, BSTNode<ElementType>* left, BSTNode<ElementType>* right) {
	this->element = element;
	this->left = left;
	this->right = right;	
}

// Boolean helper functions
template <class ElementType>
bool BSTNode<ElementType>::isLeaf() const {
	return (left == NULL && right == NULL);
}

template <class ElementType>
bool BSTNode<ElementType>::hasLeft() const {
	return (left != NULL);
}

template <class ElementType>
bool BSTNode<ElementType>::hasRight() const {
	return (right != NULL);
}