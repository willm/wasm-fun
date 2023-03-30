const mod = require('./cmake-build/wasmfun');
mod.onRuntimeInitialized = () => {
  console.log(mod._add3(10));

  const newFuncPtr = mod.addFunction(function (num) {
    console.log('wooop');
    //Module.print('Hello ' + num + ' from JS!');
  }, 'vi');
  mod._callMeBack(newFuncPtr);

  mod._startAThread();

  const shape = new mod.Shape('square');
  console.log(shape.getName());
  shape.delete();
}
