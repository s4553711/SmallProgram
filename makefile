CC = g++
LIBS = -lm
OBJS = src/main.o src/pdb.o
EXE = main

all: ${OBJS}
	${CC} -g -o ${EXE} ${LIBS} ${OBJS}

*.o: *.cpp
	${CC} $< -c

clean:
	rm -rf ${EXE} ${OBJS}
