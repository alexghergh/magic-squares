# Magic squares

## Introduction

This repo implements the methods described in [Matrix Properties of Magic
Squares](https://faculty.etsu.edu/stephen/matrix-magic-squares.pdf) to generate magic squares of any size.

Throughout this README, I will refer to a certain page of the paper above by
using `(p. <page-number>)`.

The program does not strive to achieve the best performance possible (not in
the beginning at least), but to give a correct answer when asked for a certain
sized magic square matrix. The author does acknowledge the fact that the program
may be sped up considerably using threads, or assembly vector instructions, or
other means to achieve performance. All pull requests in this sense are welcome.

## Definitions

The program only generates what in the paper above is called _classical magic
squares_ (or _normal magic squares_), i.e. _"A magic square of order n, [which]
is a square matrix or array of n² numbers such that the sum of the elements of
each row and column, as well as the main diagonal and main backdiagonal, is the
same number, called the magic constant (or magic sum, or line-sum), [...] denoted
by σ(M). [...] the entries are thought of as the natural numbers 1, 2, ..., n²,
where each number is used exactly once [...]"_ (p. 4).

Aside from this very basic definition, I will link to other definitions that
may arise in this README directly to the paper.

## How the program works

The methods to generate a certain **n**-sized magic square matrix are different when
talking about odd or even **n**. Even when talking about an even **n**, we have to talk
about a _singly-even_ **n** and a _doubly-even_ **n**. Refer to (p. 7) for a complete
definition of what this means. In short _doubly-even_ means that **n** is divisible
by _4_; all other even numbers **n** are _singly-even_.

### Implementation limits

The maximum supported limits of the matrix size are 3 for the inferior limit
(there are no magic squares smaller than 3) and around 3e10 for the superior
limit, i.e. the maximum number squared that can fit inside an 8-byte integer
(for 64-bit machines), or 45000 for a 4-byte integer (for 32-bit machines).
Realistically speaking though, your computer will run out of memory way
before this limit is reached.

### Odd-sized magic squares

There are various methods to compute an odd-sized magic square matrix. The one
we will implement is _Uniform Step Method_ (p. 9). Refer to the paper for a
complete explanation on how the method works.

Magic squares of odd-numbers can be easily generated using the _Uniform Step
Method_ by altering 6 parameters. These parameters (presented in the paper,
see paragraph above), need to respect some properties for the square to be
"magic". The 6 parameters are **p**, **q** (the initial starting row and column),
**alpha** and **beta** (the step or distance to go from the element _n_ to element
_n + 1_), and **a** and **b** (the "offset" for a colliding element). From the
paper, _"The square formed by this method is magic if and only if a, b, alpha,
beta, and (alpha * b - a * beta) are each relatively prime to n)."_. In formula,
this is equivalent to (note, _"(m, n)"_ denotes the greatest common divisor):

```
(a, n) = 1
(b, n) = 1
(alpha, n) = 1
(beta, n) = 1
(alpha * b - a * beta, n) = 1
```

So if the 6 variables mentioned above respect these properties, than the matrix
will be a magic square.

### Even-sized magic squares divisible by 4 (doubly-even)

(TODO)

### Even-sized magic squares not divisible by 4 (singly-even)

(TODO)

## Running and testing the program

The repository contains a simple Makefile, which can be used to run the program.

The Makefile generates a dynamically linked shared library by default, which can
be used in your own program to generate a magic square.

The files `magic-square.c` and `magic-square.h` demonstrate how to use the
shared library. Please note that the library does little to no sanity checks,
and so the responsibility is on the caller program to make sure the memory
is safely allocated and contains only 0's when calling the magic square
generation method. For more information read the notes in `srcs/msq.h`. This
file also stands as an API interface reference.

To generate the shared library, do:

`make`

To generate the example program:

`make magic-squares`

And then running it is as simple as:

`LD_LIBRARY_PATH=<path/to/the/shared/library> ./magic_squares <number>`

Note how we had to let the linker know where it can find our library.

Unless you changed directories, the command just resumes to:

`LD_LIBRARY_PATH=. ./magic_squares <number>`

### Testing

The program contains unit tests, which check if the matrices generated are
indeed magic squares, that respect the properties outlined in the beginning
of this file.

The unit test framework used is [cmocka](https://cmocka.org).

To run the tests, you will need to install cmocka. Follow the instructions
at [the official cmocka GitLab repo](https://gitlab.com/cmocka/cmocka/-/blob/master/INSTALL.md) to install the library.

After having it installed, just run:

`make run_tests`

The above command should give you an output with tests that failed/passed.

If any of the tests fail, consider opening an issue with the output on the
[official Github repo of the project](https://github.com/alexghergh/magic-squares).

## Other notes

The code should be fully C99-compatible.

If you see any errors or feel like something could be improved in any way,
please open a pull request.

Author and maintainer: Alexandru Gherghescu (alexghergh@gmail.com)

## License

The project is licensed under the MIT license. See [LICENSE](https://github.com/alexghergh/magic-squares/blob/master/LICENSE) for more info.
