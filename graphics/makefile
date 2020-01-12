all: window.o
	cd fighter && make
	gcc -I./fighter -o  program window.o ./fighter/fighterIdle.o ./fighter/fighterKick.o -lSDL2 -lSDL2_image

window.o: window.c
	gcc -c -g window.c

run:
	./program

clean:
	rm *.o
