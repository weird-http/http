#ifndef WEIRD_RUNTIME_EXCEPTION_H
#define WEIRD_RUNTIME_EXCEPTION_H

#include <string>
#include "Exception.h"

namespace Weird::Exception
{
    class RuntimeException : public Exception
    {
        public:
            RuntimeException(
                const std::string& message,
                const int code,
                const ExceptionInterface* innerException = NULL
            );
    };
}


#endif //WEIRD_RUNTIME_EXCEPTION_H
