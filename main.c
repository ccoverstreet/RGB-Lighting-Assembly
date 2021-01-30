#include "./stack.h"
#include "./instructions.h"
#include <stdio.h>
#include "./timing.h"

#define STACK_SIZE 15


int main() {
	unsigned int stack[STACK_SIZE] = {
		0x00000005,
		0x0000000f,
		0x00000007,
		0x00000001,
		0x00000004
	};

	int cur_index = 0;
	while (cur_index >= 0 && cur_index < STACK_SIZE) {
		printf("Stack index %d: %08x\n", cur_index, stack[cur_index]);
		if (stack[cur_index] < 16) {
			if (STACK_SIZE - cur_index - 1 < i_set[stack[cur_index]].argc) {
				printf("ERROR: Insufficient stack space for arguments.\n");
				cur_index = 0;
				break;
			}
			cur_index = i_set[stack[cur_index]].func(cur_index, &stack[cur_index]);
		} else {
			cur_index += 1;
		}
		msleep(400);
	}

	return 0;
}
