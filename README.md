# WASM fun

A few examples of how to use emscripten to glue javascript and c++ together.

## Requirements

* make
* cmake
* emscripten
* docker

## Building

```
make generate
make build
```

## Running

### In the browser

1. Serve the directory `make serve`
2. Go to http://localhost:8000 in your browser

### In node

```
node index.js
```
