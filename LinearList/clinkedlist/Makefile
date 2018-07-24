all:main.o CLinkList.o
	gcc main.o CLinkList.o -o all
main.o:main.c
	gcc -c main.c -o main.o
CLinkList.o:CLinkList.c
	gcc -c CLinkList.c -o CLinkList.o

clean:
	rm -rf *.o all