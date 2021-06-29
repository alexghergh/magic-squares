CC = gcc

SRCS = magic-squares.c
OBJS = $(patsubst %.c, %.o, $(SRCS))

EXEC = magic-squares

all: $(EXEC)

%.o: %.c
	$(CC) -o $@ -c $<

$(EXEC): $(OBJS)
	$(CC) -o $@ $^

clean:
	rm -rf $(OBJS)
	rm -rf $(EXEC)

re: clean all
