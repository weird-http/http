#ifndef WEIRD_EXCEPTION_INTERFACE_H
#define WEIRD_EXCEPTION_INTERFACE_H

#include <string>

namespace Weird::Http::Exception
{
    class ExceptionInterface : public std::exception
    {
        public:
            virtual const std::string getMessage() const = 0;
    };
}

#endif //WEIRD_EXCEPTION_INTERFACE_H
