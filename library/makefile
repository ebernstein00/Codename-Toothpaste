all: characters.o items.o gameflow.o


characters.o: characters.c characters.h items.h
	gcc -c -g characters.c

items.o: items.c items.h
	gcc -c -g items.c

gameflow.o: gameflow.c items.h characters.h
	gcc -c -g gameflow.c

clean:
	rm -rf *.o
	rm -rf *.dsYM
	rm  -rf *~ *.gch
