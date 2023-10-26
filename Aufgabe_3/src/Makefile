CXX = g++
CFLAGS = -Wall -Wextra -pedantic 
SRC = $(wildcard *.cc)
# SRC =	$(wildcard *.cpp *.cc)
OBJ = $(patsubst %.cc, build/%.o, $(SRC))
# OBJ =	$(patsubst %.cpp *.cc, build/%.o, ${SRC})

build/main: $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $@

build/%.o: %.cc
# build/%.o: %.cpp %.cc
	@mkdir -p build
	${CXX} ${CFLAGS} -c $< -o $@
all: clean build/main 

clean:
	rm -rf build
