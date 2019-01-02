CFLAGS = -Wall -O2

main: main.c gendata.o linsolve.o checkresult.o gettime.o
	gcc $(CFLAGS) -o linsolve main.c gendata.o linsolve.o checkresult.o gettime.o

gendata.o: gendata.c
	gcc $(CFLAGS) -c gendata.c

linsolve.o: linsolve.c
	gcc $(CFLAGS) -c linsolve.c

checkresult.o: checkresult.c
	gcc $(CFLAGS) -c checkresult.c

gettime.o: gettime.c
	gcc $(CFLAGS) -c gettime.c

clean:
	rm *.o program
