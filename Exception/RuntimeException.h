#ifndef WEIRD_RUNTIME_EXCEPTION_H
#define WEIRD_RUNTIME_EXCEPTION_H

#include <string>
#include "Exception.h"

namespace Weird::Http::Exception
{
    class RuntimeException : public Exception
    {
        public:
            RuntimeException(const std::string& message, int code = -1, const ExceptionInterface *innerException = NULL);
    };
}


#endif //WEIRD_RUNTIME_EXCEPTION_H
