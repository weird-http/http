#include <iostream>
#include "Exception.h"

using namespace Weird::Http::Exception;

Exception::Exception(
    const std::string message,
    const int code,
    const ExceptionInterface* innerException
) {
    std::cerr << message;

    if (NULL != innerException) {
        std::cerr << " (inner exception message: " << innerException->getMessage() << ")";
    }
}

const std::string Exception::getMessage() const
{
    return this->what();
}