Module.onRuntimeInitialized = () => {
  var newFuncPtr = Module.addFunction(function(num) {
    console.log('wooop');
    Module.print('Hello ' + num + ' from JS!');
  }, 'vi');
  Module._callMeBack(newFuncPtr);

  console.log(Module._add3(5));
};
