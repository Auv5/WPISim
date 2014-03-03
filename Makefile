build/bin/example: cmake
	cd build && make

cmake:
	mkdir -p build
	cd build && cmake ../

clean:
	rm -rf build
