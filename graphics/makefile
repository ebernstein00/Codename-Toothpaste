<<<<<<< HEAD
all: window.o gui.o
	cd classes && make
	gcc -o program window.o $(files) -lSDL2 -lSDL2_image

files =  ./classes/fighterIdle.o ./classes/fighterKick.o gui.o
=======
all: window.o
	gcc -o program window.o -lSDL2
>>>>>>> eb2e5cc849c442f7c85d3ecd929b30a29a189f27

window.o: window.c
	gcc -c -g window.c

gui.o: gui.c
	gcc -c -g gui.c
run:
	./program

clean:
	rm *.o
