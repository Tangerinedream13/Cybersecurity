# Makes rot13

CC = gcc

all: main beale bealehelper rothelper
	@echo "Compiling..."
	${CC} -o beale main.o beale.o bealehelper.o rothelper.o

main: main.c beale bealehelper
	@echo "Compiling..."
	${CC} -c main.c

beale:  beale.c beale.h
	@echo "Compiling..."
	${CC} -c beale.c

bealehelper: bealehelper.c bealehelper.h
	@echo "Compiling..."
	${CC} -c bealehelper.c

rothelper: rothelper.c rothelper.h
	@echo "Compiling..."
	${CC} -c rothelper.c

test: beale_test.c beale bealehelper rothelper
	@echo "compiling..."
	${CC} -c beale_test.c
	${CC} -o bt beale_test.o beale.o bealehelper.o rothelper.o

clean:
	rm *.o
