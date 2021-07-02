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

#include "msq.h"

bool is_magic_square(unsigned long long size, unsigned long long *magic_square) {

    unsigned long long sum;

    // expected magic constant sigma
    unsigned long long expected;

    // even
    if (size % 2 == 0) {
        expected = size / 2 * (size * size + 1);

    // odd
    } else if (size % 2 == 1) {
        expected = size * ((size * size + 1) / 2);
    }

    // check all rows
    for (unsigned long long i = 0; i < size; ++i) {
        sum = 0;

        for (unsigned long long j = 0; j < size; ++j)
            sum += magic_square[i * size + j];

        if (sum != expected)
            return false;
    }

    // check all columns
    for (unsigned long long i = 0; i < size; ++i) {
        sum = 0;

        for (unsigned long long j = 0; j < size; ++j)
            sum += magic_square[j * size + i];


        if (sum != expected)
            return false;
    }

    // check main diagonal
    sum = 0;

    for (unsigned long long i = 0; i < size; ++i) {
        sum += magic_square[i * size + i];
    }

    if (sum != expected)
        return false;


    // check main backdiagonal
    sum = 0;

    for (unsigned long long i = 0; i < size; ++i) {
        sum += magic_square[i * size + (size - i - 1)];
    }

    if (sum != expected)
        return false;

    return true;
}
