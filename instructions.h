#pragma once

#include <stdio.h>
#include <windows.h>

int R1;
int R2;


typedef struct {
	int (*func)(int stack_ind, unsigned int *argv);
	unsigned int argc;
} Instruction;

int noop(int stack_ind, unsigned int *argv) {
	printf("NO-OP\n");
	return stack_ind + 1;
}

int go_to(int stack_ind, unsigned int *argv) {
	printf("GOTO\n");
	return argv[1];
} 

int print(int stack_ind, unsigned int *argv) {
	printf("PRINT\n");
	printf("%08x\n", argv[1]);
	return stack_ind + 2;
}

int print_R1(int stack_ind, unsigned int *argv) {
	printf("PRINT R1\n");
	printf("R1: %d\n", R1);

	return stack_ind + 1;
}

int print_R2(int stack_ind, unsigned int *argv) {
	printf("PRINT R2\n");
	printf("R2: %d\n", R2);

	return stack_ind + 1;
}

int set_R1(int stack_ind, unsigned int *argv) {
	printf("SET R1\n");
	R1 = (int)argv[1];

	return stack_ind + 2;
}

int add_R1(int stack_ind, unsigned int *argv) {
	printf("ADD R1\n");
	R1 += (int)argv[1];

	return stack_ind + 2;
}

int less_than_R1(int stack_ind, unsigned int *argv) {
	R2 = argv[1] < R1;
	return stack_ind + 2;
}

int linear_color_change(int stack_ind, unsigned int *argv) {
	printf("Linear color change\n");
	unsigned int c1 = argv[1];
	unsigned int c2 = argv[2];
	unsigned int time_step = argv[3];
	unsigned int n_steps = argv[4];


	float step_size = 1 / (float)(n_steps - 1);
	printf("Step Size %f", step_size);
	printf("C1: %08x, C2: %08x, t-step: %u, n-steps: %u\n", c1, c2, time_step, n_steps);

	for (unsigned int i = 0; i < n_steps; i++) {
		printf("%u,", i);
		Sleep(time_step);
	}
	printf("\n");

	return stack_ind + 5;
}

Instruction i_set[16] = {
	{noop, 0},
	{go_to, 1},
	{print, 1},
	{print_R1, 0},
	{print_R2, 0},
	{set_R1, 1},
	{add_R1, 1},
	{less_than_R1, 1},
	{linear_color_change, 4}
};
