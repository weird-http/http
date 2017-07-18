#include "InvalidArgumentException.h"

using namespace Weird::Http::Exception;

InvalidArgumentException::InvalidArgumentException(const std::string expected, const std::string got)
    : Exception("Expected" + expected + ". Got " + got)
{
}
