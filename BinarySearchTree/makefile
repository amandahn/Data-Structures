all: translate

translate: WordPair.o ElementAlreadyExistsException.o ElementDoesNotExistException.o EmptyDataCollectionException.o BST.h BSTNode.h Dictionary.h Translator.o 
	g++ -Wall -o translate Translator.o WordPair.o ElementAlreadyExistsException.o ElementDoesNotExistException.o EmptyDataCollectionException.o

Translator.o: Translator.cpp
	g++ -Wall -c Translator.cpp
		
WordPair.o: WordPair.h WordPair.cpp
	g++ -Wall -c WordPair.cpp

ElementDoesNotExistException.o: ElementDoesNotExistException.h ElementDoesNotExistException.cpp
	g++ -Wall -c ElementDoesNotExistException.cpp

ElementAlreadyExistsException.o: ElementAlreadyExistsException.h ElementAlreadyExistsException.cpp
	g++ -Wall -c ElementAlreadyExistsException.cpp
		
EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	g++ -Wall -c EmptyDataCollectionException.cpp

clean:
	rm -f translate *.o