# Derleyiciyi tutan degisken
CC = gcc

# Kutuphane parametrelerini tuttan degisken 
CFLAGS = -Wall -I./include -L./lib

# src dizinini tutar
SRCDIR = src

# Olusturulan objelerin dizinini tutar
OBJDIR = obj

# src dizinindeki tum .c uzantili dosyalarin konumlarini tutar
SRCS = $(wildcard $(SRCDIR)/*.c)
# Olusturulan objelerin konumlarini tutar
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Test dizininde yazilan testlerin konumlarini tutar
TESTS = $(wildcard test/*.c)

# 29. satiri make komutu esnasinda calistirir 
all:    test1

# Kutuphane dosyalarini olusturur 
lib/libtests.a: $(OBJS)
        @mkdir -p lib
        ar rcs lib/libtests.a $^
        ranlib lib/libtests.a

# test dizininde ki test.c dosyasini derler
test1: test/test.c lib/libtests.a
        $(CC) $(CFLAGS) $< -o $@ -ltests

# Objeleri olusturur
$(OBJDIR)/%.o: $(SRCDIR)/%.c
        @mkdir -p $(@D)
        $(CC) $(CFLAGS) $< -c -o $@

# Derlene esnasinda olusan dosyalari temizler
clean:
        @rm -rf test1 test1 lib $(OBJDIR)

