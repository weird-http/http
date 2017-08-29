#ifndef WEIRD_IDLEWATCHER_H
#define WEIRD_IDLEWATCHER_H

#include <libev/ev++.h>
#include "./AbstractWatcher.h"

namespace Weird::Loop {
    class IdleWatcher : public AbstractWatcher<ev::idle>
    {
        public:
            void callback() override;
    };
}

#endif //WEIRD_IDLEWATCHER_H
