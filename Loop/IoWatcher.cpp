#include "IoWatcher.h"

using namespace Weird::Loop;

IoWatcher::IoWatcher(int fd, void (*cb)())
    : callbackPtr(cb)
{
    this->watcher.start(fd, ev::READ);
}

void IoWatcher::callback()
{
    this->callbackPtr();
}
