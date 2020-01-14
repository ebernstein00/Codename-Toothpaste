all: test.o characters.o items.o gameflow.o
	gcc -o test test.o characters.o items.o gameflow.o

test.o: test.c characters.h items.h gameflow.h
	gcc -c -g test.c

characters.o: characters.c characters.h items.h
	gcc -c -g characters.c

items.o: items.c items.h
	gcc -c -g items.c

gameflow.o: gameflow.c items.h characters.h
	gcc -c -g gameflow.c

clean:
	rm *.o
	rm test
	rm -rf *.dsYM
	rm *~
run:
	./test

memtest:
	valgrind ./test --leak-check=yes --dsmyutil=no
