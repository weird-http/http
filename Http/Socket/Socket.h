#ifndef WEIRD_SOCKET_H
#define WEIRD_SOCKET_H

#include <cstdint>
#include "SocketInterface.h"
#include <Types.h>
#include <string>

namespace Weird::Http::Socket {
    class Socket : public SocketInterface
    {
        protected:
            std::string hostName;
            UnsignedInt16 port;
            int socketFileDescriptor;
            int option;
            std::string internalBuffer;
            SocketAddressIpV4 address;

        public:
            Socket(const std::string& hostName, const UnsignedInt16 port, const int option = 1);

    public:
        void doBind() override;
    };
}

#endif //WEIRD_SOCKET_H
