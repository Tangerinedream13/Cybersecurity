CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

TARGET = lab4
OBJS = main.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f $(TARGET) $(OBJS)


# ./lab4 everything.txt
# ./lab4 abc.txt