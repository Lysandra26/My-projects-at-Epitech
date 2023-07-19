##
## EPITECH PROJECT, 2023
## B-ASM-400-MPL-4-1-asmminilibc-lysandra.manuguerra
## File description:
## Makefile
##

AS = nasm

CC = gcc

ASFLAGS = -f elf64

SRCS = $(wildcard src/*.asm)

OBJS = $(SRCS:.asm=.o)

TARGET = libasm.so

TEST_SRCS = $(wildcard tests/*.c)

TEST_OBJS = $(TEST_SRCS:.c=.o)

TEST_TARGET = libasm

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -nostdlib -shared -fPIC $(OBJS) -o $(TARGET)

%.o : %.asm
	$(AS) $(ASFLAGS) -o $@ $<

clean:
	$(RM) $(OBJS) $(TEST_OBJS)

fclean: clean
	$(RM) $(TARGET) $(TEST_TARGET)

re: fclean all

test: $(TEST_OBJS)
	$(CC) $(TEST_OBJS) -o $(TEST_TARGET) -L. -lasm
