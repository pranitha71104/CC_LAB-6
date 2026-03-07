#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <netinet/in.h>

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(80);

    bind(server_fd, (struct sockaddr*)&address, sizeof(address));
    listen(server_fd, 5);

    char hostname[1024];
    gethostname(hostname, 1024);

    while (true) {
        int client = accept(server_fd, NULL, NULL);

        std::string response =
        "HTTP/1.1 200 OK\nContent-Type: text/plain\n\nServed by backend: ";
        response += hostname;

        send(client, response.c_str(), response.size(), 0);
        close(client);
    }

    return 0;
}
