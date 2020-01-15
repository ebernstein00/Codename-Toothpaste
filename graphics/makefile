<<<<<<< HEAD
all: window.o gui.o background.o health.o
	cd classes && make
	cd enemies && make
	gcc -o program window.o $(files) -lSDL2 -lSDL2_image

files =  ./classes/fighterIdle.o ./classes/mageIdle.o ./classes/rogueIdle.o ./classes/knightIdle.o \
		./enemies/galactaIdle.o \
 		gui.o background.o health.o
=======
all: window.o gui.o background.o
	cd classes && make
	gcc -o program window.o $(files) -lSDL2 -lSDL2_image

files =  ./classes/fighterIdle.o ./classes/mageIdle.o ./classes/rogueIdle.o ./classes/knightIdle.o \
 		gui.o background.o
>>>>>>> 6fac653d6eafd6dd5fa29bbbe6f98482dff7b7c5

window.o: window.c
	gcc -c -g window.c

gui.o: gui.c
	gcc -c -g gui.c

background.o: background.c
	gcc -c -g background.c
<<<<<<< HEAD

health.o: health.c
	gcc -c -g health.c
=======
>>>>>>> 6fac653d6eafd6dd5fa29bbbe6f98482dff7b7c5
run:
	./program

clean:
<<<<<<< HEAD
	cd classes && make clean
	cd enemies && make clean
=======
>>>>>>> 6fac653d6eafd6dd5fa29bbbe6f98482dff7b7c5
	rm *.o
