CC = g++
LIBS = -lm
OBJS = src/main.o
EXE = main

all: ${OBJS}
	${CC} -o ${EXE} ${LIBS} ${OBJS}

*.o: *.cpp
	${CC} $< -c

clean:
	rm -rf ${EXE} ${OBJS}
