# Makes rot13

CC = gcc

all: caesar

caesar: main rot13 rothelper
	@echo "Compiling..."
	${CC} -o caesar main.c rot13.c rothelper.c

main: rot13 main.c
	@echo "Compiling..."
	${CC} -c main.c

rot13: rothelper rot13.c rot13.h
	@echo "Compiling..."
	${CC} -c rot13.c

rothelper: rothelper.c rothelper.h
	@echo "Compiling..."
	${CC} -c rothelper.c

clean:
	rm *.o