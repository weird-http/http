#include "RuntimeException.h"

using namespace Weird::Http::Exception;

RuntimeException::RuntimeException(const std::string& message, int code, const ExceptionInterface *innerException)
    : Exception(message, code, innerException)
{
}
