all:main.o LinkList.o
	gcc main.o LinkList.o -o all
main.o:main.c
	gcc -c main.c -o main.o
LinkList.o:LinkList.c
	gcc -c LinkList.c -o LinkList.o

clean:
	rm -rf *.o all