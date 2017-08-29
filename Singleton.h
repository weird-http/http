#ifndef WEIRD_SINGLETON_H
#define WEIRD_SINGLETON_H

#include <assert.h>

namespace Weird {

    /**
     * Singleton utility class.
     *
     * @tparam T Any class
     */
    template<typename T>
    class Singleton
    {
        public:
            Singleton()
            {
                assert(nullptr == instance);
                instance = static_cast<T*>(this);
            }

            virtual ~Singleton()
            {
                instance = nullptr;
            }

            /**
             * Returns the singleton instance.
             *
             * @return The singleton instance, if any.
             */
            inline static T& getInstance()
            {
                return *instance;
            }

            /**
             * Returns a pointer to the singleton instance.
             *
             * @return A pointer to the singleton instance.
             */
            inline static T* getInstancePtr()
            {
                return instance;
            }

        protected:
            static T* instance;
    };
};

#endif //WEIRD_SINGLETON_H
