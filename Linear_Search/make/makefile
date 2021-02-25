GCC = gcc
SRC = ./../src/
OBJ = ./../obj/
BIN = ./../bin/
INC = ./../inc/
CFLAGS = -c -g -Wall
IFLAGS = -I$(INC)
LFLAGS =

all: $(BIN)prog

$(BIN)prog: $(OBJ)main.o $(OBJ)linear_search.o
	$(GCC) $(OBJ)main.o $(OBJ)linear_search.o -o prog
	mv prog $(BIN)
	
$(OBJ)main.o: $(SRC)main.c $(INC)linear_search.h
	$(GCC) $(CFLAGS) $(SRC)main.c $(IFLAGS)
	mv main.o $(OBJ)

$(OBJ)linear_search.o: $(SRC)linear_search.c $(INC)linear_search.h
	$(GCC) $(CFLAGS) $(SRC)linear_search.c $(IFLAGS)
	mv linear_search.o $(OBJ)

clean:
	rm -f $(OBJ)*.o $(BIN)*

											
												
												
