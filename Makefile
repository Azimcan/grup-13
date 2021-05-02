CC = gcc

CFLAGS = -Wall -I./include -L./lib

SRCDIR = src
OBJDIR = obj

SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

TESTS = $(wildcard test/*.c)
TOBJS = $(TESTS:%.c=%)

# .PHONY = all clean lib

all: test1

lib/libtests.a: $(OBJS)
	@mkdir -p lib
	ar rcs lib/libtests.a $^
	ranlib lib/libtests.a

test1: test/test.c lib/libtests.a
	$(CC) $(CFLAGS) $< -o $@ -ltests

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	@rm -rf test1 lib $(OBJDIR)
