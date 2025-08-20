CC = clang
FLAGS = -Wall -g -Wextra -pedantic -Iinclude/

BIN_DIR = bin
SRC_DIR = source
TEST_DIR = test

SOURCE = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(SOURCE))

LIB = $(BIN_DIR)/liblist.a
INC = -Lbin

TEST_SRC = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJ = $(patsubst $(TEST_DIR)/%.c, $(TEST_DIR)/%.o, $(TEST_SRC))

TEST_NW = $(TEST_DIR)/nwuser_test.c
TEST_RM = $(TEST_DIR)/rmuser_test.c
TEST_PS = $(TEST_DIR)/psuser_test.c

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
	$(CC) $(FLAGS) main.c -llist -Lbin -o list


testall: $(LIB) | $(TEST_OBJ)
	$(CC) $(FLAGS) $(TEST_OBJ) -DTEST main.c $(INC) -llist -o list

testrm: $(LIB) 
	$(CC) $(FLAGS) -c $(TEST_RM) -o $(TEST_DIR)/rmuser_test.o
	$(CC) $(FLAGS) $(TEST_DIR)/rmuser_test.o -DTESTRM main.c $(INC) -llist -o list

testnw: $(LIB) 
	$(CC) $(FLAGS) -c $(TEST_NW) -o $(TEST_DIR)/nwuser_test.o
	$(CC) $(FLAGS) $(TEST_DIR)/nwuser_test.o -DTESTNW main.c $(INC) -llist -o list

testps: $(LIB)
	$(CC) $(FLAGS) -c $(TEST_PS) -o $(TEST_DIR)/psuser_test.o
	$(CC) $(FLAGS) $(TEST_DIR)/psuser_test.o -DTESTPS main.c $(INC) -llist -o list

$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(BIN_DIR) $(TEST_DIR)/*.o list

.PHONY: clean list testall testrm testnw testps

