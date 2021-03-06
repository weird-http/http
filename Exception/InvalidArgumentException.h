#ifndef WEIRD_INVALID_ARGUMENT_EXCEPTION_H
#define WEIRD_INVALID_ARGUMENT_EXCEPTION_H

#include "Exception.h"

namespace Weird::Exception
{
    class InvalidArgumentException : public Exception
    {
        public:
            InvalidArgumentException(
                const std::string& expected,
                const std::string& got,
                const int code,
                const ExceptionInterface* innerException = NULL
            );
    };
}


#endif //WEIRD_INVALID_ARGUMENT_EXCEPTION_H
