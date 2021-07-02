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

#ifndef _MSQ_H
#define _MSQ_H

#include <stdbool.h>

/*
 * Generate a magic square of the size given by the first parameter. The magic
 * square is generated in the second parameter, which must be a pointer to an
 * allocated memory block of at least size * size bytes of contiguous memory.
 * This memory needs to be zero'ed out before the call to the function.
 *
 * Failure to correctly pass such an array as parameter results in undefined
 * behaviour.
 *
 * A caller function should not rely on this method doing any kind of sanity
 * checks. Not even the size or the fact that the array is zero'ed are verified.
 * Such cases yield undefined behaviour.
 */
void generate_magic_square(unsigned long long size, unsigned long long *magic_square);

/*
 * Generic method to verify if a matrix is a magic square. The only checks it
 * performs are on the sums of the rows, columns, the main diagonal and the
 * main backdiagonal. It checks for all these sums to be equal to the magic
 * constant sigma, which is calculated based on the size of the matrix.
 *
 * The method will incorrectly return true if a matrix is passed with all
 * elements equal if it passes the tests above.
 *
 * Such cases are easy to spot though, since you can just test that two
 * adjacent cells are different.
 *
 * The method requires that a correct array is passed to it (see above).
 */
bool is_magic_square(unsigned long long size, unsigned long long *magic_square);

/*
 * Display a magic square on the standard output.
 *
 * This method requires the same properties as the above methods, i.e. care
 * must be taken when passing a pointer to an array as paramter. The method
 * does no sanity checks.
 */
void print_magic_square(unsigned long long size, unsigned long long *magic_square);

#endif
