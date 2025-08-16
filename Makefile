CC = gcc
FLAGS = -Wall -g -Wextra -pedantic -Iinclude/

BIN_DIR = bin
SRC_DIR = source
TEST_DIR = test

SOURCE = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(BIN_DIR)/%.o,$(SOURCE))

LIB = $(BIN_DIR)/liblist.a

TEST_NW = $(TEST_DIR)/nwuser_test.c
TEST_RM = $(TEST_DIR)/rmuser_test.c

all: $(LIB)

$(BIN_DIR): 
	mkdir -p $(BIN_DIR)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c | $(BIN_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(LIB): $(OBJECTS)
	ar rcs $@ $^

$(BIN_DIR)/%.o: $(TEST_DIR)/%.c | $(BIN_DIR)
	$(CC) $(FLAGS) -c $< -o $@


list: $(LIB) main.c
	$(CC) $(FLAGS) main.c -Lbin/ -llist -o list


testall: $(LIB)  testnw testrm
	$(CC) $(FLAGS) $(TEST_DIR)/teste_nw.o $(TEST_DIR)/teste_rm.o -DTEST main.c -Lbin/ -llist -o list

testrm: $(LIB) 
	$(CC) $(FLAGS) -c $(TEST_RM) -o $(TEST_DIR)/teste_rm.o
	$(CC) $(FLAGS) $(TEST_DIR)/teste_rm.o -DTESTRM main.c -Lbin/ -llist -o list

testnw: $(LIB) 
	$(CC) $(FLAGS) -c $(TEST_NW) -Lbin/ -llist -o $(TEST_DIR)/teste_nw.o
	$(CC) $(FLAGS) $(TEST_DIR)/teste_nw.o -DTESTNW main.c -Lbin/ -llist -o list

clean:
	rm -rf $(BIN_DIR) $(TEST_DIR)/*.o list

.PHONY: clean list testrm testeall testnw testrm

