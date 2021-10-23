#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	int N, M, S;
	if (argc == 1) {
		printf("range - arithmetic progression generator\n" \
			   "usage:\n\trange [M, N, S]\n" \
			   "M - start of sequence,\n" \
			   "N - end of sequence (not included),\n" \
			   "S - step.\n");
	} else if (argc == 2) {
		N = atoi(argv[1]);
		M = 0;
		S = 1;
	} else if (argc == 3) {
		N = atoi(argv[2]);
		M = atoi(argv[1]);
		S = 1;
	} else if (argc == 4) {
		N = atoi(argv[2]);
		M = atoi(argv[1]);
		S = atoi(argv[3]);
	} else {
		printf("Invalid number of arguments!\n");
	}

	for(int i = M; i < N; i += S) {
		printf("%d\n", i);
	}
}