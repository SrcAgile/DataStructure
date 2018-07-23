all:main.o DLinkList.o
	gcc main.o DLinkList.o -o all
main.o:main.c
	gcc -c main.c -o main.o
LinkList.o:DLinkList.c
	gcc -c DLinkList.c -o DLinkList.o

clean:
	rm -rf *.o all