#ifndef WEIRD_EXCEPTION_H
#define WEIRD_EXCEPTION_H

#include "ExceptionInterface.h"

namespace Weird::Exception
{
    class Exception : public ExceptionInterface
    {
        protected:
            const std::string message;
            const int code;
            const ExceptionInterface* innerException;

        public:
            Exception(
                const std::string& message,
                const int code = -1,
                const ExceptionInterface* innerException = NULL
            );

            const std::string getMessage() const override;
    };
}


#endif //WEIRD_EXCEPTION_H
