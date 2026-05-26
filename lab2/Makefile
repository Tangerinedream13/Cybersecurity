# Makes buffy buffer overflow project

CC = gcc

all: buffy

buffy: input main
	@echo "Compiling..."
	${CC} -o buffy main.o input.o

input:
	@echo "Compiling..."
	${CC} -c input.c

main:
	@echo "Compiling..."
	${CC} -c main.c

clean:
	rm -f input.o main.o buffy