/* --- server.c --- */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>

const char usage[] = "usage: ./a.out [-p port] [-s string]";

int main(int argc, char *argv[])
{
	int listenfd, connfd, port, c = 0;
	struct sockaddr_in serv_addr;
	char *buf = 0;

	while((c = getopt(argc, argv, "p:s:")) != -1)
		switch(c){
		case 'p':
			port = atoi(optarg);
			break;
		case 's':
			buf = optarg;
			break;
		default:
			puts(usage);
			exit(1);
		}
	
	if(buf == 0)
		buf = "pong pong";
	if(port == 0)
		port = 2020;

	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(port);
	bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	listen(listenfd, 10);

	printf("starting server on port %d, with string '%s'\n", port, buf);
	fflush(0);

	while(1)
	{
		connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);
		dprintf(connfd, "%s\n", buf);
		close(connfd);
		sleep(1);
	}
}
