GCC = gcc
CFLAGS = -c -Wall -g
LFLAGS =
INC = ./../inc
SRC = ./../src
OBJ = ./../obj
BIN = ./../bin

all: $(BIN)/prog

$(BIN)/prog: $(OBJ)/main.o $(OBJ)/linked_list.o
	$(GCC) -Wall -g -o prog  $(OBJ)/main.o $(OBJ)/linked_list.o
	mv prog ./../bin/

$(OBJ)/main.o: $(SRC)/main.c $(INC)/linked_list.h
	$(GCC) $(CFLAGS) $(SRC)/main.c -I $(INC)/
	mv main.o $(OBJ)/

$(OBJ)/linked_list.o: $(SRC)/linked_list.c $(INC)/linked_list.h
	$(GCC) $(CFLAGS) $(SRC)/linked_list.c -I $(INC)/
	mv linked_list.o $(OBJ)/

clean:
	rm $(BIN)/prog $(OBJ)/main.o $(OBJ)/linked_list.o

