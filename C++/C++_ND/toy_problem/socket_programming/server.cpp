//Writing socket programming 
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

int main()
{
  //Create Socket
  int listening = socket(AF_INET, SOCK_STREAM, 0); //__Domain, __type, __protocol
  
  if(listening == -1) {
    std::cerr << "Can't Create socket\n";
    return -1;
  }
  //Bind the Socket to a IP/Port
  sockaddr_in hint;
  hint.sin_family = AF_INET;
  hint.sin_port = htons(54000); //host to network short[Big endian / little endian]
  inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr); //pointer to number (127.0.0.1) 
  
  if(bind(listening, (sockaddr*)&hint, sizeof(hint)) == -1) {
    std::cerr << "Can't bind to IP/port\n";
    return -2;
  }
  //Mark the Socket for Listening
  if(listen(listening, SOMAXCONN) == -1) { //Maximum connection 128
    std::cerr << "Can't listen\n";
    return -3;
  }
  //Accept a call
  sockaddr_in client;
  socklen_t clientSize = sizeof(client);
  char host[NI_MAXHOST]; //NI_MAXHOST = 1024
  char svc[NI_MAXSERV]; // NI_MAXSERV = 32

  int clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

  if(clientSocket == -1) {
    std::cerr << "Problem with client connecting\n";
    return -4;
  }

  //Close the listening Socket
  close(listening);

  memset(host, 0, NI_MAXHOST);
  memset(svc, 0, NI_MAXSERV);

  int result = getnameinfo((sockaddr*) &client, sizeof(client), host, NI_MAXHOST, svc, NI_MAXSERV, 0);

  if(result) {
    std::cout << host << " connected on " << svc << std::endl;
  } else {
    inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
    std::cout << host << " connected on " << ntohs(client.sin_port) << std::endl;
  }

  //while receiving display message, echo message
  char buf[4096];

  while(true) {
    //Clear the buffer
    memset(buf, 0, 4096);
    //Wait for a message
    int bytesRecv = recv(clientSocket, buf, 4096, 0);
    if(bytesRecv == -1) {
      std::cerr << "There was a connection issue\n" << std::endl;
      break;
    }

    if(bytesRecv == 0){
      std::cout << "The client is disconnected\n";
      break;
    }
    //Display message
    std::cout << "Received: " << std::string(buf, 0, bytesRecv) << std::endl;
    //Resent message
    send(clientSocket, buf, bytesRecv + 1, 0);
  }
  //close socket
  close(clientSocket);

  return 0;
}
