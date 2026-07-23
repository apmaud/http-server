#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>


int main()
{

  int status;
  struct addrinfo hints, *servinfo;

  memset(&hints, 0 , sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  if ((status = getaddrinfo(NULL, "3490", &hints, &servinfo)) != 0)
  {
    fprintf(stderr, "gai error: %s\n", gai_strerror(status));
    exit(1);
  }

  int s;
  s = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
  

  while (1)
  {
    printf("Waiting for request ... \n");
    sleep(1);
  }

  freeaddrinfo(servinfo);
}

