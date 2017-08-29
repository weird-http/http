#ifndef WEIRD_EXCEPTION_INTERFACE_H
#define WEIRD_EXCEPTION_INTERFACE_H

#include <string>

namespace Weird::Exception
{
    class ExceptionInterface
    {
        public:
            virtual const std::string getMessage() const = 0;
    };
}

#endif //WEIRD_EXCEPTION_INTERFACE_H
