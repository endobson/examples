#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

int main (int argc, char** argv) {
  int sock;
  struct sockaddr_in serv_addr;
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("\n Socket creation error \n");
    return -1;
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(80);

  if (inet_aton("169.254.169.254", &serv_addr.sin_addr) <= 0) {
    printf("\nInvalid address/ Address not supported \n");
    return -1;
  }

  if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
    printf("\nConnection Failed: %d \n", errno);
    return -1;
  }
  char* request = "GET /computeMetadata/v1/instance/service-accounts/default/token HTTP/1.1\r\nHost: metadata.google.internal\r\nMetadata-Flavor: Google\r\n\r\n";

  if (argc == 1 || argc == 2) {
    if (send(sock, request, strlen(request), 0) < 0) {
      printf("\nSend failed\n");
    }
    if (argc == 2) {
      shutdown(sock, SHUT_WR);
    }
  }

  int amt_read;
  char buffer[2048];
  while (1) {
    if ((amt_read = read(sock, buffer, 2048)) < 0) {
      printf("\nRead failed\n");
      return -1;
    }
    if (amt_read == 0) break;

    if (write(STDOUT_FILENO, buffer, amt_read) != amt_read) {
      printf("\nWrite failed\n");
      return -1;
    }
  }
  close(sock);


  return 0;
}
