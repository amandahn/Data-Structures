all:	x

x: BankSimApp.o PriorityQueue.h BinaryHeap.h Queue.h EmptyDataCollectionException.o 
	g++ -Wall -o x EmptyDataCollectionException.o BankSimApp.o

BankSimApp.o: BankSimApp.cpp
	g++ -Wall -c BankSimApp.cpp

PriorityQueue.o: PriorityQueue.cpp PriorityQueue.h
	g++ -Wall -c PriorityQueue.cpp

BinaryHeap.o: BinaryHeap.cpp BinaryHeap.h
	g++ -Wall -c BinaryHeap.cpp

Queue.o: Queue.cpp Queue.h 
	g++ -Wall -c Queue.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	g++ -Wall -c EmptyDataCollectionException.cpp

clean:	
	rm -f x *.o



