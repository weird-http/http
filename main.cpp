#include <iostream>
#include <unistd.h>
#include <Types.h>
#include <Exception/RuntimeException.h>
#include <Http/Socket/Socket.h>
#include <Http/Socket/SocketInterface.h>
#include <Loop/EventLoop.h>
#include <Loop/IdleWatcher.h>
#include <Loop/IoWatcher.h>

extern Weird::Loop::EventLoop& sEventLoop;

void error(const char *msg)
{
    std::cerr << msg;
    exit(1);
}

int main(int argc, char* argv[])
{
    Weird::Http::Socket::SocketInterface* socket = new Weird::Http::Socket::Socket("127.0.0.1", 8080);
    socket->doBind();
    Weird::Loop::IdleWatcher watcher;
    Weird::Loop::IoWatcher ioWatcher(STDIN_FILENO, []() {
        char buf[16256];
        memset(buf, 0, 16256);
        read(STDIN_FILENO, buf, 16255);

        std::cout << buf;
    });

    sEventLoop.getInstance().addWatcher(&watcher);
    sEventLoop.getInstance().addWatcher(&ioWatcher);
    sEventLoop.getInstance().run();

    return 0;
}
