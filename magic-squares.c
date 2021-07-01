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

#include "magic-squares.h"

int main(int argc, char *argv[]) {

    if (argc != 2) {
        print_usage();
        exit(EXIT_FAILURE);
    }

    long long *magic_square;
    long long size;

    size = parse_input(argv[1]);

    // to check if malloc failed, see malloc(1)
    errno = 0;

    // allocate memory for the matrix
    magic_square = malloc(sizeof(long long) * size);

    if (magic_square == NULL && errno == ENOMEM) {
        printf("Error: Out of memory! Quitting!\n");
        exit(EXIT_FAILURE);
    }

    // doubly-even matrix
    if (size % 4 == 0) {

        generate_doubly_even_magic_square(size, magic_square);

    // singly-even matrix
    } else if (size % 2 == 0) {

        generate_singly_even_magic_square(size, magic_square);

    // odd matrix
    } else if (size % 2 == 1) {

        generate_odd_magic_square(size, magic_square);
    }

    return 0;
}

void print_usage() {
    printf("usage: ./magic-squares <number>\n\t where <number> is a number bigger than 3\n");
}

long long parse_input(const char *arg) {
    char *check;
    long long ret;

    // set errno to 0 before the call, see strtoll(1)
    errno = 0;
    ret = strtoll(arg, &check, 10);

    if (ret < MIN_MATRIX_SIZE) {
        printf("Warning: Matrix size cannot be smaller than 3! Continuing with size 3.\n");
        ret = MIN_MATRIX_SIZE;
    }

    // check that the number won't overflow when squared
    if (ret * ret < ret) {
        printf("Error: Overflow occured! Please input a lower number! Quitting!\n");
        exit(EXIT_FAILURE);
    }

    // underflow or overflow; treated above, ignore
    if (errno == ERANGE) {

    // other error
    } else if (errno != 0) {
        perror("strtoll");
        printf("Unrecovarable error. Quitting!\n");
        exit(EXIT_FAILURE);
    }

    if (arg == check) {
        printf("Not a number. Quitting!\n");
        exit(EXIT_FAILURE);
    }

    if (*check != '\0') {
        printf("Trailing characters, please enter a number. Quitting!\n");
        exit(EXIT_FAILURE);
    }

    // if we got here, strtoll() successfully parsed a number

    return ret;
}
