// Lesson: Sockets - minimal TCP client (POSIX)
// Compile (Unix): g++ -o 0081_socket 0081_socket.cpp
// Run: ./0081_socket [host] [port]  (default: 127.0.0.1 80)
// Requires a server listening on the given port for a real connection.

#include <iostream>
#include <string>
#include <cstring>

#if defined(_WIN32) || defined(_WIN64)
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#endif

int main(int argc, char* argv[]) {
    const char* host = argc > 1 ? argv[1] : "127.0.0.1";
    int port = argc > 2 ? std::stoi(argv[2]) : 80;

#if defined(_WIN32) || defined(_WIN64)
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        std::cerr << "WSAStartup failed\n";
        return 1;
    }
#endif

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cerr << "socket() failed\n";
        return 1;
    }

    struct sockaddr_in server {};
    server.sin_family = AF_INET;
    server.sin_port = htons(static_cast<unsigned short>(port));
    if (inet_pton(AF_INET, host, &server.sin_addr) <= 0) {
        std::cerr << "Invalid address\n";
        return 1;
    }

    if (connect(sock, reinterpret_cast<struct sockaddr*>(&server), sizeof(server)) < 0) {
        std::cerr << "connect() failed (is a server listening on " << host << ":" << port << "?)\n";
#if defined(_WIN32) || defined(_WIN64)
        closesocket(sock);
        WSACleanup();
#else
        close(sock);
#endif
        return 1;
    }

    std::cout << "Connected to " << host << ":" << port << "\n";

#if defined(_WIN32) || defined(_WIN64)
    closesocket(sock);
    WSACleanup();
#else
    close(sock);
#endif
    return 0;
}
