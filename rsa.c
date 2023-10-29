#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./rsa FILENAME\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");
    char *line = NULL, *p = NULL;
    size_t size = 1024;
    unsigned long long number, i, j;

    getline(&line, &size, fp);

    number = strtoull(line, &p, 10);

    for (i = number / 2 - 1; i > 2; i--)
    {
        if (number % i == 0)
        {
            printf("%llu=%llu*%llu\n", number, i, number / i);
            break;
        }
    }

    if (i == 2)
        printf("%llu=%llu*%i\n", number, number / 2, 2);

    free(line);

    return 0;
}
