#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char sample[] = 
	"0x00000010\n"
	"0xff0000ff\n"
	"0x0000000b\n"
	"0x00000fff\n"
	"0x00000010\n"
	"0x00ff00ff\n"
	"0x00000001\n"
	"0x00000000\n"
	"0x00000000\n"
	"0x00000000\n"
	"0x00000000\n"
	"0x00000000\n";

int parse_program(char *program, unsigned int *stack_dest, unsigned int stack_size) {
	char *tok = strtok(program, "\n");

	unsigned int stack_ind = 0;
	
	while (tok != NULL) {
		stack_dest[stack_ind] = (unsigned int)strtol(tok, NULL, 16);
		stack_ind++;
		tok = strtok(NULL, "\n");
	}

	return 0;
}

int load_program_file(const char *filename, unsigned int *stack_dest, unsigned int stack_size) {
	FILE *file = fopen(filename, "r");
	char line[256];

	unsigned int stack_ind = 0;

	while (fgets(line, sizeof(line), file)) {
		if (strcmp(line, "\n")) {
			printf("%s\n", line);
			stack_dest[stack_ind] = (unsigned int)strtol(line, NULL, 16);
			stack_ind++;
		}
	}

	fclose(file);

	return 0;
}
