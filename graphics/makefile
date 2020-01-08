all: window.o
	gcc -o program window.o -lSDL2 

window.o: window.c
	gcc -c -g window.c

run:
	./program

clean:
	rm *.o
