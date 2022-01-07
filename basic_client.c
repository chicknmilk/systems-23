#include "pipe_networking.h"


int main() {

  int socket;

  socket = client_handshake();

  while (1) {
    char *req = malloc(BUFFER_SIZE);

    printf("Enter a string: ");
    fgets(req, BUFFER_SIZE, stdin);
    sscanf(req, "%s", req);

    if (strcmp(req, "exit") == 0) {
      printf("Exiting...\n");
      break;
    }

    write(socket, req, BUFFER_SIZE);

    char *res = malloc(BUFFER_SIZE);
    read(socket, res, BUFFER_SIZE);

    printf("response: %s\n", res);

  }

  return 0;
}
