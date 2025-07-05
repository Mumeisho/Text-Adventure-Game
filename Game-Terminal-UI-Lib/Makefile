CC = gcc
CFLAGS = -Wall -Wextra -std=c2x

gtuilib_test: testing.c basic/basic_terminal.c
	$(CC) $(CFLAGS) -o gtuilib_test testing.c basic/basic_terminal.c -Ibasic

clean:
	rm -f gtuilib_test

.PHONY: clean