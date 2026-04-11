RISCV_PREFIX ?= riscv64-unknown-elf
CC = $(RISCV_PREFIX)-gcc
AR = $(RISCV_PREFIX)-ar

CFLAGS = -march=rv32im_zicsr -mabi=ilp32 -ffreestanding -Iinclude -Wall -Wextra -O2

CRT_SRCS = src/crt/crt0.s src/crt/__libc_start_main.c
C_SRCS = $(shell find src -name "*.c" ! -path "src/crt/*")

CRT_OBJS = $(CRT_SRCS:.s=.o)
CRT_OBJS := $(CRT_OBJS:.c=.o)
C_OBJS = $(C_SRCS:.c=.o)

LIB = riscylibc.a

all: $(LIB)

src/crt/%.o: src/crt/%.s
	$(CC) $(CFLAGS) -c $< -o $@

src/crt/%.o: src/crt/%.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB): $(CRT_OBJS) $(C_OBJS)
	$(AR) rcs $@ $^

clean:
	rm -f $(CRT_OBJS) $(C_OBJS) $(LIB)
