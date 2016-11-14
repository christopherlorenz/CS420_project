CC = gcc

CFLAGS = 

SRC = lu.c

all: lu.exe

lu.exe: lu.o
	$(CC) $(CFLAGS) -o lu.exe lu.o

lu.o: lu.c
	$(CC) $(CFLAGS) -c lu.c

clean:
	rm -f *.o *.exe
