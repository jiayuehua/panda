#include  "unp.h"

int
main(int argc, char **argv)
{
  int         sockfd;
  struct sockaddr_un  cliaddr, servaddr;

  sockfd = Socket(AF_LOCAL, SOCK_DGRAM, 0);

  bzero(&cliaddr, sizeof(cliaddr));   /* bind an address for us */
  cliaddr.sun_family = AF_LOCAL;
  //strcpy(cliaddr.sun_path, tmpnam(NULL));
  strcpy(cliaddr.sun_path, "/tmp/unixdgclient8");
  int val = 1;
  unlink(cliaddr.sun_path);


  bind(sockfd, (SA *) &cliaddr, sizeof(cliaddr));

  bzero(&servaddr, sizeof(servaddr)); /* fill in server's address */
  servaddr.sun_family = AF_LOCAL;
  strcpy(servaddr.sun_path, UNIXDG_PATH);


  dg_client( sockfd, (const SA*)&servaddr, sizeof(servaddr));

  exit(0);
}
