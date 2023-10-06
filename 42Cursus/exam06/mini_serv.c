#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

#define MAX_CLIENTS 128
#define BUFFER_SIZE 200000

void	ftErr( char *err ){

	write(STDERR_FILENO, err, strlen(err));
	exit (1);
}

int main( int ac, char **av ){

	if (ac != 2)
		ftErr("args\n");

	int		clientSockets[MAX_CLIENTS] = {0};
	int		nextId = 0;
	fd_set	activeSockets, readySockets;
	char	buffer[BUFFER_SIZE];

	int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket < 0)
		ftErr("socket\n");

	struct sockaddr_in serverAddress = {0};
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	serverAddress.sin_port = htons(atoi(av[1]));
	if ( bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0 )
		ftErr("bind\n");

	if ( listen(serverSocket, MAX_CLIENTS) < 0 )
		ftErr("listen\n");

	FD_ZERO(&activeSockets);
	FD_SET(serverSocket, &activeSockets);
	int maxSocket = serverSocket;

	while (1){
	
		int clientId;
		readySockets = activeSockets;
		if ( select(maxSocket + 1, &readySockets, NULL, NULL, NULL) < 0 )
			ftErr("select\n");

		for (int sockId = 0; sockId <= maxSocket; sockId++){
		
			memset(buffer, 0, BUFFER_SIZE);
			for (clientId = 0; clientId < nextId && clientSockets[clientId] != sockId; clientId++)
				;

			if ( FD_ISSET(sockId, &readySockets) ){
			
				if (sockId == serverSocket){
				
					int clientSocket = accept(sockId, NULL, NULL);
					if (clientSocket < 0)
						ftErr("accept\n");

					FD_SET(clientSocket, &activeSockets);
					maxSocket = (clientSocket > maxSocket) ? clientSocket : maxSocket;

					sprintf(buffer, "client %d arrived\n", nextId);
					for (int i = 0; i < nextId; i++)
						send(clientSockets[i], buffer, strlen(buffer), 0);

					clientSockets[nextId] = clientSocket;
					nextId++;
				}
				else{
				
					int bytesReceived = recv(sockId, buffer, BUFFER_SIZE - 1, 0);
					if (bytesReceived <= 0){
					
						sprintf(buffer, "client %d removed\n", clientId);
						for (int i = 0; i < nextId; i++)
							if (i != clientId)
								send(clientSockets[i], buffer, strlen(buffer), 0);

						close(sockId);
						clientSockets[clientId] = 0;
						FD_CLR(sockId, &activeSockets);
					}
					else{
					
						char tempBuff[BUFFER_SIZE + 50] = {0};
						sprintf(tempBuff, "client %d: %s", clientId, buffer);

						for (int i = 0; i < nextId; i++)
							if (i != clientId)
								send(clientSockets[i], tempBuff, strlen(tempBuff), 0);
					}
				}
			}
		}
	}
	return(0);
}
