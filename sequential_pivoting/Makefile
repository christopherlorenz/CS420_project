CC = gcc

CFLAGS = 

SRC = lu.c

all: lu.exe

lu_fac.exe: lu.o
	$(CC) $(CFLAGS) -o lu.exe lu.o

lu_fac.o: lu_fac.c
	$(CC) $(CFLAGS) -c lu.c

clean:
	rm -f *.o *.exe


