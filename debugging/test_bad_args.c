#include <stdio.h>

void bad_arguments(int argument) {
	printf("Int: %d");
	return;
}

int main() {
	char * string = "Hello world!\n";
	bar_arguments(string);
	return 0;
}
