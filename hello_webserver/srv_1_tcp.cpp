/*
    $ clang++ -std=c++20 -Wall -Wextra -O0 -g hello_webserver/srv_1_tcp.cpp -o build/srv_1_tcp && ./build/srv_1_tcp
    then, in another terminal:
    $ nc localhost 9090
    then: type anything and hit enter.
*/

#include <iostream>      // console I/O
#include <sys/socket.h>  // socket(), bind(), listen(), accept(), send(), recv()
#include <netinet/in.h>  // sockaddr_in
#include <unistd.h>      // close()
#include <string>


int main() {
    std::cout << "hello, sockets!\n";

    // Address the listening socket binds to:
    sockaddr_in server_addr{};                 // zero-initialize
    server_addr.sin_family = AF_INET;          // IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY;  // accept on any local interface
    server_addr.sin_port = htons(9090);        // host byte order -> network byte order

    // domain=IPv4, type=stream (TCP), protocol=0 (default for the type)
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    std::cout << "Server FD: " << server_fd << std::endl;

    // bind: attach the socket to a local address so clients can find it
    int bind_result = bind(
        server_fd,
        // bind() takes a generic sockaddr*, so cast our sockaddr_in
        reinterpret_cast<sockaddr*>(&server_addr),
        sizeof(server_addr)
    );
    std::cout << "bind() returned: " << bind_result << std::endl;

    int listen_result = listen(server_fd, 16);
    std::cout << "listen() returned: " << listen_result << std::endl;

    // while (true) {  // hold off on looping, one client at a time for now
    std::cout << "Waiting for a connection...\n";
    int client_fd = accept(server_fd, nullptr, nullptr);
    std::cout << "Accepted client FD: " << client_fd << std::endl;

    /*
       recv_buf
       ┌───┬───┬───┬───┬───┬───┬─── ... ───┐
       │   │   │   │   │   │   │           │
       └───┴───┴───┴───┴───┴───┴─── ... ───┘
        2048 bytes
    */
    char recv_buf[2048];  // fixed buffer for the incoming bytes
    int bytes_read = recv(client_fd, recv_buf, sizeof(recv_buf) - 1, 0);
    std::string received(recv_buf, bytes_read);  // received(...) constructs a std::string from a raw char buffer + length
    std::cout << "Received: " << received << std::endl;

    std::string reply = "Hey there! You said: " + received + "\n";
    int bytes_written = send(client_fd, reply.c_str(), reply.size(), 0);
    std::cout << "Sent bytes: " << bytes_written << std::endl;

    int close_result = close(client_fd);
    std::cout << "close() returned: " << close_result << std::endl;

    return 0;
}
