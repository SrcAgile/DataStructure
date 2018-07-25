all:main.o liststack.o
	gcc main.o liststack.o -o all
main.o:main.c
	gcc -c main.c -o main.o
liststack.o:ListStack.c
	gcc -c ListStack.c -o liststack.o
clean:
	rm -rf *.o all
