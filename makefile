CFLAGS=-Wall -Werror -Wfatal-errors

BST: BST.o class.o
	g++ -o BST BST.o class.o

BST.o: BST.cc class.h
	g++ -c $(CFLAGS) BST.cc

class.o: class.cc class.h
	g++ -c $(CFLAGS) class.cc

clean:
	rm -rf *.o main