#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include "../include/eval.h"
#include "../include/lexer.h"

#define DEFER_ERROR(...) do { \
	fprintf(stderr, "\033[31;1;4mERROR\033[0m: %s:%d - ", __FILE__, __LINE__); \
	if (errno != 0) fprintf(stderr, "(%d) %s\n", errno, strerror(errno));\
	fprintf(stderr, __VA_ARGS__) \
	goto defer; \
} while (0);

#define ERROR(...) do { \
	fprintf(stderr, "\033[31;1;4mERROR\033[0m: %s:%d - ", __FILE__, __LINE__); \
	if (errno != 0) fprintf(stderr, "(%d) %s\n", errno, strerror(errno)); \
	fprintf(stderr, __VA_ARGS__); \
} while (0);

int main(int argc, char **argv) {
	// TODO abstract Lexer and Binary tree under the respective operations to clean up main
/*
	int evaluation_flag = 0;
	int opt;
	while ((opt = getopt(argc, argv, ":DI:hfart")) != -1) {
		switch (opt) {
			case 'e': evaluation_flag = 1;
			case 'D': 
				printf("Differentiation\n");
				// TODO Differentiate Binary Tree after parsing
			case 'I': printf("Integration\n");
			default:
				for (; optind < argc; optind++) fprintf(stderr, "\033[31;1;4mERROR\033[0m: Unknown flag %s\n", argv[optind]);
				fprintf(stderr, "\033[34;1;4mUSAGE\033[0m: %s [OPTION] [FILE]\n", argv[0]);
				exit(1);
		}
	}
*/
	char *filename = argv[1];
	printf("Reading data from the file %s\n", filename);
	size_t fsize;
	char *data = slurp_file(filename, &fsize);
	lex(data, fsize);

	free(data);
	return 0;
}

char *slurp_file(char *filepath, size_t *fsize) {
	FILE *f = fopen(filepath, "rb");
	if (f == NULL) {
		printf("Error opening file %s\n", filepath);
		return NULL;
	}
	if (fseek(f, 0, SEEK_END) == -1) {
		printf("Could not find end of file\n");
		return NULL;
	}
	if ((*fsize = ftell(f)) == -1) {
		printf("Could not get file sz in bytes\n");
		return NULL;
	}
	fseek(f, 0, SEEK_SET);
	char *data = malloc(*fsize * sizeof((data)));
	if (data == NULL){
		printf("Error allocating space for input file data: %s\n", filepath);
		return NULL;
	}
	if (fread(data, sizeof(*data), *fsize, f) == 0) {
		printf("Error reading file data\n");
		return NULL;
	}
	return data;
}

struct Token *lex(char *data, size_t sz) {
	printf("Data read = %ld;\n", sz);
	for (int i = 0; i < sz; i++) {
		printf("\t:%c\n", data[i]);
	}
	return NULL;
}
