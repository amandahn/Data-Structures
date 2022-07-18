/* 
 * Stack.cpp
 *
 * Description: Implementation of a Stack data structure using a singly linked list
 * Class Invariant: Elements are entered and accessed in a Last In
 *                  First Out method (LIFO)
 *
 * Author: Amanda Ngo
 * Date: February 13, 2022
 */

using namespace std;

// Constructor
// Description: Creates an empty Stack object
// Postcondition:  Stack is empty; head and tail are both set to NULL

template <class ElementType>
Stack::Stack(){
    head = NULL;
    tail = NULL;
}

// Destructor
// Description: Destruct a Stack object, releasing heap-allocated memory
// Postcondition: All elements of a linked list are deleted
template <class ElementType>
Stack<ElementType>::~Stack(){
    StackNode* curr = tail;
    while(curr != NULL){
        head = head -> next;
        delete head;
        curr = head;
    }
}


// Description:  Insert element x to the top of the stack.
// Postcondition:  Element x is the new tail; previous tail is now 'next
//                 of the new tail
template <class ElementType>
void Stack<ElementType>::push(ElementType x){
    StackNode* newNode = new StackNode;
    if(newNode == NULL){
        cout << "Unable to push\n";
    }
    newNode -> data = ElementType;
    newNode -> next = tail;
    tail = newNode;
}


// Description:  Remove and return element at the top of the stack.
// Precondition:  The stack is not empty
// Postcondition:  Returns the data stored in 'tail', deletes the current 'tail'
//                 and sets the former 'next' element to tail
template <class ElementType>
ElementType Stack<ElementType>::pop(){
    ElementType popped;
    if(tail != NULL){
        popped = tail -> data;
    }
    StackNode* holder = tail -> next;
    delete tail;
    tail = holder;
    return popped;
}

// Description:  Return the topmost element of the stack.
// Precondition:  The stack is not empty
// Postcondition:  Returns the data stored in 'tail'
template <class ElementType>
ElementType Stack<ElementType>::peek() const{
    ElementType peeked;
    if(tail != NULL){
        peeked = tail -> data;
    }
    return peeked;
}


// Description:  Checks if the stack is empty
// Postcondition:  Returns TRUE if the stack is empty, FALSE otherwise
template <class ElementType>
bool Stack::isEmpty() const{
    bool empty = false;
    if(tail == NULL){
        empty = true;
    }
    return empty;
}

