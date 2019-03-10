#include "unp.h"
#include <iostream>

int main()
{
    int listenfd, connfd;
    socklen_t len;
    struct sockaddr_in servaddr, cliaddr;
    char buff[MAXLINE];
    time_t ticks;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    std::cout<< htonl(INADDR_ANY) <<std::endl;
    servaddr.sin_port = htons(13);
    std::cout<< htons(13)<<std::endl;
    bind(listenfd, (SA*)&servaddr, sizeof(servaddr));
    int listens = listen(listenfd, LISTENQ);
    std::cout<< listens <<std::endl;

    while (1) {
        len = sizeof(cliaddr);
        connfd = accept(listenfd, (SA*)&cliaddr, &len);
        printf("connection from %s, port %d\n", inet_ntop(AF_INET, &cliaddr.sin_addr, buff, sizeof(buff)), ntohs(cliaddr.sin_port));
        ticks = time(NULL);
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
        write(connfd, buff, strlen(buff));
        close(connfd);
    }
}
