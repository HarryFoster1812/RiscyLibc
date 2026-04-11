# Toolchain
RISCV_PREFIX ?= riscv64-unknown-elf
RISCV_CC = $(RISCV_PREFIX)-gcc
RISCV_OBJDUMP = $(RISCV_PREFIX)-objdump
RISCV_OBJCOPY = $(RISCV_PREFIX)-objcopy

# Compilation flags
RISCV_FLAGS = -march=rv32im_zicsr -mabi=ilp32 -ffreestanding -Iinclude -Wall -Wextra -O2

# Source files
CRT_SRCS = crt/crt0.s crt/__libc_start_main.c
C_SRCS = io/*.c mm/*.c stdio/*.c string/*.c syscall.c

# Object files
CRT_OBJS = $(CRT_SRCS:.c=.o)
CRT_OBJS := $(CRT_OBJS:.s=.o)
C_OBJS = $(C_SRCS:.c=.o)

# Output
LIB = riscylibc.a

# Default target
all: $(LIB)

# Assemble and compile CRT
crt/%.o: crt/%.s
	$(RISCV_CC) $(RISCV_FLAGS) -c $< -o $@

crt/%.o: crt/%.c
	$(RISCV_CC) $(RISCV_FLAGS) -c $< -o $@

# Compile C sources
%.o: %.c
	$(RISCV_CC) $(RISCV_FLAGS) -c $< -o $@

# Create static library
$(LIB): $(CRT_OBJS) $(C_OBJS)
	ar rcs $@ $^

# Clean build files
clean:
	rm -f $(C_OBJS) $(CRT_OBJS) $(LIB)

# Compile a test program
# Usage: make run TEST=test_program.c
run: $(LIB)
	$(RISCV_CC) $(RISCV_FLAGS) -nostdlib -static -L. -lriscylibc -lgcc -o $(basename $(TEST)) $(TEST)
