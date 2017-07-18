#include <iostream>
#include "Exception.h"

using namespace Weird::Http::Exception;

Exception::Exception(
    const std::string& message,
    const int code,
    const ExceptionInterface* innerException
) : code(code), message(message) {
    this->innerException = innerException;
}

const std::string Exception::getMessage() const
{
    return this->message;
}
