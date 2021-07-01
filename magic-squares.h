/*
 * MIT License
 * 
 * Copyright (c) [2021] [Alexandru Gherghescu]
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. 
 */

#ifndef _MAGIC_SQUARES_H_
#define _MAGIC_SQUARES_H_

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <stdint.h>

#define MIN_MATRIX_SIZE 3

/**
 * Show the usage of the program.
 */
void print_usage();

/**
 * Parse a long long number from the argument given as arg.
 *
 * On success, returns the number extracted from the argument.
 *
 * On error, prints a message and terminate program.
 */
long long parse_input(const char *arg);

/*
 *
 */
void generate_doubly_even_magic_square(long long size, long long *magic_square);

/*
 *
 */
void generate_singly_even_magic_square(long long size, long long *magic_square);

/*
 *
 */
void generate_odd_magic_square(long long size, long long *magic_square);

#endif
