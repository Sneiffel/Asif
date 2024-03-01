CC=gcc
INC=include/ 
BIN=bin/main
SRC=asifar/main.c

build:
	$(CC) -Wall $(SRC) -I$(INC) -o $(BIN)

run:
	./$(BIN)

clean:
	rm $(BIN)
