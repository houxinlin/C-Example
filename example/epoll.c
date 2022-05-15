//
// Created by hxl on 2022/5/15.
//

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

#define MAXEVENTS 64

int main() {
    int opt = 1;
    int port = 8080;
    struct epoll_event event;
    struct epoll_event *events;
    int sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)));

    struct sockaddr_in ser_addr;
    ser_addr.sin_family = AF_INET;
    ser_addr.sin_addr.s_addr = INADDR_ANY;
    ser_addr.sin_port = htons(port);

    if (bind(sfd, (struct sockaddr *) &ser_addr, sizeof(ser_addr))) {
        printf("bind socket failure:%s\n", strerror(errno));
        return -1;
    }
    int flags = fcntl(sfd, F_GETFD, 0);
    fcntl(sfd, F_SETFD, flags |= O_NONBLOCK);

    if (listen(sfd, SOMAXCONN) == -1) {
        printf("listen socket failure:%s\n", strerror(errno));
        return -1;
    }
    int efd = epoll_create1(0);
    if (efd == -1) {
        printf("epoll_create1  failure:%s\n", strerror(errno));
        return -1;
    }


    event.data.fd = sfd;
    event.events = EPOLLIN;

    if (epoll_ctl(efd, EPOLL_CTL_ADD, sfd, &event) == -1) {
        printf("epoll_ctl failure:%s\n", strerror(errno));
        return -1;
    }

    events = calloc(MAXEVENTS, sizeof event);
    while (1) {
        int n = epoll_wait(efd, events, MAXEVENTS, -1);
        for (int i = 0; i < n; i++) {
            if (events[i].data.fd == sfd) {
                struct sockaddr in_addr;
                socklen_t in_len;
                in_len = sizeof in_addr;
                int cfd = accept(sfd, &in_addr, &in_len);
                int flags = fcntl(cfd, F_GETFD, 0);
                fcntl(cfd, F_SETFD, flags |= O_NONBLOCK);
                event.data.fd = cfd;
                event.events = EPOLLIN;
                epoll_ctl(efd, EPOLL_CTL_ADD, cfd, &event) == -1;
            } else {
                int sockfd_r;
                char buf[512];
                read(events[i].data.fd, buf, sizeof buf);
                printf("%s\n", buf);
                close(events[i].data.fd);
            }
        }
    }
    close(sfd);
    return 0;

}