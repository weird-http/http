#include <netinet/in.h>
#include <Exception/RuntimeException.h>
#include "Socket.h"
#include "Constants.h"

using namespace Weird::Exception;
using namespace Weird::Http::Socket;

Socket::Socket(const std::string& hostName, const UnsignedInt16 port, const int option)
{
    this->hostName = hostName;
    this->port = port;
    this->option = option;
    this->socketFileDescriptor = socket(
        Constants::IP_V4,
        Constants::TRANSPORT_PROTOCOL_TCP,
        Constants::INTERNET_PROTOCOL
    );

    if (0 == this->socketFileDescriptor) {
        throw Exception::RuntimeException("Error while opening socket", -1);
    }

    int socketOptions = setsockopt(
        this->socketFileDescriptor,
        Constants::CURRENT_SOCKET,
        Constants::REUSE_ADDRESS_PORT,
        &this->option, sizeof(this->option)
    );

    if (0 != socketOptions) {
        throw Exception::RuntimeException("Could not set default socket options", -1);
    }

    this->address.sin_family = Constants::IP_V4;
    this->address.sin_addr.s_addr = Constants::ANY_ADDRESS;
    this->address.sin_port = this->port;
}

void Socket::doBind()
{
    if (bind(this->socketFileDescriptor, (SocketAddress*) &this->address, sizeof(this->address)) < 0) {
        throw Exception::RuntimeException("Could not bind socket to current address", -1);
    }

    //todo: implement these features!
//    listen(sockfd, 5);
//    socklen_t clilen = sizeof(cli_addr);
//    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
//    if (newsockfd < 0) {
//        error("ERROR on accept");
//    }
//
//    bzero(buffer,256);
//    n = read(newsockfd, buffer, 255);
//
//    if (n < 0) {
//        error("ERROR reading from socket");
//    }
//
//    printf("Here is the message: %s\n", buffer);
//
//    n = write(newsockfd, "I got your message", 18);
//    if (n < 0) {
//        error("ERROR writing to socket");
//    }
}
