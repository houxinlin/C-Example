#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define WORK_PATH "/home/HouXinLin/test/"
#define RESPONSE_HEADER_OK "HTTP/1.1 200 OK\r\n";
#define RESPONSE_HEADER_404 "HTTP/1.1 404 OK\r\n";
char *append(char *string, char *newValue) {
    char *str = (char *) calloc(strlen(string) + strlen(newValue), sizeof(char));
    strcat(str, string);
    strcat(str, newValue);
    return str;
}

char *itoa(int num) {
    int temp = num;
    int count = 0;
    while (num > 0) {
        count += 1;
        num = num / 10;
    }
    char *result = calloc(count, sizeof(char));
    sprintf(result, "%d ", temp);
    return result;
}

char *addHeader(char src[], char header[], char value[]) {
    int size = strlen(src) + strlen(header) + strlen(value) + 5;
    char *result = (char *) calloc(size, sizeof(char));
    strcat(result, src);
    strcat(result, header);
    strcat(result, ":");
    strcat(result, value);
    strcat(result, "\r\n");
    return result;
}

char *addTxtBody(char src[], char body[]) {
    char *result = calloc(strlen(src) + strlen(body) + 2, sizeof(char));
    strcat(result, src);
    strcat(result, "\r\n");
    strcat(result, body);
    return result;
}

char *getFileFullPath(char *subName) {
    char *result = calloc(strlen(WORK_PATH) + strlen(subName), sizeof(char));
    strcat(result, WORK_PATH);
    strcat(result, subName);
    return result;
}

char *getResource(char data[]) {
    char *c1 = strchr(data, 32) + 1;
    char *c2 = strchr(c1, 32);
    int size = abs(c2 - c1);
    char *result = calloc(size, sizeof(char));
    strncpy(result, c1 + 1, size - 1);
    return result;
}

char *getFileContent(char file[]) {
    char path[] = WORK_PATH;
    char subName[50] = {0};
    strcpy(subName, file);
    strcat(path, subName);
    printf("%s", path);
    FILE *fp = fopen(path, "r");
    char buf[2048] = {0};
    char ch = -1;
    int count = 0;
    while ((ch = getc(fp)) != -1) {
        buf[count] = ch;
        count++;
    }
    char *result = calloc(count, sizeof(char));
    strcpy(result, buf);
    return result;
}

long int fileSize(char file_name[]) {
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        return -1;
    }
    fseek(fp, 0L, SEEK_END);
    long int res = ftell(fp);
    fclose(fp);
    return res;
}

void logd(long d) {
    printf("%d\n", d);
}


char *file2Byte(char fileName[]) {
    FILE *fp = fopen(fileName, "rb");
    unsigned char *result = calloc(fileSize(fileName), sizeof(char));
    int offset = 0;
    if (fp) {
        unsigned char buffer[4096];
        size_t sz;
        while ((sz = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
            for (int i = 0; i < sz; i++) {
                result[offset] = buffer[i];
                offset++;
            }
        }
    }
    return result;

}

char *strlwr(char *str) {
    int size = strlen(str);
    char *result = calloc(size, 1);
    for (int i = 0; i < size; i++) {
        if (str[i] <= 'Z' && str[i] >= 'A') {
            result[i] = str[i] + 32;
            continue;
        }
        result[i] = str[i];
    }
    return result;
}

int isTextFile(char fileName[]) {
    char *spot = strrchr(fileName, '.');
    char *start = (char *) &fileName[0];
    int nameLength = strlen(fileName);
    char *tag = start + (nameLength - 1);
    if (strcmp(tag, spot) != 0) {
        if (strcmp(".txt", strlwr(spot)) == 0) {
            return 1;
        }

    }
    return 0;
}

char *getResponseFileNameHeader(char *name) {
    char *result = calloc(21 + strlen(name) + 2, sizeof(char));

    strcat(result, "attachment; filename=\"");
    strcat(result, name);
    strcat(result, "\"");
    return result;
}

void downloadFile(int client, char fileName[]) {
    char *msg = RESPONSE_HEADER_OK;
    int size = fileSize(getFileFullPath(fileName));
    char *cSize = itoa(size);
    cSize = append(cSize, "\r\n");
    msg = addHeader(msg, "Content-Disposition", getResponseFileNameHeader(fileName));
    msg = addHeader(msg, "Content-Type", "application/octet-stream; charset=UTF-8");
    msg = addHeader(msg, "Content-Length", cSize);

    unsigned char *binary = file2Byte(getFileFullPath(fileName));
    send(client, msg, strlen(msg), 0);
    send(client, binary, size, 0);
    close(client);
}

void responseTxt(int client, char fileName[]) {
    char *msg = RESPONSE_HEADER_OK;
    msg = addHeader(msg, "Content-Type", "text/plain; charset=UTF-8");
    msg = addTxtBody(msg, getFileContent(fileName));
    send(client, msg, strlen(msg), 0);
    close(client);
}

void responseHtml(int client, char body[]) {
    char *msg = RESPONSE_HEADER_OK;
    msg = addHeader(msg, "Content-Type", "text/html; charset=UTF-8");
    msg = addTxtBody(msg, body);
    send(client, msg, strlen(msg), 0);
    close(client);
}

void start(int port) {

    int opt = 1;
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt)));

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    int addrlen = sizeof(address);
    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        printf("error\n");
    }
    if (listen(server_fd, 3) < 0) {
        printf("error\n");
    }
    while (1) {
        int c = accept(server_fd, (struct sockaddr *) &address, (socklen_t *) &addrlen);
        char buffer[2048] = {0};
        read(c, buffer, 2048);
        char *resource = getResource(buffer);
        if (strcmp(resource, "") == 0) {
            responseHtml(c, "<div style=\"color:red\">index</div>");
            continue;
        }


        if (strcmp(resource, "favicon.ico") == 0) {
            close(c);
            continue;
        }
        if (fileSize(getFileFullPath(resource)) == -1) {
            responseHtml(c, "<div style=\"color:red\">404</div>");
            continue;
        }

        /**
         * if is text file
         */
        if (isTextFile(resource)) {
            responseTxt(c, resource);
            continue;
        }
        downloadFile(c, resource);

    }
}

int main() {
    start(1111);
}