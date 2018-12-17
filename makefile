main.bin: main.o ambulanciaTrabalho.o
	gcc main.o ambulanciaTrabalho.o -o main.bin
main.o: main.c
	gcc -c main.c
ambulanciaTrabalho.o: ambulanciaTrabalho.c ambulanciaTrabalho.h
	gcc -c ambulanciaTrabalho.c
clean:
	rm *.o
