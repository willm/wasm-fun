cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(wasmfun)

add_definitions(-std=c++17)
set (CMAKE_CXX_STANDARD 17)

if (DEFINED EMSCRIPTEN)
    add_executable(wasmfun main.cpp)
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
    set_target_properties(wasmfun PROPERTIES COMPILE_FLAGS "-Os ")
    set(EMCC_ARGS
        -O3 -s ALLOW_MEMORY_GROWTH=1 -s ALLOW_TABLE_GROWTH=1 -s EXTRA_EXPORTED_RUNTIME_METHODS='[addFunction]' -s EXPORTED_RUNTIME_METHODS='[cwrap,addFunction]' -s MODULARIZE=1 -s NO_EXIT_RUNTIME=1 -s NO_FILESYSTEM=1)
    set_target_properties(wasmfun PROPERTIES LINK_FLAGS    "-O1 -s ALLOW_MEMORY_GROWTH=1 -s INVOKE_RUN=0 -s ALLOW_TABLE_GROWTH=1 -s EXPORTED_RUNTIME_METHODS='[cwrap,addFunction,removeFunction]' -s RESERVED_FUNCTION_POINTERS=1 -o index.html --minify 0 --post-js ../post.js")
else()
    add_library(wasmfun SHARED main.cpp)
endif()
