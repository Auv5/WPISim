all:
	mkdir -p bin lib
	g++ -std=c++11 -Iinclude -c src/*.cpp -Wl,--no-as-needed
	ar rcs lib/libwpisim.a *.o
	g++ -std=c++11 -Iinclude -o bin/example examples/*.cpp -Llib -lwpisim -pthread -Wl,--no-as-needed
	rm *.o
