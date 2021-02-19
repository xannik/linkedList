CC = gcc
HEADERS = linkedListLib.h
help: 
	@echo make build to build source code
	@echo make clean to remove built executeable

build: linkedList.c linkedListLib.c $(HEADERS)
	$(CC) linkedList.c linkedListLib.c  -o $@

clean:
	rm build
