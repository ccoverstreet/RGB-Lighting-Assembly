#include "./stack.h"
#include "./instructions.h"
#include "./custom_instructions.h"
#include "./programparser.h"

#include <stdio.h>
#include "./timing.h"


int main() {
	// All this stack parsing should be moved into instructions.h
	unsigned int stack[STACK_SIZE] = {0};


	load_program_file("./programs/rgb_for_loop.txt", stack, STACK_SIZE);
	//parse_program(sample, stack, STACK_SIZE);

	// Custom definitions start at 0x00000010
	i_set[0x00000010] = (Instruction){print_RGB, 1};

	int cur_index = 0;
	while (cur_index >= 0 && cur_index < STACK_SIZE) {
		printf("Stack index %d: %08x\n", cur_index, stack[cur_index]);
		print_registers();
		if (stack[cur_index] < 32) {
			if (STACK_SIZE - cur_index - 1 < i_set[stack[cur_index]].argc) {
				printf("ERROR: Insufficient stack space for arguments.\n");
				cur_index = 0;
				break;
			}
			cur_index = i_set[stack[cur_index]].func(cur_index, &stack[cur_index]);
		} else {
			printf("Instruction not recognized. Defaulting to NO-OP.\n");
			cur_index += 1;
		}
		msleep(000);
	}

	return 0;
}
