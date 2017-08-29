#ifndef WEIRD_NULL_POINTER_EXCEPTION_H
#define WEIRD_NULL_POINTER_EXCEPTION_H

#include "Exception.h"

namespace Weird::Exception
{
    class NullPointerException : public Exception
    {
        public:
            NullPointerException(
                const std::string& message,
                const int code,
                const ExceptionInterface* innerException = NULL
            );
    };
}


#endif //WEIRD_NULL_POINTER_EXCEPTION_H
