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

#include "tests.h"

/*
 * Setup with a 3x3 correct magic square.
 */
static int setup_with_size_3_correct(void **state) {
    struct mag_sq_info *info = NULL;

    if ((info = malloc(sizeof(struct mag_sq_info))) == NULL) {
        return -1;
    }

    info->size = 3;

    if ((info->arr = malloc(info->size * sizeof(unsigned long long))) == NULL) {
        return -1;
    }

    memset(info->arr, 0, info->size * info->size);

    info->arr[0] = 8;
    info->arr[1] = 1;
    info->arr[2] = 6;
    info->arr[3] = 3;
    info->arr[4] = 5;
    info->arr[5] = 7;
    info->arr[6] = 4;
    info->arr[7] = 9;
    info->arr[8] = 2;

    *state = info;

    return 0;
}

/*
 * Setup with empty 3x3 matrix.
 */
static int setup_with_size_3_empty(void **state) {
    struct mag_sq_info *info = NULL;

    if ((info = malloc(sizeof(struct mag_sq_info))) == NULL) {
        return -1;
    }

    info->size = 3;

    if ((info->arr = malloc(info->size * sizeof(unsigned long long))) == NULL) {
        return -1;
    }

    memset(info->arr, 0, info->size * info->size);

    *state = info;

    return 0;
}

/*
 * Teardown method. For cleanup.
 */
static int teardown(void **state) {
    struct mag_sq_info *info = *state;

    free(info->arr);
    free(info);

    return 0;
}

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test_setup_teardown(test_function_is_magic_square_on_odd_matrix_is_correct, setup_with_size_3_correct, teardown),
        cmocka_unit_test_setup_teardown(test_generate_with_size_3_returns_correct_magic_square, setup_with_size_3_empty, teardown),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
