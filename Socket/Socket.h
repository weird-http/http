#ifndef WEIRD_SOCKET_H
#define WEIRD_SOCKET_H

#include <cstdint>
#include "SocketInterface.h"
#include <Types.h>

namespace Weird::Http::Socket {
    class Socket : public SocketInterface
    {
        protected:
            UnsignedInt16 port;

        public:
            Socket(UnsignedInt16 port);

    protected:
        void bind() override;
    };
}

#endif //WEIRD_SOCKET_H
