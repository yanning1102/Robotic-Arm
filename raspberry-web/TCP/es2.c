/*Required Headers*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
                int     socket_id;
        
        socket_id = socket(PF_INET, SOCK_STREAM, 0);
        printf("Connection socket id: %d\n", socket_id);

	////////////////
	struct sockaddr_in	s_add;	// server address
	int	status;

        s_add.sin_family= AF_INET;
        s_add.sin_port= htons(10000);
        s_add.sin_addr.s_addr = inet_addr("192.168.156.11");

        status = connect(socket_id,
			(struct sockaddr *) &s_add, sizeof(s_add));
        printf("status = %d\n", status);
	
	///////////////
	char	request[] = "Request from Teacher";
	int	send_bytes;
	
	printf("Request sent: %s\n", request);
        send_bytes = send(socket_id, request, strlen(request), 0);
        if (send_bytes != strlen(request))
        {
                printf("send() failed...\n");
                exit(1);
        }
	
	////////////
	char	response[100];
	int	response_size;
	
	bzero(response, 100);
	response_size = recv(socket_id, response, 100, 0);
        if (response_size < 0)
        {
                printf("recv() failed...\n");
                exit(1);
        }
        printf("Response received: %s\n", response);
	
	close(socket_id);
}
