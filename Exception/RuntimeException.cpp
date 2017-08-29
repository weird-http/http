#include "RuntimeException.h"

using namespace Weird::Exception;

RuntimeException::RuntimeException(
    const std::string& message,
    const int code,
    const ExceptionInterface* innerException
) : Exception(message, code, innerException)
{
}
