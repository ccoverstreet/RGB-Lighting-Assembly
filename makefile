CC = gcc

driver: main.c instructions.h
	$(CC) main.c -o driver

run: driver
	./driver

