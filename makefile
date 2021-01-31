CC = zig cc 

driver: src/main.c src/instructions.h src/programparser.h
	$(CC) src/main.c -o driver

run: driver
	./driver

clean:
	rm driver
