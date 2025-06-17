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
#include <mysql.h>

// Parameters used in mysql_real_connect()
static char *host_name = NULL; 		// server host (default=localhost)
static char *user_name = "test"; 	// username (default=login name)
static char *password = "test"; 	// password (default=none)
static unsigned int port_num = 0; 	// port number (use built-in value)
static char *socket_name = NULL; 	// socket name (use built-in value)
static char *db_name = NULL; 		// database name (default=none)
static unsigned int flags = 0; 		// connection flags (none)

static MYSQL *conn;			// pointer to connection handler

int main(int argc, char **argv)
{
	int     socket_id;
	
	///////////////////////// Database 
	
	if ((conn = mysql_init(NULL)) == NULL) 
	{
		printf("%s\n", mysql_error(conn));
		exit(1);
	}

	if (mysql_real_connect(conn, host_name, user_name, password,
			db_name, port_num, socket_name, flags) == NULL) 
	{
		printf("%s\n", mysql_error(conn));
		mysql_close(conn);
		exit(1);
	}
	
	if (mysql_select_db(conn, "test")) 
		printf("%s\n", mysql_error(conn));
	else	printf("Database test select success.\n");
	
	char	sqlstring[300];
	MYSQL_RES *result;
	MYSQL_ROW row;
	int	num_fields, i;
	
	strcpy(sqlstring, "SELECT * FROM test1 where SID=12");
	
	if (! mysql_query(conn, sqlstring))
	{
		
		
	
		result = mysql_store_result(conn);
		if (result != NULL) 
		{
			num_fields = mysql_num_fields(result);
			while (row = mysql_fetch_row(result)) 
			{ 
				for(i = 0; i < num_fields; i++) 
					printf("%s ", row[i] ? row[i] : "NULL");  //把資料庫資串抓到row[0]
				printf("\n"); 
			}
			mysql_free_result(result);
		}
	}
	
	mysql_close(conn);
	
	////////////////////////////////////////// Database End
      
	
        socket_id = socket(PF_INET, SOCK_STREAM, 0);
        printf("Connection socket id: %d\n", socket_id);

	/////
	struct sockaddr_in	s_add;	// server address
	int	status;

        s_add.sin_family= AF_INET;
        s_add.sin_port= htons(10000);
        s_add.sin_addr.s_addr = inet_addr("192.168.156.11");

        status = connect(socket_id,
			(struct sockaddr *) &s_add, sizeof(s_add));
        printf("status = %d\n", status);
	
	//////////////////
	char	request[300];
	int	send_bytes;
	
	sprintf(request, "%s,%s,%s", row[0], row[1], row[2]);//這句怪怪
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


