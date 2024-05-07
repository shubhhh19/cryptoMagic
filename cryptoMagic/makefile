
CC = gcc #our compiler
CFLAGS = -Wall -O2 #our compiler flags
SRC_DIR = src #directories
INC_DIR = inc
OBJ_DIR = obj
BIN_DIR = bin
TARGET = $(BIN_DIR)/cryptoMagic #for target executable
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)

clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR)

test_custom: $(TARGET)
	./$(TARGET) -encrypt $(INPUT_FILE)
	./$(TARGET) -decrypt $(OUTPUT_FILE)

.PHONY: all clean test_custom
