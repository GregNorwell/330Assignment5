CXXFLAGS+=-std=c++11 -Wall -Wextra -Werror -pedantic -I.

all: dog

dog: main.cc functions.cc header.h
	g++ $(CXXFLAGS) -o dog main.cc functions.cc

clean:
	rm -f dog
	
world: clean all
