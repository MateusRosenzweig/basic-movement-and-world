CC = gcc
CFLAGS = -Wall -Wextra -Iinc/

SRCS := $(wildcard src/*.c)
OBJS := $(SRCS:src/%.c=obj/%.o)


app: $(OBJS)
	$(CC) $(OBJS) -o bin/app.exe

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f bin/*.exe obj/*.o

