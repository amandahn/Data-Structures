/* 
 * PriorityQueue.h
 *
 * Description: Priority Queue data collection ADT class. 
 *
 * Class Invariant:  Always a Minimum Binary Heap
 * 
 * Author: Amanda Ngo
 *
 * Last Modification: March 2022
 *
 */  

#include "BinaryHeap.h"

template <class ElementType>
class PriorityQueue {

    private:
        BinaryHeap<ElementType> Queue; 
    public:
        /******* Start of Priority Queue Public Interface *******/
        // Default Constructor
        PriorityQueue();

        // Description: Returns "true" if this Priority Queue is empty, otherwise "false".
        // Postcondition: This Priority Queue is unchanged by this operation.
        // Time Efficiency: O(1)
        bool isEmpty() const;

        // Description: Inserts newElement in this Priority Queue and 
        //              returns "true" if successful, otherwise "false".
        bool enqueue(ElementType& newElement);

        // Description: Removes (but does not return) the element with the next
        //              "highest" priority value from the Priority Queue.
        // Precondition: This Priority Queue is not empty.
        // Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
        void dequeue();
        
        // Description: Returns (but does not remove) the element with the next 
        //              "highest" priority from the Priority Queue.
        // Precondition: This Priority Queue is not empty.
        // Postcondition: This Priority Queue is unchanged by this operation.
        // Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
        ElementType peek() const;
        
        /*******  End of Priority Queue Public Interface *******/
};

    // Default constructor
    template <class ElementType>
        PriorityQueue<ElementType>::PriorityQueue(){}

    // Description: Returns "true" if this Priority Queue is empty, otherwise "false".
    // Postcondition: This Priority Queue is unchanged by this operation.
    // Time Efficiency: O(1)
    template <class ElementType>
        bool PriorityQueue<ElementType>::isEmpty() const{
            if(Queue.getElementCount() == 0){
                return true;
            }
            return false;
        }

    // Description: Inserts newElement in this Priority Queue and 
    //              returns "true" if successful, otherwise "false".
    template <class ElementType>
    bool PriorityQueue<ElementType>::enqueue(ElementType& newElement){
        return Queue.insert(newElement);
    }

    // Description: Removes (but does not return) the element with the next
    //              "highest" priority value from the Priority Queue.
    // Precondition: This Priority Queue is not empty.
    // Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
    template <class ElementType>
    void PriorityQueue<ElementType>::dequeue(){
        Queue.remove();
    }
    
    // Description: Returns (but does not remove) the element with the next 
    //              "highest" priority from the Priority Queue.
    // Precondition: This Priority Queue is not empty.
    // Postcondition: This Priority Queue is unchanged by this operation.
    // Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
    template <class ElementType>
    ElementType PriorityQueue<ElementType>::peek() const{
        return Queue.retrieve();
    }