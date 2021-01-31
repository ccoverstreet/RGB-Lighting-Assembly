#pragma once

typedef struct {
	unsigned int r;
	unsigned int g;
	unsigned int b;
	unsigned int a;
} RGBA_Color;

RGBA_Color parse_color(unsigned int color) {
	RGBA_Color x = {
		color >> (8 * 3),
		color >> (8 * 2) & 0xff,
		color >> (8 * 1) & 0xff,
		color & 0xff
	};

	return x;
}

int print_RGB(int stack_ind, unsigned int *argv) {
	RGBA_Color color = parse_color(argv[1]);

	printf("r: %u\n", color.r);
	printf("g: %u\n", color.g);
	printf("b: %u\n", color.b);
	printf("a: %u\n", color.a);

	return stack_ind + 2;
}
