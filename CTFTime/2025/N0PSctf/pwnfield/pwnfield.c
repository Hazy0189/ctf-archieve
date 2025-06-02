#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

#define MAX_INSTRUCTIONS 32
#define USER_INSTR_SIZE 5
#define MINE_SIZE 12
#define LINE_SIZE (USER_INSTR_SIZE + MINE_SIZE)
#define TOTAL_SIZE (LINE_SIZE * MAX_INSTRUCTIONS) + 1
 
const uint8_t exit_mine[] = {
    0xB8, 0x3C, 0x00, 0x00, 0x00,     
    0xBF, 0x39, 0x05, 0x00, 0x00,     
    0x0F, 0x05                        
};

int main() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);

    void *mem = mmap(NULL, TOTAL_SIZE, PROT_READ | PROT_WRITE | PROT_EXEC,
                     MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (mem == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    uint8_t *p = mem;
    printf("Type 'exit' to stop inputting instructions.\n");
    for (int i = 0; i < MAX_INSTRUCTIONS; i++) {
        printf("Instruction %d/32 (5 bytes mov): ", i + 1);
        fflush(stdout);

        uint8_t buf[USER_INSTR_SIZE];
        ssize_t n = read(0, buf, USER_INSTR_SIZE);
        if (n != USER_INSTR_SIZE) {
            puts("Bad input.");
            exit(1);
        }

        if (strncmp((char *)buf, "exit", 4) == 0) {
            puts("Starting execution!");
            break;
        }

        // Must be mov — opcode B8..BF
        if (buf[0] < 0xB8 || buf[0] > 0xBF) {
            puts("Only mov r32, imm32 allowed.");
            exit(1);
        }

        memcpy(p, buf, USER_INSTR_SIZE);
        p += USER_INSTR_SIZE;

        memcpy(p, exit_mine, MINE_SIZE);
        p += MINE_SIZE;
    }


    printf("Start execution from which instruction? ");
    fflush(stdout);

    char input[32];
    read(0, input, sizeof(input) - 1);
    input[31] = '\0';

    int32_t index = atoi(input); 

    // Check if index is within bounds
    if (index < 0) {
        puts("Invalid instruction index.");
        exit(1);
    }
    
    // Calculate starting address with bounds checking
    void *start = mem + (((int64_t)index * LINE_SIZE) % TOTAL_SIZE);

    puts("Executing...");
    ((void(*)())start)();

    return 0;
}
