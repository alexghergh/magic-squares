#
# MIT License
#
# Copyright (c) [2021] [Alexandru Gherghescu]
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#

CC = gcc
LINKER_FLAGS = -lcmocka

SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))
TEST_EXEC = test-magic-squares

all: $(TEST_EXEC)

%.o: %.c
	$(CC) -o $@ -c $< $(LINKER_FLAGS)

$(TEST_EXEC): $(OBJS)
	$(CC) -o $@ $^ $(LINKER_FLAGS) -L.. -lmagic-squares

clean:
	rm -rf $(OBJS)
	rm -rf $(TEST_EXEC)

re: clean all
