# Compiler and Flags
CC = clang
CFLAGS = -Wall -O2 -fPIC -fdiagnostics-color=always
LDFLAGS = -ldl

# Directories
SRC_DIR = ./src
OBJ_DIR = ./obj
OUT_DIR = /steam

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Output shared object
SO_FILE = hook.so

# Header files
HEADERS = $(wildcard $(SRC_DIR)/*.h)

# Default target to build everything
all: $(SO_FILE)

# Rule to create the .so file
$(SO_FILE): $(OBJ_FILES)
	$(CC) $(CFLAGS) -shared -o $(SO_FILE) $^ $(LDFLAGS)
	cp $(SO_FILE) $(OUT_DIR)

# Rule to compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean up object files and the shared object
clean:
	rm -rf $(OBJ_DIR) $(SO_FILE)

# Phony targets
.PHONY: all clean
