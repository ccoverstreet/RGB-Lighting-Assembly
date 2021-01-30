#pragma once

#include <stdio.h>
#include "./timing.h"

int R1;

void print_registers() {
	printf("R1: %d\n", R1);
}

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

int jump(int stack_ind, unsigned int *argv) {
	printf("JUMP\n");
	return stack_ind + argv[1];
}

int jump_eq(int stack_ind, unsigned int *argv) {
	if (R1 == argv[2]) {
		return stack_ind + argv[1];
	}

	return stack_ind + 3;
}

int jump_lt(int stack_ind, unsigned int *argv) {
	if (R1 < argv[2]) {
		return stack_ind + argv[1];
	}

	return stack_ind + 3;
}

int jump_gt(int stack_ind, unsigned int *argv) {
	if (R1 > argv[2]) {
		return stack_ind + argv[1];
	}

	return stack_ind + 3;
}

int jump_lt_eq(int stack_ind, unsigned int *argv) {
	if (R1 <= argv[2]) {
		return stack_ind + argv[1];
	}

	return stack_ind + 3;
}

int jump_gt_eq(int stack_ind, unsigned int *argv) {
	if (R1 >= argv[2]) {
		return stack_ind + argv[1];
	}

	return stack_ind + 3;
}

int set_R1(int stack_ind, unsigned int *argv) {
	R1 = argv[1];

	return stack_ind + 2;
}

int increment_R1(int stack_ind, unsigned int *argv) {
	R1 += argv[1];
	return stack_ind + 2;
}

int decrement_R1(int stack_ind, unsigned int *argv) {
	R1 -= argv[1];
	return stack_ind + 2;
}


Instruction i_set[32] = {
	{noop, 0}, // 0x00000000
	{go_to, 1}, // 0x00000001
	{jump, 1}, // 0x00000002
	{jump_eq, 2}, // 0x00000003
	{jump_lt, 2}, // 0x00000004
	{jump_gt, 2}, // 0x00000005
	{jump_lt_eq, 2}, // 0x00000006
	{jump_gt_eq, 2}, // 0x00000007
	{set_R1, 1}, // 0x00000008
	{increment_R1, 1}, // 0x00000009
	{decrement_R1, 1}, // 0x0000000a
	{noop, 0}, // 0x00000009
	{noop, 0}, // 0x0000000c
	{noop, 0}, // 0x0000000d
	{noop, 0}, // 0x0000000e
	{noop, 0}, // 0x0000000f

	// Application Specific Section
};
