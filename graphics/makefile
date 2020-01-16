all: window.o gui.o background.o health.o
	cd classes && make
	cd enemies && make
	gcc -o program  $(files) -lSDL2 -lSDL2_image

files =  ./classes/fighterIdle.o ./classes/mageIdle.o ./classes/rogueIdle.o ./classes/knightIdle.o \
		./enemies/galactaIdle.o \
 		gui.o background.o health.o window.o

window.o: window.c
	gcc -c -g window.c

gui.o: gui.c
	gcc -c -g gui.c

background.o: background.c
	gcc -c -g background.c

health.o: health.c
	gcc -c -g health.c

run:
	./program

clean:
	cd classes && make clean
	cd enemies && make clean
	rm -r -f *.o *.gch
