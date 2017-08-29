#ifndef WEIRD_EVENTLOOP_H
#define WEIRD_EVENTLOOP_H

#include "../Singleton.h"
#include "./AbstractWatcher.h"
#include <libev/ev++.h>

namespace Weird::Loop {
    class EventLoop : public Weird::Singleton<EventLoop>
    {
        public:
            explicit EventLoop(ev::loop_ref& loop);

            template <typename T>
            void addWatcher(AbstractWatcher<T>* watcher)
            {
                watcher->watcher.start();
            }

            void run();

        private:
            ev::loop_ref & loop;
    };
}

#endif //WEIRD_EVENTLOOP_H
