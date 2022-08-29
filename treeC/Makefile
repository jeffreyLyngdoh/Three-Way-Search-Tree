
CC=gcc

CFLAGS = -ansi -pedantic-errors -Wall -fstack-protector-all -Werror -g

all: driver.x

driver.x: TWST.o driver.o
	$(CC) TWST.o driver.o -o driver.x

TWST.o: TWST.c TWST.h nodeStructure.h
	$(CC) $(CFLAGS) -c TWST.c

driver.o: driver.c TWST.c TWST.h nodeStructure.h
	$(CC) $(CFLAGS) -c driver.c

clean:
	rm *.o *.x

run:
	./driver.x

val:
	valgrind --leak-check=yes ./driver.x
