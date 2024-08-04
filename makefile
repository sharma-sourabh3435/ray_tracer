CC=g++
CFLAGS= -c -Wall -I src/include

SRC_DIR = src/features
OBJ_DIR = obj

all: prog

prog: main.o $(OBJ_DIR)/tuple.o $(OBJ_DIR)/color.o $(OBJ_DIR)/canvas.o
	$(CC) main.o $(OBJ_DIR)/tuple.o $(OBJ_DIR)/color.o $(OBJ_DIR)/canvas.o -o prog

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

$(OBJ_DIR)/tuple.o: $(SRC_DIR)/tuple.cpp
	$(CC) $(CFLAGS) $(SRC_DIR)/tuple.cpp -o $(OBJ_DIR)/tuple.o

$(OBJ_DIR)/color.o: $(SRC_DIR)/color.cpp
	$(CC) $(CFLAGS) $(SRC_DIR)/color.cpp -o $(OBJ_DIR)/color.o

$(OBJ_DIR)/canvas.o: $(SRC_DIR)/canvas.cpp
	$(CC) $(CFLAGS) $(SRC_DIR)/canvas.cpp -o $(OBJ_DIR)/canvas.o

clean:
	rm -rf $(OBJ_DIR)/*.o main.o prog

all: $(OBJ_DIR) prog