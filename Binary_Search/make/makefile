GCC = gcc
SRC = ./../src/
OBJ = ./../obj/
BIN = ./../bin/
INC = ./../inc/
CFLAGS = -c -g -Wall
IFLAGS = -I$(INC)
LFLAGS =

all: $(BIN)prog

$(BIN)prog: $(OBJ)main.o $(OBJ)binary_search.o
	$(GCC) $(OBJ)main.o $(OBJ)binary_search.o -o prog
	mv prog $(BIN)
	
$(OBJ)main.o: $(SRC)main.c $(INC)binary_search.h
	$(GCC) $(CFLAGS) $(SRC)main.c $(IFLAGS)
	mv main.o $(OBJ)

$(OBJ)binary_search.o: $(SRC)binary_search.c $(INC)binary_search.h
	$(GCC) $(CFLAGS) $(SRC)binary_search.c $(IFLAGS)
	mv binary_search.o $(OBJ)

clean:
	rm -f $(OBJ)*.o $(BIN)*

											
												
												
