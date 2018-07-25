all:main.o sqstack.o
	gcc main.o sqstack.o -o all
main.o:main.c
	gcc -c main.c -o main.o
sqstack.o:SqStack.c
	gcc -c SqStack.c -o sqstack.o
clean:
	rm -rf *.o all


