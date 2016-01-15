queue:queue.o list.o main.o
	cc queue.o list.o main.o -o queue
queue.o:queue.c
	cc -c queue.c
list.o:list.c
	cc -c list.c
main.o:main.c
	cc -c main.c
clean:
	rm *.o queue
