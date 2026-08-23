/*
    $ clang++ -std=c++20 -Wall -Wextra -O0 -g hello_webserver/srv_5_files.cpp -o /tmp/srv_5_files && /tmp/srv_5_files
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

// TODO: std::unordered_map<std::string, std::string> for route table?


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
    // std::cout << "Received: " << raw_request << std::endl;

    // Parse the request line
    std::istringstream stream(raw_request);  // e.g. "GET /ping HTTP/1.1"
    HttpRequest request;
    stream >> request.method;
    stream >> request.path;
    stream >> request.http_version;

    // Route the request
    int status_code = 200;
    std::string status_name = "OK";
    if (request.path == "/") {
        request.path = "/index.html";
    }
    std::string filename = "hello_webserver/static" + request.path;
    std::cout << "Reading file path: " + filename << std::endl;

    // Check existence
    if (!std::filesystem::exists(filename)) {
        status_code = 404;
        status_name = "NOT FOUND";
        filename = "hello_webserver/static/404.html";
    }

    // Guess the content type
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

    // Read the file for the response body
    std::cout << "Reading content from file: " << filename << std::endl;
    std::ifstream file_stream(filename);  // ifstream = an input file stream, opens a file for reading
    // istreambuf_iterator walks raw characters out of a stream buffer
    // body(begin, end)
    std::string body(
        (std::istreambuf_iterator<char>(file_stream)),
        std::istreambuf_iterator<char>()
    );

    // Wrap it in an HTTP response
    std::string response =
        "HTTP/1.1 " + std::to_string(status_code) + " " + status_name + " \r\n"
        "Content-Type: " + content_type + "\r\n"
        "Content-Length: " + std::to_string(body.size()) + "\r\n"
        "\r\n" + body;
    send(client_fd, response.c_str(), response.size(), 0);
    // std::cout << "Sent bytes: " << bytes_written << std::endl;

    close(client_fd);
    close(server_fd);

    return 0;
}
