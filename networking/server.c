#include "networking.h"

void process(char *s);
void client_turn(int client_socket);

int main() {

    int listen_socket;
    int client_socket1;
    int client_socket2;
    listen_socket = server_setup();
    
    client_socket1 = server_connect(listen_socket);
    client_socket2 = server_connect(listen_socket);
    
  while (1){
      client_turn(client_socket1);
      client_turn(client_socket2);
  }
  close(client_socket1);
  close(client_socket2);
}

void client_turn(int client_socket) {
  char buffer[BUFFER_SIZE];

  while (read(client_socket, buffer, sizeof(buffer))) {

    printf("[server %d] received: [%s]\n", getpid(), buffer);
    process(buffer);
    write(client_socket, buffer, sizeof(buffer));
  }//end read loop
  /* close(client_socket); */
}

void process(char * s) {
  while (*s) {
    if (*s >= 'a' && *s <= 'z')
      *s = ((*s - 'a') + 13) % 26 + 'a';
    else  if (*s >= 'A' && *s <= 'Z')
      *s = ((*s - 'a') + 13) % 26 + 'a';
    s++;
  }
}
