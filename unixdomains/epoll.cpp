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
dg_client(int sfd)
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
  /* The event loop */
  /* The event loop */
  /* The event loop */
  /* The event loop */
  int i = 0;

  for (;; ++i) {
    printf(" ------0--%d \n", i);
    int n, i;
    n = epoll_wait(efd, events, MAXEVENTS, 0);
    printf(" ------1--%d \n ", i);
    int done = 0;
    printf(" ------4--%d \n ", i);
    char buf[512];

    if ( Fgets(buf, sizeof buf, stdin)) {
      ssize_t count = write(events[i].data.fd, buf, strlen (buf) );

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

      if (s == -1) {
        perror("write");
      }
    }

    for (i = 0; i < n; i++) {
      if ((events[i].events & EPOLLERR) ||
          (events[i].events & EPOLLHUP)
         ) {
        /* An error has occured on this fd, or the socket is not
        ready for reading (why were we notified then?) */
        fprintf(stderr, "epoll error\n");
//        close(events[i].data.fd);
        continue;
      } else if (sfd == events[i].data.fd) {
        if (events[i].events & EPOLLIN) {
          printf(" ------2--%d \n", i);
          /* We have data on the fd waiting to be read. Read and
          display it. We must read whatever data is available
          completely, as we are running in edge-triggered mode
          and won't get a notification again for the same
          data. */
          int done = 0;

          while (1) {
            printf(" ------3--%d \n", i);
            ssize_t count;
            char buf[512];
            count = read(events[i].data.fd, buf, sizeof buf);

            if (count == -1) {
              /* If errno == EAGAIN, that means we have read all
              data. So go back to the main loop. */
              if (errno != EAGAIN) {
                perror("read");
                printf(" ------3.0--%d \n", i);
              }

              printf(" ------3.1--%d \n", i);
              break;
            } else if (count == 0) {
              /* End of file. The remote has closed the
              connection. */
              printf(" ------3.2--%d \n", i);
              break;
            }

            //           jia handle read
            buf[count] = 0;
            printf(" ------3.3--%d \n", i);
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