/* 
 * Stack.h
 *
 * Description: Implementation of an int sequence with push/pop ...
 * Class Invariant: ... in a LIFO order
 *
 * Author: Amanda Ngo
 * Date: February 13, 2022
 */
 
class Stack {

    private:

        // Description:  Nodes for a singly-linked list
        class StackNode {
            public:
                int data;
                StackNode * next;
        };
        

        // Description:  head = ptr to the first StackNode (NULL if empty)
        //               tail = ptr to the last StackNode (NULL if empty)
        // Class Invariant:  Follows Assignment 2 requirements, namely that the implementation 
        //                   is a singly-linked list, with insert/remove 
        //                   operations at the list's tail.
        StackNode * head;
        StackNode * tail;

    public:

        // Constructor
        // Description: Creates an empty Stack object
        // Postcondition:  Stack is empty; head and tail are both set to NULL
        Stack();


        // Destructor
        // Description: Destruct a Stack object, releasing heap-allocated memory
        // Postcondition: All elements of a linked list are deleted
        ~Stack();



        // Description:  Insert element x to the top of the stack.
        // Postcondition:  Element x is the new tail; previous tail is now 'next
        //                 of the new tail
        void push(int x);

        // Description:  Remove and return element at the top of the stack.
        // Precondition:  The stack is not empty
        // Postcondition:  Returns the data stored in 'tail', deletes the current 'tail'
        //                 and sets the former 'next' element to tail
        int pop();

        // Description:  Return the topmost element of the stack.
        // Precondition:  The stack is not empty
        // Postcondition:  Returns the data stored in 'tail'
        int peek() const;


        // Description:  Checks if the stack is empty
        // Postcondition:  Returns TRUE if the stack is empty, FALSE otherwise
        bool isEmpty() const;
};


