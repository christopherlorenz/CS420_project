CC = gcc

CFLAGS = 

SRC = lu.c lu_row.c lu_full.c

all: lu.exe lu_row.exe lu_full.exe

lu.exe: lu.o
	$(CC) $(CFLAGS) -o lu.exe lu.o

lu.o: lu.c
	$(CC) $(CFLAGS) -c lu.c

lu_row.exe: lu_row.o
	$(CC) $(CFLAGS) -o lu_row.exe lu_row.o

lu_row.o: lu_row.c
	$(CC) $(CFLAGS) -c lu_row.c

lu_full.exe: lu_full.o
	$(CC) $(CFLAGS) -o lu_full.exe lu_full.o

lu_full.o: lu_full.c
	$(CC) $(CFLAGS) -c lu_full.c

clean:
	rm -f *.o *.exe
