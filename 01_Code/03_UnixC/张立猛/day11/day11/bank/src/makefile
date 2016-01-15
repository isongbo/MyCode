CC = gcc
RM = rm
CFLAGS = -c -Wall
all: client server open query
client: client.o
	$(CC) $^ -o ../bin/$@
client.o: client.c	
	$(CC) $(CFLAGS) $^
server: server.o
	$(CC) $^ -o ../bin/$@
server.o: server.c
	$(CC) $(CFLAGS) $^
open: open.o dao.o
	$(CC) $^ -o ../bin/$@
open.o: open.c
	$(CC) $(CFLAGS) $^
query: query.o dao.o
	$(CC) $^ -o ../bin/$@
query.o: query.c
	$(CC) $(CFLAGS) $^
dao.o: dao.c
	$(CC) $(CFLAGS) $^
clean:
	$(RM) *.o \
	../bin/client \
	../bin/server \
	../bin/open
