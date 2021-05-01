CC = gcc

CFLAGS = -Wall -Werror -I. -L.

SRCS = $(wildcard *.c)

OBJS = $(SRCS:%.c=%.o)

TESTS = $(wildcard test/*.c)
TOBJS = $(TESTS:%.c=%)

all: $(TOBJS)

lib: $(OBJS)
	ar rcs libtests.a $^
	ranlib libtests.a

%: %.c lib
	$(CC) $(CFLAGS) $< -o $@ -ltests

%.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm *.o test/test libtests.a
