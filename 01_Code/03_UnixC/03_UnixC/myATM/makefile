all:server open client
server:server.c bank.c
	gcc server.c bank.c -o server
open:open.c bank.c dao.c
	gcc open.c bank.c dao.c -o open
client:client.c bank.c
	gcc client.c bank.c -o client
clean:
	rm server open client save
