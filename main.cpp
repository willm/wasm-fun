#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#include <stdio.h>
#include <stdlib.h>
#else
#define EMSCRIPTEN_KEEPALIVE
#endif

extern "C" {
    EMSCRIPTEN_KEEPALIVE int add3(int i);
    EMSCRIPTEN_KEEPALIVE void callMeBack(int callbackPointer);
}

int add3(int i) {
    return i + 3;
}

void callMeBack(int callbackPointer) {
    void (*callback)(int) = reinterpret_cast<void (*)(int)>(callbackPointer);
    callback(2);
    EM_ASM_(Module.removeFunction($0), callback);
}
