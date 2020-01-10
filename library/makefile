all: test.o characters.o items.o
	gcc -o test test.o characters.o items.o

test.o: test.c characters.h items.h
	gcc -c -g test.c

characters.o: characters.c characters.h items.h
	gcc -c -g characters.c

items.o: items.c items.h
	gcc -c -g items.c

clean:
	rm *.o
	rm test
	rm *~
run:
	./test

memtest:
	valgrind ./test --leak-check=yes
