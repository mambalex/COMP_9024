wordchains: wordchains.o Graph.o
	gcc -o wordchains wordchains.o Graph.o

wordchains.o : wordchains.c Graph.h
	gcc -Wall -Werror -c wordchains.c 

Graph.o : Graph.c Graph.h
	gcc -Wall -Werror -c Graph.c

clean:
	rm -f wordchains wordchains.o Graph.o core

