CC = g++
LIBS = -lm
OBJS = linklist.o main.o
EXE = main
.SUFFIXS: .cpp

all: ${OBJS}
	${CC} -g -o ${EXE} ${LIBS} ${OBJS}

*.o: *.cpp
	${CC} $< -c

clean:
	rm -rf ${EXE} ${OBJS}
