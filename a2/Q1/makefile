main: main.c gendata.o linsolve.o checkresult.o
	gcc -o linsolve main.c gendata.o linsolve.o checkresult.o

gendata.o: gendata.c
	gcc -c gendata.c

linsolve.o: linsolve.c
	gcc -c linsolve.c

checkresult.o: checkresult.c
	gcc -c checkresult.c

