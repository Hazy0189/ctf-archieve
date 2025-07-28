#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_GLASSES 16
#define GLASS_SIZE 0x58
#define READ_SIZE 0x59

void show_banner();
void setup_io();
void clear_screen();
void show_error(const char *msg);
unsigned long read_number();

void *glasses[MAX_GLASSES];

int main() {
    unsigned char glass_count = 0;
    unsigned long option, index;
    
    setup_io();
    show_banner();
    memset(glasses, 0, sizeof(glasses));

    while (1) {
        printf("Menu: \n\n");
        option = read_number();

        if (option == 4) {
            printf("\nChoose glass: ");
            index = read_number();
            if (index >= glass_count) {
                show_error("This glass is unavailable!");
                continue;
            }
            if (glasses[index]) {
                printf("\nGlass content: ");
                write(1, glasses[index], GLASS_SIZE);
                putchar('\n');
            } else {
                show_error("Cannot view empty glass!");
            }
        } else if (option == 3) {
            printf("\nChoose glass to customize: ");
            index = read_number();
            if (index >= glass_count) {
                show_error("This glass is unavailable!");
                continue;
            }
            if (glasses[index]) {
                printf("\nAdd another drink: ");
                read(0, glasses[index], READ_SIZE);
                putchar('\n');
            } else {
                show_error("Cannot customize empty glass!");
            }
        } else if (option == 2) {
            printf("\nChoose glass to empty: ");
            index = read_number();
            if (index >= glass_count) {
                show_error("This glass is unavailable!");
                continue;
            }
            if (glasses[index]) {
                free(glasses[index]);
                glasses[index] = NULL;
                puts("\nGlass is empty now!\n");
            } else {
                show_error("This glass is already empty!");
            }
        } else if (option == 1) {
            if (glass_count > 15) {
                show_error("You cannot take any more glasses!");
                exit(69);
            }
            glasses[glass_count] = calloc(1, GLASS_SIZE);
            if (glasses[glass_count]) {
                ++glass_count;
                printf("\nHere is your refreshing juice!\n\n");
            } else {
                show_error("Something went wrong with the juice!");
            }
        } else {
            show_error("Have a great day!\n");
            exit(69);
        }
    }

    return 0;
}

void setup_io() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    alarm(600);  // 0x258 seconds = 600
}

void show_banner() {
    puts("\x1B[1;33m");
    clear_screen();
    puts((char *)0x2030);  // assumes static emoji banner
    puts("It's too hot.. Drink a juice Jumpio.. Or 2.. Or 10!\n");
}

void clear_screen() {
    printf("\x1B[2J");
    printf("\x1B[0;0H");
}

void show_error(const char *msg) {
    printf("\n\x1B[1;31m%s\x1B[1;33m\n\n", msg);
}

unsigned long read_number() {
    char buf[0x20] = {0};
    read(0, buf, sizeof(buf) - 1);
    return strtoul(buf, NULL, 0);
}
