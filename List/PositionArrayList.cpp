/*
 * PositionArrayList.cpp
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates allowed).
 *                   - Position-oriented list.
 *
 * Author: Amanda Ngo
 * Date: July 18, 2022 (Last Modified)
 */

#include <iostream>
#include "List.h"

// Default Constructor
// Description: Creates a new List object
template <class ElementType>
List<ElementType>::List(){
	arr = new ElementType[INITIAL_CAPACITY];
	elementCount = 0;
	capacity = INITIAL_CAPACITY;
}

// Destructor
// Description: Destruct a List object, releasing heap-allocated memory.
template <class ElementType>
List<ElementType>::~List(){
	delete [] arr;
}

// Description: Returns the total element count currently stored in List.
template <class ElementType>
int  List<ElementType>::getElementCount() const{
	return elementCount;
}

// Description: Insert an element.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted and elementCount has been incremented.
template <class ElementType>
bool List<ElementType>::insert(const ElementType& newElement){
	bool ableToInsert = true;
	int insert_pos;
	// Check to see if newElement is already in the data collection
	for(int i=0; i<elementCount; i++){
		if(arr[i] == newElement){
			ableToInsert = false;
		}
	}
	for(int a=0; a<elementCount; a++){
		// Searches for an element which is < newElement
		// and returns the position of that element 
		// in the array
		if(arr[a] < newElement){
			insert_pos = a;
			break;
		}
		// In the case that all elements of arr > newElement
		// insert_pos = elementCount
		if(arr[a] > newElement && a == elementCount - 1){
			insert_pos = elementCount;
		}
	}
	if(ableToInsert){
		// One comaprison implementations of newElement
		if(elementCount == 0){
			arr[0] = newElement;
			elementCount++;
			return ableToInsert;
		}
		if(elementCount == 1){
			if(arr[0] > newElement){
				arr[1] = newElement;
				elementCount++;
			}
			else{
				arr[1] = arr[0];
				arr[0] = newElement;
				elementCount++;
			}
			return ableToInsert;
		}
		else{
			// Special case where insert_pos = 0 and all elements just need to be shifted.
			// A new array with an incremented capacity is created to later replace arr.
			if(insert_pos == 0){
				ElementType* new_arr = new ElementType[capacity+1];
				new_arr[0] = newElement;
				for(int i=0;i<elementCount; i++){
					new_arr[i+1] = arr[i];
				}
				elementCount++;
				capacity++;
				delete[] arr;
				arr = new_arr;
			}
			// A new array is created so that the element is sorted in the correct position
			// and all other elements in arr remain sorted. arr is replaced by the new array.
			else{
				ElementType* new_arr = new ElementType[capacity+1];
				for(int j=0; j<insert_pos; j++){
					new_arr[j] = arr[j];
				}
				new_arr[insert_pos] = newElement;
				for(int k=insert_pos; k<elementCount; k++){
					new_arr[k + 1] = arr[k];
				}
				capacity++;
				elementCount++;
				delete[] arr;
				arr = new_arr;
			}
		}
	}
	return ableToInsert;
}

// Description: Remove an element. 
// Postcondition: toBeRemoved is removed and elementCount has been decremented.
template <class ElementType>
bool List::remove( const ElementType& toBeRemoved ){
	bool ableToRemove = false;
	int remove_pos;
	// Check to see that toBeRemoved exists in the LIst
	for(int i=0; i<elementCount; i++){
		if(arr[i] == toBeRemoved){
			ableToRemove = true;
			remove_pos = i;
			break;
		}
	}
	if(ableToRemove){
	// If the removed element is the last element of the array, decrement the list
		if(remove_pos == elementCount -1){
				elementCount--;
			}
		else{
			ElementType* new_arr = new ElementType[capacity-1];
			int curr;
			if(elementCount > 1){
				// If remove_pos is 0, shift each element in the array over by one
				// in the new array
				if(remove_pos == 0){
					for(int j=1; j<elementCount; j++){
						new_arr[j-1] = arr[j];
					}
				}
				// Otherwise, shift only the elements that need to be removed 
				// by iterating through every element before and after
				// into the new_arr
				else{
					for(int j=0; j<remove_pos; j++){
						new_arr[j] = arr[j];
						curr = j;
					}
					for(int k=remove_pos + 1; k<elementCount; k++){
						curr++;
						new_arr[curr] = arr[k];
					}
				}
			}
			capacity--;
			elementCount--;
			delete[] arr;
			arr = new_arr;
		}
	}
	return ableToRemove;
}
	
// Description: Remove all elements.
// Postcondition: elementCount is set to 0; the List no longer has elements
template <class ElementType>
void List<ElementType>::removeAll(){
	elementCount = 0;
}
   
// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
template <class ElementType>
ElementType* List<ElementType>::search(const ElementType& target){
	for(int i=0; i<elementCount; i++){
		if(arr[i] == target){
			return &arr[i];
		}
	}
	return NULL;
}

// Description: Prints all elements stored in List by descending order of search key.
template <class ElementType>
void List<ElementType>::printList(){
	for(int i=0; i<elementCount; i++){
		cout << arr[i];
	}
}
