BINARIES=makeBox
CXX=g++

CCFLAGS=-Wall -std=c++11

all:	${BINARIES}

makeBox: makeBox.cpp
	${CXX} -o $@ $^ ${CCFLAGS}

clean:
	/bin/rm -rf *.o ${BINARIES}
