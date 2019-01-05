
CC=gcc
CFLAGS=-Wall -fPIC -O3  
LDFLAGS=  
LIBS= 

all:	carsim


car.o: car.c 
	$(CC) $(CFLAGS) $(DEFINE_ST) -I . -c car.c

main.o: main.c car.h
	$(CC) $(CFLAGS) $(DEFINE_ST) -I . -c main.c


carsim:	car.o main.o
	$(CC) $(LDFLAGS) -o carsim car.o main.o  $(LIBS)

clean:	
	rm -f carsim car.o main.o

