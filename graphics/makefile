all: window.o
	gcc -o program window.o -lSDL2 -lSDL2_image

window.o: window.c
	cd fighter && make
	gcc -c -g window.c

run:
	./program

clean:
	rm *.o
