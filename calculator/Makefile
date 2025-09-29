.PHONY: all debug release clean

all: debug release

debug: area-dbg
area-dbg: area.cpp
	g++ -g -O0 area.cpp -o area-dbg -Wall -Wextra -pedantic

release: area
area: area.cpp
	g++ -O2 area.cpp -o area -DNDEBUG -Wall -Wextra -pedantic

clean:
	rm -f area area-dbg

