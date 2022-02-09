#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>

int main()
{
    unsigned char ip_address[15];
    int fd;
    struct ifreq ifr;

    fd = socket(AF_INET, SOCK_DGRAM, 0);

    ifr.ifr_addr.sa_family = AF_INET;
    memcpy(ifr.ifr_name, "wlp5s0", IFNAMSIZ - 1);

    ioctl(fd, SIOCGIFADDR, &ifr);
    close(fd);

    strcpy(ip_address, inet_ntoa(((struct sockaddr_in*)&ifr.ifr_addr)->sin_addr));

    printf("System IP Address is: %s\n", ip_address);

    return 0;
}