#include "InvalidArgumentException.h"

using namespace Weird::Exception;

InvalidArgumentException::InvalidArgumentException(
    const std::string& expected,
    const std::string& got,
    const int code,
    const ExceptionInterface* innerException
) : Exception("Expected" + expected + ". Got " + got, code, innerException)
{
}
