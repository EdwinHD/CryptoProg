.PHONY: all debug release clean

all: debug release

debug: cipher-dbg

cipher-dbg: main.cpp
	g++ -g -O0 main.cpp -o cipher-dbg -Wall -lcrypto++

release: main

main: main.cpp
	g++ -O2 main.cpp -o main -DNDEBUG -Wall -lcrypto++

clean:
	rm -f main cipher-dbg
