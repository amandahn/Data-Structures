/*
 * BSTNode.h
 * 
 * Description: Models a node required to build a link-based binary search tree (BST).
 * 
 * Author: AL
 * Date of last modification: Feb. 2022
 */ 

#pragma once

using namespace std;

template <class ElementType>
class BSTNode {

public:

	ElementType element;
	BSTNode<ElementType>* left;
	BSTNode<ElementType>* right;

	// Constructors
	BSTNode() ;
    BSTNode(ElementType element) ;
    BSTNode(ElementType element, BSTNode<ElementType>* theLeftSubTree, BSTNode<ElementType>* theRightSubTree) ;

	// Boolean helper functions
	bool isLeaf() const;
	bool hasLeft() const;
	bool hasRight() const;

};

#include "BSTNode.cpp" // Including "BSTNode.cpp" (instead of copying the content of BSTNode.cpp) 
                       // is another way of creating templates.