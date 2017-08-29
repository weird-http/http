#include "NullPointerException.h"

using namespace Weird::Exception;

NullPointerException::NullPointerException(
    const std::string& message,
    const int code,
    const ExceptionInterface* innerException
) : Exception("" == message ? "Object reference not set to an instance of an object." : message, code, innerException)
{
}