#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>


int main (int argc, char* argv[]){

if(argc!=3){
	printf("Usage: %s <ip-address> <port>\n", argv[0]);
	exit(1); 
}
   char* ip_address = argv[1];
   int port = atoi(argv[2]);

   struct sockaddr_in host_addr; 

   host_addr.sin_family = AF_INET; 
   host_addr.sin_port = htons(port);
   host_addr.sin_addr.s_addr = inet_addr(ip_address);

   char hostname[1024];
   char service[20];

   getnameinfo((struct sockaddr *) &host_addr, sizeof(host_addr), hostname, sizeof(hostname), service, sizeof(service), 0);

   printf("Hostname: %s\n", hostname);
   printf("Service %s\n", service);



}