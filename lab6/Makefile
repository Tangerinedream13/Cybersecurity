# Makes steggy for lab7

CC = gcc

all: steggy steghelper main
	@echo "Compiling..."
	${CC} -o steggy steggy.o steghelper.o main.o -lm

steggy: steggy.c steggy.h
	@echo "Compiling..."
	${CC} -c steggy.c

steghelper: steghelper.c steghelper.h
	@echo "Compiling..."
	${CC} -c steghelper.c

main: main.c steggy.h steghelper.h
	@echo "Compiling..."
	${CC} -c main.c

clean:
	rm *.o
