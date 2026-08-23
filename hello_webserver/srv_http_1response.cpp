/*
    $ clang++ -std=c++20 -Wall -Wextra -O0 -g srv_http_1response.cpp -o build/srv_http_1response && ./build/srv_http_1response
    then:
    curl localhost:9090
    or:
    open from browser: http://localhost:9090
*/

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string>


int main() {
    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(9090);

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    int bind_result = bind(
        server_fd,
        reinterpret_cast<sockaddr*>(&server_addr),
        sizeof(server_addr)
    );
    std::cout << "bind() returned: " << bind_result << std::endl;

    int listen_result = listen(server_fd, 16);
    std::cout << "listen() returned: " << listen_result << std::endl;

    std::cout << "Waiting for a connection...\n";
    int client_fd = accept(server_fd, nullptr, nullptr);
    std::cout << "Accepted client FD: " << client_fd << std::endl;

    char recv_buf[2048];
    int bytes_read = recv(client_fd, recv_buf, sizeof(recv_buf) - 1, 0);
    std::string request(recv_buf, bytes_read);
    std::cout << "Received: " << request << std::endl;

    std::string body = "<h1>You sent:</h1>\n<pre>\n" + request + "\n</pre>";

    // Every header line needs a trailing "\r\n" (the body doesn't)
    std::string response =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "Content-Length: " + std::to_string(body.size()) + "\r\n"
        "\r\n" + body;
    int bytes_written = send(client_fd, response.c_str(), response.size(), 0);
    std::cout << "Sent bytes: " << bytes_written << std::endl;

    int close_result = close(client_fd);
    std::cout << "close() returned: " << close_result << std::endl;

    return 0;
}
