#include "magic-squares.h"

int main(int argc, char *argv[]) {

    if (argc != 2) {
        print_usage();
        exit(EXIT_FAILURE);
    }

    long long number = parse_input(argv[1]);

    printf("%lld\n", number);

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

    // underflow or overflow
    if (errno == ERANGE) {

        printf("Warning: Underflow or overflow occured! ");

        if (ret == LLONG_MIN) {
            printf("Continuing with minimum possible value %lld.\n", ret);

        } else if (ret == LLONG_MAX) {
            printf("Continuing with maximum possible value %lld.\n", ret);
        }

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
