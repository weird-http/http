#include "EventLoop.h"

using namespace Weird::Loop;

template <> EventLoop * Weird::Singleton<EventLoop>::instance = nullptr;
EventLoop sEventLoop(ev::default_loop);

EventLoop::EventLoop(ev::loop_ref& loop)
    : loop(loop)
{
}

void EventLoop::run()
{
    ev::get_default_loop().loop();
}
