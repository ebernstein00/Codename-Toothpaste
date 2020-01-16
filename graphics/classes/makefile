all: fighterIdle.o mageIdle.o knightIdle.o rogueIdle.o

fighterIdle.o: fighterIdle.c
	gcc -c -g fighterIdle.c

mageIdle.o: mageIdle.c
	gcc -c -g mageIdle.c

knightIdle.o: knightIdle.c
	gcc -c -g knightIdle.c

rogueIdle.o: rogueIdle.c
	gcc -c -g rogueIdle.c

run:
	./program

clean:
	rm -f *.o *.gch
