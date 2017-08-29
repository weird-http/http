#ifndef WEIRD_CONSTANTS_H
#define WEIRD_CONSTANTS_H

#include <sys/socket.h>
#include <Types.h>

namespace Weird::Http::Socket {
    enum Constants {
        INTERNET_PROTOCOL = IPPROTO_TCP,
        IP_V4 = AF_INET,
        IP_V6 = AF_INET6,
        TRANSPORT_PROTOCOL_UDP = SOCK_DGRAM,
        TRANSPORT_PROTOCOL_TCP = SOCK_STREAM,
        CURRENT_SOCKET = SOL_SOCKET,
        REUSE_ADDRESS = SO_REUSEADDR,
        REUSE_ADDRESS_PORT = SO_REUSEPORT,
        ANY_ADDRESS = INADDR_ANY,
    };
}

#endif //WEIRD_CONSTANTS_H
