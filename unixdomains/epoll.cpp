#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <errno.h>
#include <vector>
#include <utility>
#include "unp.h"
enum {MAXEVENTS = 2};

int
dg_client(int sfd, const SA* pSA, socklen_t len)
{
  int var = Fcntl(sfd, F_GETFL, 0);
  Fcntl(sfd, F_SETFL, var | O_NONBLOCK);
  int s;
  int efd;
  struct epoll_event *events;
  struct epoll_event event;
  event.data.fd = sfd;
  event.events = EPOLLIN  | EPOLLET;
  efd = epoll_create1(0);

  if (efd == -1) {
    perror("epoll_create");
    abort();
  }

  s = epoll_ctl(efd, EPOLL_CTL_ADD, sfd, &event);

  if (s == -1) {
    perror("epoll_ctl");
    abort();
  }

  /* Buffer where events are returned */
  events = (epoll_event *)calloc(MAXEVENTS, sizeof event);

  for (;;) {
    int n, j;
    n = epoll_wait(efd, events, MAXEVENTS, 0);
    int done = 0;
    char buf[512];

    if ( Fgets(buf, sizeof buf, stdin)) {
      ssize_t count = sendto(sfd, buf, strlen (buf), 0, pSA, len );

      if (count == -1) {
        if (errno != EAGAIN) {
          perror("sendto");
        }
      } else if (count == 0) {
      }
    }

    for (j = 0; j < n; j++) {
      if ((events[j].events & EPOLLERR) ||
          (events[j].events & EPOLLHUP)
         ) {
        /* An error has occured on this fd, or the socket is not
        ready for reading (why were we notified then?) */
//        close(events[i].data.fd);
        continue;
      } else if (sfd == events[j].data.fd) {
        if (events[j].events & EPOLLIN) {
          /* We have data on the fd waiting to be read. Read and
          display it. We must read whatever data is available
          completely, as we are running in edge-triggered mode
          and won't get a notification again for the same
          data. */
          int done = 0;

          while (1) {
            ssize_t count;
            char buf[512];
            count = recvfrom(events[j].data.fd, buf, sizeof buf, 0 ,0 , 0);

            if (count == -1) {
              /* If errno == EAGAIN, that means we have read all
              data. So go back to the main loop. */
              if (errno != EAGAIN) {
                perror("read");
              }

              break;
            } else if (count == 0) {
              /* End of file. The remote has closed the
              connection. */
              break;
            }

            //           jia handle read
            buf[count] = 0;
            Fputs(buf, stdout);
          }
        }
      }
    }
  }

  free(events);
  close(sfd);
  return EXIT_SUCCESS;
}
