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

void generate_doubly_even_magic_square(long long size, long long *magic_square) {
    ;
}

void generate_singly_even_magic_square(long long size, long long *magic_square) {
    ;
}

void generate_odd_magic_square(long long size, long long *magic_square) {
    /*
     * Refer to the original paper for information on what these variables mean.
     *
     * The matrix generated can easily be altered by changing these 6 variables,
     * although they have to respect some properties for the matrix to be magic.
     *
     * See README.md, section "Odd-sized magic squares".
     */
    long long p;
    long long q;

    long long alpha;
    long long beta;

    long long a;
    long long b;

    // counter that goes from 1 to size^2
    long long counter = 1;

    p = 0;
    q = size / 2;

    alpha = size - 1;
    beta = 1;

    a = 1;
    b = 0;

    while (counter - 1 != size * size) {

        // calculate the correct indices for the row and column
        long long curr_row = (p + alpha * (counter - 1) + a * ((counter - 1) / size)) % size;
        long long curr_col = (q + beta * (counter - 1) + b * ((counter - 1) / size)) % size;

        // place an element
        magic_square[curr_row * size + curr_col] = counter++;
    }
}
