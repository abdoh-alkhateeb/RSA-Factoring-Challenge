#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: ./factors FILENAME\n");
		exit(EXIT_FAILURE);
	}

	FILE *fp = fopen(argv[1], "r");
	char *line = NULL, *p = NULL;
	size_t size = 1024;
	unsigned long long number, i, j;

	while (getline(&line, &size, fp) != EOF)
	{
		number = strtoull(line, &p, 10);

		j = number / 2;

		for (i = 2; i < j; i++)
		{
			if (number % i == 0)
			{
				printf("%llu=%llu*%llu\n", number, number / i, i);
				break;
			}
		}

		if (i == j)
			printf("%llu=%llu*%i\n", number, number, 1);
	}
}
