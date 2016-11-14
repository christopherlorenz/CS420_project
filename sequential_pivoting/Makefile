CC = gcc

CFLAGS = 

SRC = lu.c lu_row.c

all: lu.exe lu_row.exe

lu.exe: lu.o
	$(CC) $(CFLAGS) -o lu.exe lu.o

lu.o: lu.c
	$(CC) $(CFLAGS) -c lu.c

lu_row.exe: lu_row.o
	$(CC) $(CFLAGS) -o lu_row.exe lu_row.o

lu_row.o: lu_row.c
	$(CC) $(CFLAGS) -c lu_row.c

clean:
	rm -f *.o *.exe
