#include <stdio.h>

#define SHELLCODE_LENGTH 0x1000

int main() {
	char shellcode[SHELLCODE_LENGTH];

	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	puts("Speak English *ONLY* !!!");
	puts("No more crazy stuffs like binary !!!");
	scanf(" %[a-zA-Z0-9]", shellcode);
	((void (*)(void))shellcode)();
}
