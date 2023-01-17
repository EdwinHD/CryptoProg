.PHONY: all debug release clean

all: debug release

debug: hash-dbg

hash-dbg: main.cpp
	g++ -g -O0 main.cpp -o hash-dbg -Wall -lcrypto++

release: main

main: main.cpp
	g++ -O2 main.cpp -o main -DNDEBUG -Wall -lcrypto++

clean:
	rm -f main hash-dbg
