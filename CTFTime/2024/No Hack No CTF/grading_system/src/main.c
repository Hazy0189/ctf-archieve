#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void spawn_shell() {
	system("/bin/sh");
	return;
}


int main() {
	unsigned int *score;
	unsigned int index, length, value, number_of_students, i, is_admin = 1234;
	size_t size_of_array;
	char opcode;

	setvbuf(stdin, 0, _IONBF, 0);
	setvbuf(stdout, 0, _IONBF, 0);

	puts("Online grading system - management interface");
	printf("Number of students: ");
	scanf("%u", &number_of_students);
	puts("Notice: values must NOT be negative!");

	size_of_array = number_of_students * sizeof(unsigned int);

	score = alloca(size_of_array);
	memset(score, 0, size_of_array);

	while (1) {
		puts("Options:");
		puts("    (V)iew grade of a student");
		puts("    (D)ump grades of specific range");
		puts("    (K)ey in grade of a student");
		puts("    (Q)uit the system");

		printf("Your choice: ");
		scanf(" %c", &opcode);
		switch (opcode) {
		case 'V':
			printf("seat_number: ");
			scanf("%u", &index);
			printf("score = %u\n", score[index + 1]);
			break;
		case 'D':
			printf("seat_number,length: ");
			scanf("%u,%u", &index, &length);
			for (i = index;i < index + length; i++) {
				printf("%u\n", score[i + 1]);
			}
			break;
		case 'K':
			printf("seat_number,score: ");
			scanf("%u,%u", &index, &value);
			score[index + 1] = value;
			break;
		case 'Q':
			puts("Exiting...");
			return 0;
		/* Spawn a shell, for developers only */
		case 'S':
			if (is_admin) {
				spawn_shell();
				break;
			} else {
				puts("Contact admin if you a bug occurred");
				break;
			}
		default:
			puts("Invalid operation, ignored");
			break;
		}
	}
}
