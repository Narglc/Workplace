#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<ctype.h>

#define SERV_PORT 9527

void sys_err(const char* str)
{
    perror(str);
    exit(1);
}

#define CHECK_RESULT(result, equal_val, info) 	\
	if(result == equal_val)						\
	{											\
		sys_err(info);							\
	}

int main(int argc, char *argv[])
{
	int lfd = 0;
	lfd = socket(AF_INET, SOCK_STREAM, 0);
	CHECK_RESULT(lfd, -1, "socket fail");

	struct sockaddr_in serv_addr;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port   = htons(SERV_PORT);
	int dst;
	int pton_rst = inet_pton(AF_INET,"10.211.55.7",(void*)&dst);
	CHECK_RESULT(pton_rst, -1, "invalid ip address");
	CHECK_RESULT(pton_rst, 0, "not contain a character string");

	printf("---> %x- pton_rst:%d\n", dst, pton_rst);
	serv_addr.sin_addr.s_addr = dst;
	int bind_rst = bind(lfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	CHECK_RESULT(bind_rst, -1, "bind fail");

	int listen_rst = listen(lfd, 128);
	CHECK_RESULT(listen_rst, -1, "listen fail");

	struct sockaddr_in client_addr;
	socklen_t client_addr_len = sizeof(client_addr);
	int cfd = accept(lfd, (struct sockaddr*)&client_addr, &client_addr_len);
	CHECK_RESULT(cfd, -1, "accept fail");

	char client_ip[1024];
	printf("client_ip:%s,port:%d\n",
		inet_ntop(AF_INET, &client_addr.sin_addr.s_addr, client_ip, sizeof(client_ip)),
		ntohs(client_addr.sin_port));

	char buf[4096]; //BUFSIZ];
	int counter = 10;
	int info_len;
	int i;
	while(counter--)
	{
		info_len = read(cfd, buf, sizeof(buf));
		for(i = 0; i < info_len; i++)
			buf[i] = toupper(buf[i]);
		write(cfd, buf, info_len);
		sleep(1);
	}

	close(cfd);
	close(lfd);
	return 0;
}
