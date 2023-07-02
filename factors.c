#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *str;
	char *line = NULL;
	size_t len = 0;
	long long flag = 1, div, rest, number, counter;
	ssize_t nread;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	str = fopen(argv[1], "r");
	if (str == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&line, &len, str)) != -1) {
		flag = 1, div = 2;
		number = atoll(line);
		while (flag) {
			rest = number % div;
			if (!rest) {
				counter = number / div;
				printf("%lld=%lld*%lld\n", number, counter, div);
				flag = 0;
			}
			div++;
		}
	}

	free(line);
	fclose(str);
	exit(EXIT_SUCCESS);
}
