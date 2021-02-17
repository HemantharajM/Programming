/**
 * TOM_SERVER implement SERVER implementation
 */

#include "Tom_Server.h"

/**
 * @brief Server Listen for any new connection at this port 
 */
void Tom_Server::Tom_listen()
{
    printf("Listening...\n");
    if(listen(socket_listen, _connection_queue_len) < 0) {
        fprintf(stderr, "listen() failed. (%d)\n", GETSOCKETERRNO());
    }
}

/**
 * @brief Server Accept new connection at this port 
 */
void Tom_Server::Tom_accept()
{
  printf("Waiting for connection...\n");
  _socket_client = accept(socket_listen, (struct sockaddr*) &_client_address, &_client_len);

  if(!ISVALIDSOCKET(_socket_client)) {
    fprintf(stderr, "accept() failed. (%d)\n", GETSOCKETERRNO());
  }

  printf("Client is connected...\n");
  
  getnameinfo((struct sockaddr*)&_client_address, _client_len, _address_buffer, sizeof(_address_buffer), 0, 0, NI_NUMERICHOST);
  printf("%s\n", _address_buffer);

}

/**
 * @brief recv msg over socket
 */
void Tom_Server::Tom_recv()
{
    printf("Reading request... \n");
    char request[1024];
    int bytes_received = recv(_socket_client, request, 1024, 0);
    printf("Received %d bytes. \n", bytes_received)
}

/**
 * @brief Send msg over socket
 */
void Tom_Server::Tom_recv()
{
    printf("Sending respose...\n");
    const char *response = 
                "HTTP/1.1 200 OK\r\n"
                "Connection: close\r\n"
                "Content-Type: text/plain\r\n\r\n"
                "Local time is: ";

  int bytes_sent = send(_socket_client, response, strlen(response), 0);

  printf("Sent %d of %d bytes.\n", bytes_sent, (int)strlen(response));

  time_t timer;
  time(&timer);
  char *time_msg = ctime(&timer);
  bytes_sent = send(_socket_client, time_msg, strlen(time_msg),0);
  
  printf("Send %d of %d bytes.\n", bytes_sent, (int)strlen(time_msg));

  printf("Closing connection...\n");
}