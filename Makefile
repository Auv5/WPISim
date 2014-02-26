all:
	mkdir -p bin lib
	g++ -std=c++11 -Iinclude -c src/*.cpp -Wl,--no-as-needed
	ar rcs lib/libwpisim.a Main.o SimpleRobot.o
	g++ -std=c++11 -Iinclude -o bin/example examples/ExampleBot.cpp -Llib -lwpisim -pthread -Wl,--no-as-needed
	rm Main.o SimpleRobot.o
