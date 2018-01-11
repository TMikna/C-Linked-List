All: func.o main.o
	gcc -o list func.o main.o
hed.o: hed.c
	gcc -c func.c -o hed.o
main.o: main.c
	gcc -c main.c -o main.o
clean:
	rm *.o
