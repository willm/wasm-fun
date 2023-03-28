const mod = require('./cmake-build/wasmfun');
mod.onRuntimeInitialized = () => {
  const newFuncPtr = mod.addFunction(function (num) {
    console.log('wooop');
    //Module.print('Hello ' + num + ' from JS!');
  }, 'vi');
  mod._callMeBack(newFuncPtr);
}