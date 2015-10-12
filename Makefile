CC=gcc
CFLAGS=-W -Wall -ansi
CFILES = hamming.c matrix.c
EXEC=hamming

all: $(EXEC)

hamming: hamming.o matrix.o
	$(CC) $(CFLAGS) -o $(EXEC) hamming.o matrix.o

hamming.o : hamming.c matrix.h
	$(CC) -c hamming.c

matrix.o: matrix.c matrix.h
	$(CC) -c matrix.c

clean:
	rm $(EXEC) *.o *~
