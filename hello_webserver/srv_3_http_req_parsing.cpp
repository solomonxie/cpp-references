/*
    $ clang++ -std=c++20 -Wall -Wextra -O0 -g hello_webserver/srv_3_http_req_parsing.cpp -o build/srv_3_http_req_parsing && ./build/srv_3_http_req_parsing
    then:
    curl localhost:9090/api/v1/ping
    or:
    open from browser: http://localhost:9090/api/v1/ping
*/

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string>
#include <sstream>  // for std::istringstream


struct HttpRequest {
    std::string method;
    std::string path;
    std::string http_version;
};


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
    std::string raw_request(recv_buf, bytes_read);
    std::cout << "Received: " << raw_request << std::endl;

    // Parse the request line
    std::istringstream stream(raw_request);  // e.g. "GET /ping HTTP/1.1"
    HttpRequest request;
    stream >> request.method;  // >> splits on whitespace, same idea as std::cin >>
    stream >> request.path;
    stream >> request.http_version;

    // Build response
    std::string body =
        "<h1>Parsed request line</h1>\n"
        "<p>Method: " + request.method + "</p>\n"
        "<p>Path: " + request.path + "</p>\n"
        "<p>Version: " + request.http_version + "</p>\n";
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
