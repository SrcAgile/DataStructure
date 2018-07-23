all:main.o SqList.o
	gcc main.o SqList.o -o all
main.o:main.c
	gcc -c main.c -o main.o
SqList.o:SqList.c
	gcc -c SqList.c -o SqList.o

clean:
	rm -rf *.o all