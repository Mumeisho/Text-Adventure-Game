# Build system for temperature converter application
# Creates organized directory structure with bin/ and obj/ folders

# Compiler configuration
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = temperature_converter
SRCDIR = .
CONVERTERDIR = ./Converters

# Build output directories
BINDIR = bin
OBJDIR = obj

# Source file locations
SOURCES = main.c getInput.c $(CONVERTERDIR)/celsius.c $(CONVERTERDIR)/farenheit.c $(CONVERTERDIR)/kelvin.c $(CONVERTERDIR)/getTemperatureInput.c
# Transform source files to object file paths in obj/ directory
OBJECTS = $(SOURCES:%.c=$(OBJDIR)/%.o)
# Final executable path
BINARY = $(BINDIR)/$(TARGET)

# Build the executable (default target)
all: $(BINARY)

# Create bin directory if it doesn't exist
$(BINDIR):
	mkdir -p $(BINDIR)

# Create obj directory if it doesn't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Link object files into final executable
$(BINARY): $(OBJECTS) | $(BINDIR)
	$(CC) $(OBJECTS) -o $@

# Compile source files to object files in obj/ directory
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Explicit dependencies for object files
$(OBJDIR)/main.o: main.c
$(OBJDIR)/getInput.o: getInput.c
$(OBJDIR)/$(CONVERTERDIR)/celsius.o: $(CONVERTERDIR)/celsius.c
$(OBJDIR)/$(CONVERTERDIR)/farenheit.o: $(CONVERTERDIR)/farenheit.c
$(OBJDIR)/$(CONVERTERDIR)/kelvin.o: $(CONVERTERDIR)/kelvin.c
$(OBJDIR)/$(CONVERTERDIR)/getTemperatureInput.o: $(CONVERTERDIR)/getTemperatureInput.c

# Remove all build artifacts
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Clean and rebuild everything
rebuild: clean all

# Targets that don't create files
.PHONY: all clean rebuild help run

# Display available build targets
help:
	@echo "Available targets:"
	@echo "  all      - Build the temperature converter (default)"
	@echo "  clean    - Remove all build artifacts"
	@echo "  rebuild  - Clean and build from scratch"
	@echo "  debug    - Build with debug flags"
	@echo "  release  - Build with optimization flags"
	@echo "  install  - Install to /usr/local/bin"
	@echo "  run      - Build and run the program"
	@echo "  help     - Show this help message"

# Build and execute the program
run: $(BINARY)
	./$(BINARY)

# Copy executable to system binary directory
install: $(BINARY)
	cp $(BINARY) /usr/local/bin/

# Build with debugging symbols and no optimization
debug: CFLAGS += -DDEBUG -O0
debug: $(BINARY)

# Build with optimization and no debug symbols
release: CFLAGS += -O2 -DNDEBUG
release: $(BINARY)