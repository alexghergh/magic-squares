CC = gcc

SRCS = magic-squares.c generate.c
OBJS = $(patsubst %.c, %.o, $(SRCS))
INCLUDES = magic-squares.h

EXEC = magic-squares

all: $(EXEC)

%.o: %.c
	$(CC) -o $@ -c $<

$(EXEC): $(OBJS) $(INCLUDES)
	$(CC) -o $@ $^ -I.

clean:
	rm -rf $(OBJS)
	rm -rf $(EXEC)

re: clean all
