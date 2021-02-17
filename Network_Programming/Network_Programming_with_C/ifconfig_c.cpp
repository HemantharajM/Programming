//Listing network adapter
#include <iostream>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory>

int main()
{
  //Variable to store linked list of adapter address family
  struct ifaddrs* addresses;
  
  if(getifaddrs(&addresses) == -1) { //set addressess 
    std::cout << "getifaddrs call failed\n";
    return -1;
  }

  struct ifaddrs* address = addresses; //set address to header of linkedlist

  while(address) {  //traverse through address

    int family = address->ifa_addr->sa_family; 
     int family_size ;
    char ap[100];
    
    std::cout << "Adapter name : " << address->ifa_name << std::endl;

    if(family == AF_INET || family == AF_INET6) { //Checking Family Name
      if(family == AF_INET) {
        std::cout << "Adapter address family : " << family;
        family_size = sizeof(struct sockaddr_in);
      }else {
        std::cout << "Adapter address family : " << family;
        family_size = sizeof(struct sockaddr_in6);
      }

      getnameinfo(address->ifa_addr, family_size, ap, sizeof(ap), 0, 0, NI_NUMERICHOST);
      std::cout << ap << std::endl; 
    }
  
    address = address->ifa_next; //go to next adapter 
  }

  return 0;
}
