# WASM fun

A few examples of how to use emscripten to glue javascript and c++ together.

## Requirements

* cmake
* emscripten

## Building

```
make generate
make build
```

## Running

### In the browser

1. Serve the directory `python3 -m http.server`
2. Go to http://localhost:8000 in your browser

### In node

```
node index.js
```
