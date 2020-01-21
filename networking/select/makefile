all: client server

server: select_server.o networking.o
	gcc -o server select_server.o networking.o

client: select_client.o networking.o
	gcc -o client select_client.o networking.o

select_client.o: select_client.c networking.h
	gcc -c select_client.c

select_server.o: select_server.c networking.h
	gcc -c select_server.c

networking.o: networking.c networking.h
	gcc -c networking.c

clean:
	rm *.o
	rm *~
