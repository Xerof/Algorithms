all: LinkedList

OBJ=LinkedList.o
CC=gcc
CFLAGS+= -Wall -Werror
LIBS =

LinkedList: $(OBJ)
		$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
		rm -f LinkedList *.o
.PHONY: all clean



