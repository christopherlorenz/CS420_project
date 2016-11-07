CC = gcc

CFLAGS = -std=c99

SRC = lu_fac.c

all: lu_fac.exe

lu_fac.exe: lu_fac.o
	$(CC) $(CFLAGS) -o lu_fac.exe lu_fac.o

lu_fac.o: lu_fac.c
	$(CC) $(CFLAGS) -c lu_fac.c

clean:
	rm -f *.o *.exe


