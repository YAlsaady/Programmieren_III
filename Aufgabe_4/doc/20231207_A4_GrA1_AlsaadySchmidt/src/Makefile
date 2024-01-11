CXX = g++
CFLAGS = -Wall -Wextra -pedantic 
SRC1 = $(wildcard *.cc)
SRC2 = $(wildcard *.cpp)
OBJ1 = $(patsubst %.cc, build/%.o, $(SRC1))
OBJ2 = $(patsubst %.cpp, build/%.o, $(SRC2))

build/main: $(OBJ1) $(OBJ2)
	$(CXX) $(CFLAGS) $(OBJ1) $(OBJ2) -o $@

build/%.o: %.cc
	@mkdir -p build
	${CXX} ${CFLAGS} -c $< -o $@

build/%.o: %.cpp
	@mkdir -p build
	${CXX} ${CFLAGS} -c $< -o $@

all: clean build/main 

clean:
	rm -rf build

run:
	./build/main 
