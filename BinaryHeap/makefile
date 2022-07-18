all:	x

x: td.o BinaryHeap.h EmptyDataCollectionException.o 
	g++ -Wall -o x EmptyDataCollectionException.o td.o


BinaryHeap.o: BinaryHeap.cpp BinaryHeap.h
	g++ -Wall -c BinaryHeap.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	g++ -Wall -c EmptyDataCollectionException.cpp

clean:	
	rm -f x *.o



