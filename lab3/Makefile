# Makes rot13

CC = gcc

all: viggy

viggy: main vigenere rothelper
	@echo "Compiling..."
	${CC} -o viggy main.o vigenere.o rothelper.o

main: vigenere main.c
	@echo "Compiling..."
	${CC} -c main.c

vigenere:  vigenere.c vigenere.h
	@echo "Compiling..."
	${CC} -c vigenere.c

rothelper: rothelper.c rothelper.h
	@echo "Compiling..."
	${CC} -c rothelper.c

clean:
	rm *.o
