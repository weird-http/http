cmake_minimum_required(VERSION 3.7)
project(weird C CXX)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

add_custom_target(
    lib_libev
    COMMAND test -f ${LIBRARY_OUTPUT_PATH}/lib/libev.a || (./configure --prefix=${LIBRARY_OUTPUT_PATH} --enable-shared=no && make install)
    WORKING_DIRECTORY ../libev
)

add_executable(weird ${SOURCE_FILES})
target_link_libraries(weird ${LIBRARY_OUTPUT_PATH}/lib/libev.a)
add_dependencies(weird lib_libev)
