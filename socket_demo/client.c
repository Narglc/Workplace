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
	int cfd = 0;
	cfd = socket(AF_INET, SOCK_STREAM, 0);
	CHECK_RESULT(cfd, -1, "socket fail");

	struct sockaddr_in serv_addr;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port   = htons(SERV_PORT);
	inet_pton(AF_INET, "10.211.55.7", &serv_addr.sin_addr.s_addr);
	//inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr.s_addr);
	int connet_rst = connect(cfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	CHECK_RESULT(connet_rst, -1, "connect fail");

	char buf[4096]; //BUFSIZ];
	int counter = 10;
	while(counter--)
	{
		write(cfd, "hello, the world", 18);
		int ret = read(cfd, buf, sizeof(buf));
		printf("got rsp:%s\n", buf);
	}

	close(cfd);
	return 0;
}
