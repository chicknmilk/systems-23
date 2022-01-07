#include "pipe_networking.h"

int toupper(int c) {
  if (c >= 'a' && c <= 'z') {
    return c - 'a' + 'A';
  }
  return c;
}

int main() {

  int from_client;
  int client_socket;

  from_client = server_setup();


  while (1) {
    client_socket = server_connect(from_client);

    char * res = calloc(BUFFER_SIZE, sizeof(char));
    int f = fork();

    if (!f) {

      while (read(client_socket, res, BUFFER_SIZE)) {
        int i = 0;

        while (res[i]) {
          res[i] = toupper(res[i]);
          i++;
        }

        write(client_socket, res, BUFFER_SIZE);
        printf("sent %s to client\n", res);
      }

      exit(0);
    }
    else close(client_socket);

    printf("connection established\n");

  }


  return 0;
}
