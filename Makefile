generate:
	mkdir -p cmake-build
	cd cmake-build && emcmake cmake ..

build:
	cd cmake-build && emmake make

clean:
	rm -rf cmake-build/*

serve:
	docker run -v $$(pwd)/nginx.conf:/etc/nginx/conf.d/default.conf \
		-v $$(pwd):/usr/share/nginx/html --rm -p 8000:80 --name wasm-fun nginx
