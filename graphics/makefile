all: window.o gui.o background.o display.o
	cd classes && make
	cd enemies && make
	gcc -o program  $(files) -lSDL2 -lSDL2_image

files =  ./classes/fighterIdle.o ./classes/mageIdle.o ./classes/rogueIdle.o ./classes/knightIdle.o \
		./enemies/galactaIdle.o ./enemies/dededeIdle.o ./enemies/waddledeeIdle.o ./enemies/waddledooIdle.o ./enemies/knucklejoeIdle.o \
		./enemies/bonkersIdle.o ./enemies/chefIdle.o \
 		gui.o background.o display.o window.o

window.o: window.c
	gcc -c -g window.c

gui.o: gui.c
	gcc -c -g gui.c

background.o: background.c
	gcc -c -g background.c

display.o: display.c
	gcc -c -g display.c

run:
	./program

clean:
	cd classes && make clean
	cd enemies && make clean
	rm -r -f *.o *.gch
