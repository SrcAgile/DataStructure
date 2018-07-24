all:main.o CDLinkList.o
	gcc main.o CDLinkList.o -o all
main.o:main.c
	gcc -c main.c -o main.o
CDLinkList.o:CDLinkList.c
	gcc -c CDLinkList.c -o CDLinkList.o

clean:
	rm -rf *.o all