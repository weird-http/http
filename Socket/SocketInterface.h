#ifndef WEIRD_SOCKET_INTERFACE_H
#define WEIRD_SOCKET_INTERFACE_H

namespace Weird::Http::Socket
{
    class SocketInterface
    {
        protected:
            virtual void bind() = 0;
    };
}

#endif //WEIRD_SOCKET_INTERFACE_H
