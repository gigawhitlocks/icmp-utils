#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <string.h>

/*
 *  USAGE: ping IP_ADDRESS
 * 
*/
int main(int argc, char* argv[]) {
  if ( argc != 2 ) {
    fprintf(stderr,"Use the correct argument, dumbass. (ping IP-ADDR)\n");
    exit(1);
  }

  char* host = argv[1];
  int sock = socket(PF_INET, SOCK_RAW, IPPROTO_ICMP);
  
  if ( sock < 0 ) {
    perror("socket");
    exit(1);

  }

  struct addrinfo *ai;
  if (getaddrinfo ( host, NULL, NULL, &ai ) < 0 ) { 
    perror("getaddrinfo");
    exit(1);
  }
  
  struct icmp message;
  message.icmp_type = ICMP_ECHO;        // 8
  message.icmp_code = ICMP_ECHOREPLY;  // 0
  message.icmp_cksum = 0;
  message.icmp_hun.ih_idseq.icd_id = 1337; // we r so leet
  message.icmp_hun.ih_idseq.icd_seq = 0;
  memset(&message.icmp_dun, 0, sizeof(message.icmp_dun));


  

//  sendto(sock, /*data to send*/)
}
