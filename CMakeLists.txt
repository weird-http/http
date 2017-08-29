cmake_minimum_required(VERSION 3.7)
project(weird C CXX)

set(CMAKE_CXX_STANDARD 14)
include_directories(AFTER SYSTEM ${PROJECT_SOURCE_DIR})

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

add_custom_target(
    lib_libev
    COMMAND test -f ${LIBRARY_OUTPUT_PATH}/lib/libev.a || (./configure --prefix=${LIBRARY_OUTPUT_PATH} --enable-shared=no && make install)
    WORKING_DIRECTORY ../libev
)

set(SOURCE_FILES main.cpp Socket/Socket.cpp Socket/SocketInterface.cpp Exception/ExceptionInterface.cpp Exception/Exception.cpp Exception/InvalidArgumentException.cpp Exception/RuntimeException.cpp Loop/EventLoop.cpp Loop/IdleWatcher.cpp Loop/IoWatcher.cpp)
add_executable(weird ${SOURCE_FILES})
target_link_libraries(weird ${LIBRARY_OUTPUT_PATH}/lib/libev.a)
add_dependencies(weird lib_libev)
