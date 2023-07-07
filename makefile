CC = g++
CFLAGS = -std=c++11 -Wall
INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))
EXECUTABLE = $(BIN_DIR)/Organizzer

all: directories $(EXECUTABLE)

directories:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BIN_DIR)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXECUTABLE)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all directories clean