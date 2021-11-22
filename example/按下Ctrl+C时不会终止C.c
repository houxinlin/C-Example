#include <signal.h>
#include <stdio.h>

void sigintHandler(int sig_num) {
    signal(SIGINT, sigintHandler);
    printf("\n 就是不让你终止 \n");
    fflush(stdout);
}

/**
 * SIGABRT——异常终止。
SIGFPE – 浮点异常。
SIGILL – 无效指令。
SIGINT – 发送到程序的交互式注意请求。
SIGSEGV – 无效的内存访问。
SIGTERM – 发送到程序的终止请求。
 * @return
 */
int main() {
    signal(SIGINT, sigintHandler);
    while (1) {
    }
    return 0;
}