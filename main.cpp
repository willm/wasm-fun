#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#include <emscripten/bind.h>
#include <stdio.h>
#include <stdlib.h>
#else
#define EMSCRIPTEN_KEEPALIVE
#define EMSCRIPTEN_BINDING
#endif
#include <thread>
#include <chrono>
#include <iostream>

extern "C" {
    EMSCRIPTEN_KEEPALIVE int add3(int i);
    EMSCRIPTEN_KEEPALIVE void callMeBack(int callbackPointer);
    EMSCRIPTEN_KEEPALIVE void startAThread();
}

int add3(int i) {
    return i + 3;
}

void callMeBack(int callbackPointer) {
    void (*callback)(int) = reinterpret_cast<void (*)(int)>(callbackPointer);
    callback(2);
    EM_ASM_(Module.removeFunction($0), callback);
}

void startAThread() {
    int arg = 8;
    puts("Starting a thread");
    std::thread thread([&]() {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        // output int shared with main thread
        std::cout << "Inside the thread: " << arg << std::endl;
    });

    thread.detach();
    std::cout << "Main thread exiting" << std::endl;
}

class Shape {
    private:
        std::string _name;
    public:
        Shape(std::string name) {
            _name = name;
        }
        std::string getName() {
            return _name;
        }
};
// Binding code
EMSCRIPTEN_BINDINGS(shape_example) {
    emscripten::class_<Shape>("Shape")
    .constructor<std::string>()
    .function("getName", &Shape::getName);
}
