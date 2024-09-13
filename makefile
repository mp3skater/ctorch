# Makefile for a C program from ChatGBT

CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = bin/ctorch.out
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
SRC = $(SRC_DIR)/tensor.c $(SRC_DIR)/test.c
OBJ = $(BUILD_DIR)/tensor.o $(BUILD_DIR)/test.o

# Rule for linking the object files and creating the binary
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Rule for compiling .c files to .o files, placing them in the build directory
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)

# A simple test rule
check:
	cat test_generator.txt
	cat test_incoder.txt
	cat test_fehler.txt
	cat test_decoder.txt

# Clean object files and binary
clean:
	rm -f $(BUILD_DIR)/*.o $(TARGET)

# Clean everything, including output and temporary files
cleanall:
	rm -f $(BUILD_DIR)/*.o *.txt $(TARGET)