link = ../liststack/ListStack.c
objects = main.o ExpValue.o ListStack.o
all:$(objects)
	gcc $(objects) -o all
main.o:main.c
	gcc -c -g main.c -o main.o
ExpValue.o:ExpValue.c
	gcc -c -g ExpValue.c -o ExpValue.o
ListStack.o:$(link)
	gcc -c -g $(link) -o ListStack.o

clean:
	rm -rf *.o all debug