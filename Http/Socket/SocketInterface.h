#ifndef WEIRD_SOCKET_INTERFACE_H
#define WEIRD_SOCKET_INTERFACE_H

#include <Types.h>

namespace Weird::Http::Socket
{
    class SocketInterface
    {
        public:
            virtual void doBind() = 0;
    };
}

#endif //WEIRD_SOCKET_INTERFACE_H
