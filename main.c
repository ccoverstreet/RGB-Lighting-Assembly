#include "./stack.h"
#include "./instructions.h"
#include "./custom_instructions.h"

#include <stdio.h>
#include "./timing.h"

#define STACK_SIZE 30

int main() {
	unsigned int stack[STACK_SIZE] = {
		0x00000008, // Set R1 to 0
		0x00000000,
		0x00000000, // Placeholder for doing stuff in loop
		0x00000009, // Increment R1 by 1
		0x00000001,
		0x00000007, // Jump if R1 >= 2, should do two iterations
		0x00000005, // Jumps to NOOP after GOTO
		0x00000002,
		0x00000001, // GOTO 2, start of loop
		0x00000002,
		0x00000000,
		0x00000010,
		0xff00ffff
	};

	for (int i = 0; i < STACK_SIZE; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%u\n", stack[i]);
		}
	}
	
	// Custom definitions start at 0x00000010
	i_set[0x00000010] = (Instruction){print_RGB, 0};

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
			cur_index += 1;
		}
		msleep(200);
	}

	return 0;
}
