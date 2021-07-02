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

SRCS_DIR = srcs
SRCS = $(wildcard $(SRCS_DIR)/*.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))
INCLUDES_DIR = $(SRCS_DIR)

EXEC = magic-squares

DYN_LIB = lib$(EXEC).so

all: $(DYN_LIB)

%.o: %.c
	$(CC) -fPIC -o $@ -c $< -I$(INCLUDES_DIR)

$(DYN_LIB): $(OBJS)
	$(CC) -shared -o $(DYN_LIB) $^

magic-squares.o: magic-squares.c
	$(CC) -c $< -o $@

$(EXEC): magic-squares.o $(DYN_LIB)
	$(CC) -L. -o $@ $< -l$(EXEC)

clean:
	rm -rf $(OBJS)
	rm -rf $(DYN_LIB)
	rm -rf $(EXEC)
	rm -rf magic-squares.o

re: clean all
