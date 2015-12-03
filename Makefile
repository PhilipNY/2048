CC=gcc
CFLAGS=-std=c11 -I include 
LDFLAGS=-lm
OBJS=obj/2048.o obj/main.o obj/share.o
DEPS=include/2048.h include/share.h

all: bin/main

obj/%.o: src/%.c ${DEPS}
	${CC} -c ${CFLAGS} -o $@ $<

bin/main: ${OBJS}
	${CC} ${CFLAGS} -o $@ $^ ${LDFLAGS}

run: bin/main
	bin/main

clean:
	rm -f bin/main
	rm -f obj/*.o
	
