#ifndef WEIRD_TYPES_H
#define WEIRD_TYPES_H

#include <netinet/in.h>

typedef uint8_t UnsignedInt8;
typedef uint16_t UnsignedInt16;
typedef uint32_t UnsignedInt32;
typedef uint64_t UnsignedInt64;

typedef struct sockaddr SocketAddress;
typedef struct sockaddr_in SocketAddressIpV4;
typedef struct sockaddr_in6 SocketAddressIpV6;

#endif //WEIRD_TYPES_H
