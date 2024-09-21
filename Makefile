CC = gcc
CFLAGS = -Wall

all: gpm

gpm: src/gpm.c src/install.c src/list.c src/remove.c
	$(CC) $(CFLAGS) -o gpm src/gpm.c src/install.c src/list.c src/remove.c

clean:
	rm -f gpm