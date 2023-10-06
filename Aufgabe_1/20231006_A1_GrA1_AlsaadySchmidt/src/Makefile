CXX = g++
CFLAGS = -Wall -Wextra
SRC = $(wildcard *.cc)
OBJ = $(patsubst %.cc, build/%.o, $(SRC))

build/main: $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $@

build/%.o: %.cc
	@mkdir -p build
	${CXX} ${CFLAGS} -c $< -o $@
all: clean build/main 

clean:
	rm -rf build
