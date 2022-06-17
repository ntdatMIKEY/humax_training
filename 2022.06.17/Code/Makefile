CC = gcc
CFLAGS = -c -Wall

all: test4

test4.o: 
	$(CC) $(CFLAGS) test4.c -o test4.o
test4: test4.o
	$(CC) test4.o -o test4

clean:
	rm -rf test4
