#include <stdio.h>
#include "tcp.h"

int main() {
    tcp_server server = {0};
    server_status_e status = bind_tcp_port(&server, 8080);
    if (status != SERVER_OK) {
        fprintf(stderr, "Server initialization failed");
        return -1;
    }

    int client_fd = accept_client(server.socket_fd);
    if (client_fd == -1) {
        fprintf(stderr, "Failed to accept client connection");
        close(server.socket_fd);
        return -1;
    }

    printf("Client connected");

    close(client_fd);
    close(server.socket_fd);
    return 0;
}
