#ifndef WEIRD_ABSTRACTWATCHER_H
#define WEIRD_ABSTRACTWATCHER_H

namespace Weird::Loop {
    template <typename T>
    class AbstractWatcher
    {
        friend class EventLoop;

        public:
            AbstractWatcher()
            {
                watcher.template set<AbstractWatcher<T>, &AbstractWatcher<T>::internalCallback> (this);
            }

            virtual ~AbstractWatcher()
            {
            }

            /**
             * Callback invoked by the event loop when a watcher is signalled
             * for events pending.
             */
            virtual void callback() = 0;

        protected:
            T watcher;

        private:
            /**
             * Internal callback for event watcher.
             *
             * @param watcher Watcher pointer
             * @param revents
             *
             * @return
             */
            void internalCallback(T& watcher, int revents)
            {
                this->callback();
            }
    };
}


#endif //WEIRD_ABSTRACTWATCHER_H
