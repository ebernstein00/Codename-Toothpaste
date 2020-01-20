all: gui.o background.o display.o
	cd classes && make
	cd enemies && make


gui.o: gui.c
	gcc -c gui.c

background.o: background.c
	gcc -c background.c

display.o: display.c
	gcc -c display.c

clean:
	cd classes && make clean
	cd enemies && make clean
	rm -r -f *.o *.gch
