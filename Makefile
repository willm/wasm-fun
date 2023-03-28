generate:
	mkdir -p cmake-build
	cd cmake-build && emcmake cmake ..

build:
	cd cmake-build && emmake make

clean:
	rm -rf cmake-build/*