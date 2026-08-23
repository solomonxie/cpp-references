/*
    $ clang++ -std=c++20 -Wall -Wextra -O0 -g hello_webserver/srv_6_file_links.cpp -o /tmp/srv_6_file_links && /tmp/srv_6_file_links
    then:
    curl -v localhost:9090/about
    or:
    open from browser: http://localhost:9090/about
*/

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string>
#include <sstream>
#include <fstream>     // std::ifstream
#include <filesystem>  // std::filesystem::exists()


struct HttpRequest {
    std::string method;
    std::string path;
    std::string http_version;
};

struct HttpResponse {
    int status_code = 200;
    std::string status_name = "OK";
    std::string content_type = "text/plain";
    std::string body;
};

std::string detect_content_type(std::string filename) {
    std::string content_type;
    if (filename.ends_with(".html")) {
        content_type = "text/html";
    } else if (filename.ends_with(".css")) {
        content_type = "text/css";
    } else if (filename.ends_with(".js")) {
        content_type = "application/javascript";
    } else if (filename.ends_with(".json")) {
        content_type = "application/json";
    } else if (filename.ends_with(".jpeg")) {
        content_type = "image/jpeg";
    } else if (filename.ends_with(".png")) {
        content_type = "image/png";
    } else {
        content_type = "text/plain";
    }
    return content_type;
}


HttpRequest parse_request(std::string raw_request) {
    std::istringstream stream(raw_request);  // e.g. "GET /ping HTTP/1.1"
    HttpRequest request;
    stream >> request.method;
    stream >> request.path;
    stream >> request.http_version;
    return request;
}


HttpResponse build_response(std::string path) {
    HttpResponse response;
    // Route the request
    if (path == "/") {
        path = "/index.html";
    }
    std::string filename = "hello_webserver/static" + path;
    std::cout << "Reading file path: " + filename << std::endl;

    // Check existence
    if (!std::filesystem::exists(filename)) {
        response.status_code = 404;
        response.status_name = "NOT FOUND";
        filename = "hello_webserver/static/404.html";
    }

    // Guess the content type
    response.content_type = detect_content_type(filename);

    // Read the file for the response body
    std::cout << "Reading content from file: " << filename << std::endl;
    std::ifstream file_stream(filename);
    std::string content((std::istreambuf_iterator<char>(file_stream)), std::istreambuf_iterator<char>());

    // Wrap it in an HTTP response
    response.body =
        "HTTP/1.1 " + std::to_string(response.status_code) + " " + response.status_name + " \r\n"
        "Content-Type: " + response.content_type + "\r\n"
        "Content-Length: " + std::to_string(content.size()) + "\r\n"
        "\r\n"
        + content;
    return response;
}

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

    while (true) {
        std::cout << "Waiting for a connection...\n";
        int client_fd = accept(server_fd, nullptr, nullptr);
        std::cout << "Accepted client FD: " << client_fd << std::endl;

        char recv_buf[2048];
        int bytes_read = recv(client_fd, recv_buf, sizeof(recv_buf) - 1, 0);
        std::string raw_request(recv_buf, bytes_read);

        HttpRequest request = parse_request(raw_request);
        HttpResponse response = build_response(request.path);

        send(client_fd, response.body.c_str(), response.body.size(), 0);
        close(client_fd);
    }

    return 0;
}
