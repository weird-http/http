#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <Types.h>
#include <Exception/RuntimeException.h>
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
//    int sockfd;
//    int newsockfd;
//    int port;
//    char buffer[256];
//
//    sockaddr_in serv_addr;
//    sockaddr_in cli_addr;
//    int n;
//
//    if (argc < 2) {
//        error("ERROR, no port provided\n");
//        exit(1);
//    }
//
//    sockfd = socket(AF_INET, SOCK_STREAM, 0);
//    if (sockfd < 0) {
//        error("ERROR opening socket");
//    }
//
//    bzero((char *) &serv_addr, sizeof(serv_addr));
//    port = atoi(argv[1]);
//
//    serv_addr.sin_family = AF_INET;
//    serv_addr.sin_addr.s_addr = INADDR_ANY;
//    serv_addr.sin_port = htons(port);
//
//    if (bind(sockfd, (sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
//        error("ERROR on binding");
//    }
//
//    listen(sockfd, 5);
//    socklen_t clilen = sizeof(cli_addr);
//    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
//    if (newsockfd < 0) {
//        error("ERROR on accept");
//    }
//
//    bzero(buffer,256);
//    n = read(newsockfd, buffer, 255);
//
//    if (n < 0) {
//        error("ERROR reading from socket");
//    }
//
//    printf("Here is the message: %s\n", buffer);
//
//    n = write(newsockfd, "I got your message", 18);
//    if (n < 0) {
//        error("ERROR writing to socket");
//    }
    UnsignedInt16 x = 12345;

    try {
        throw Weird::Http::Exception::RuntimeException("message");
    } catch (Weird::Http::Exception::ExceptionInterface &e) {
        std::cout << e.getMessage();
    }

    std::cout << x;
    return 0;
}
