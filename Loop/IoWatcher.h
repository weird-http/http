#ifndef WEIRD_IOWATCHER_H
#define WEIRD_IOWATCHER_H

#include <libev/ev++.h>
#include "./AbstractWatcher.h"

namespace Weird::Loop {
    class IoWatcher : public AbstractWatcher<ev::io>
    {
        public:
            IoWatcher(int fd, void (*cb)());

            void callback() override;

        private:
            void (*callbackPtr)();
    };
}

#endif //WEIRD_IOWATCHER_H
