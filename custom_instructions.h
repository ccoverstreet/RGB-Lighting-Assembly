#pragma once

int print_RGB(int stack_ind, unsigned int *argv) {
	unsigned int r = argv[1] >> 8 * 3;
	printf("%02x\n", r);

	return stack_ind + 2;
}
