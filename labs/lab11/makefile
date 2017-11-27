CC = gcc
CFLAGS = -Wall -g -std=c99
LIBS = 

BIN = ./bin/
SRC = ./src/

SRC_FILES = $(wildcard ./src/*.c)
TEST_FILES = $(wildcard ./tests/*.c)

program:
	$(CC) $(CFLAGS) $(SRC_FILES) -Iinclude -L./lib $(LIBS) -o $(BIN)program_new

testing:
	$(CC) $(CFLAGS) $(TEST_FILES) ./src/heap.c -Iinclude -L./lib $(LIBS) -o $(BIN)testProgram_new

show:
	@echo $(SRC_FILES)

showTest:
	@echo $(TEST_FILES)

cls:
	clear

clean:
	rm ./bin/*

