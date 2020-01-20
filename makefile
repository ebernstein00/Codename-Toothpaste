all: game.o
	cd library && make
	cd graphics && make
	gcc -o program  $(files) -lSDL2 -lSDL2_image

files =  ./graphics/classes/fighterIdle.o ./graphics/classes/mageIdle.o ./graphics/classes/rogueIdle.o ./graphics/classes/knightIdle.o \
	./graphics/enemies/galactaIdle.o ./graphics/enemies/dededeIdle.o ./graphics/enemies/waddledeeIdle.o ./graphics/enemies/waddledooIdle.o ./graphics/enemies/knucklejoeIdle.o \
	./graphics/enemies/bonkersIdle.o ./graphics/enemies/chefIdle.o \
	./graphics/gui.o ./graphics/background.o ./graphics/display.o \
	./library/characters.o ./library/items.o ./library/gameflow.o \
	game.o

game.o: game.c
		gcc -c game.c
run:
	./program

clean:
	cd library && make clean
	cd graphics && make clean
	rm -r -f *.o *.gch
