# Makefile for a C program from ChatGBT

CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = bin/ctorch.out
TTARGET = bin/tensor.out
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
TENSOR_DIR = tensor

# Files for the main project
SRC = $(SRC_DIR)/linear_regression.c $(SRC_DIR)/parser.c $(SRC_DIR)/test.c
OBJ = $(BUILD_DIR)/linear_regression.o $(BUILD_DIR)/parser.o $(BUILD_DIR)/test.o

# Files for the tensor project
TSRC = $(TENSOR_DIR)/tensor.c $(TENSOR_DIR)/test.c
TOBJ = $(TENSOR_DIR)/tensor.o $(TENSOR_DIR)/test.o

# Rule for linking the object files and creating the binary
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(TTARGET): $(TOBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Rule for compiling .c files to .o files, placing them in the build directory
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(TENSOR_DIR)/%.o: $(TENSOR_DIR)%.c
	$(CC) $(CFLAGS) -I$(TENSOR_DIR) -c $< -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)

tensor: $(TTARGET)
	./$(TTARGET)

# Clean object files and binary
clean:
	rm -f $(BUILD_DIR)/*.o $(TARGET)

# Clean everything, including output and temporary files
cleanall:
	rm -f $(BUILD_DIR)/*.o *.txt $(TARGET)