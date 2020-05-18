all: first
first: first.c
	gcc -Wall -Werror -fsanitize=address -lm  -std=c11 first.c -o first

clean:
	rm -f first	
