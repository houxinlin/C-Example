#include <netdb.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>

void main() {
    struct hostent *host;
    host = gethostbyname("www.houxinlin.com");
    char *item = host->h_addr_list[0];
    char buf[255];
    char *result = inet_ntop(host->h_addrtype, item, buf, 255);
    printf("%s", buf);
};
