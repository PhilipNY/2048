CC=gcc
TITLE = triangle
GTEST_DIR = ../gtest
CFLAGS=-std=c11 -I include -I $(GTEST_DIR)/include
LDFLAGS=-lm
OBJS=obj/2048.o obj/main.o obj/share.o
DEPS=include/2048.h include/share.h
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
		$(GTEST_DIR)/include/gtest/internal/*.h
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h \
		$(GTEST_HEADERS)
GTEST_LIBS = $(GTEST_DIR)/lib/*.a

all: bin/main bin/$(TITLE)_unittest

$(GTEST_DIR)/obj/gtest-all.o : $(GTEST_SRCS_)
	$(CC) $(CFLAGS) -I$(GTEST_DIR) -c \
            $(GTEST_DIR)/src/gtest-all.cc -o $@

$(GTEST_DIR)/obj/gtest_main.o : $(GTEST_SRCS_)
	$(CC) $(CFLAGS) -I$(GTEST_DIR) -c \
            $(GTEST_DIR)/src/gtest_main.cc -o $@

$(GTEST_DIR)/lib/gtest.a : $(GTEST_DIR)/obj/gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

$(GTEST_DIR)/lib/gtest_main.a : $(GTEST_DIR)/obj/gtest-all.o $(GTEST_DIR)/obj/gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

obj/%.o: src/%.c ${DEPS}
	${CC} -c ${CFLAGS} -o $@ $<

bin/main: ${OBJS}
	${CC} ${CFLAGS} -o $@ $^ ${LDFLAGS}

bin/$(TITLE)_unittest : obj/$(TITLE).o obj/$(TITLE)_unittest.o \
			$(GTEST_DIR)/lib/gtest_main.a
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $^ -o $@

run: bin/main
	bin/main

clean:
	rm -rf $(GTEST_DIR)/obj/*.o
	rm -rf $(GTEST_LIBS)
	rm -f obj/*.o
	rm -f bin/main
	rm -rf bin/$(TITLE)_unittest
	
