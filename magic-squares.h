#ifndef _MAGIC_SQUARES_H_
#define _MAGIC_SQUARES_H_

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

/**
 * Show the usage of the program.
 */
void print_usage();

/**
 * Parse a long long number from the argument given as arg.
 *
 * On success, returns the number extracted from the argument.
 *
 * On error, prints a message and program exits.
 */
long long parse_input(const char *arg);

#endif