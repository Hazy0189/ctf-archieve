#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void clear_screen() {
    printf("\x1B[2J");
    printf("\x1B[%d;%dH", 0, 0);
}

void show_error(const char *msg) {
    printf("\n\x1B[1;31m[-] %s\x1B[1;34m\n", msg);
}

unsigned long read_number() {
    char input[32] = {0};
    read(0, input, 31);
    return strtoul(input, NULL, 0);
}

void show_banner() {
    puts("\n\n\n\n                       ");
}

void show_banana() {
    printf("\x1B[1;33m\n[!] You chose: \n                 \x1B[0m");
}

void show_rocket() {
    printf("\x1B[1;37m\n[!] You chose: \n                                       \x1B[0m");
}

void show_mushroom() {
    printf("\x1B[1;31m\n[!] You chose: \n\n        \x1B[0m");
}

void custom_power_up() {
    char input[32] = {0};
    printf("\n\x1B[1;33m[!] Enter name for your Power Up: ");
    read(0, input, 19);
    puts("\n          ");
    printf("\n\x1B[1;33m[!] You start the race with: ");
    printf(input); // format string vulnerability
}

void race_game() {
    const char *directions[2] = {"LEFT", "RIGHT"};
    char input[2] = {0};
    char decision[2] = {0};
    char buffer[72] = {0};

    printf("\x1B[1;34m\n\n[*] There are 7 some turns (Left of Right), turn accordingly to avoid crashing!\n\n");

    for (int i = 0; i <= 6; ++i) {
        memset(input, 0, sizeof(input));
        srand(time(0));
        int dir = rand() % 2;
        printf("\n[!] Warning! %s turn ahead: ", directions[dir]);
        read(0, input, 2);
        if (input[0] != directions[dir][0]) {
            putchar('\n');
            show_error("WE CRASHED AND LOST THE RACE!\n");
            exit(1);
        }
        printf("\n\x1B[1;32m[+] Nice!\n\x1B[1;34m");
    }

    printf("\n[!] You are second! Do you want to use your Power Up?? (y/n)\n\n> ");
    read(0, decision, 2);

    memset(buffer, 0, sizeof(buffer));
    printf("\n\x1B[1;32m[+] BOOM! You finished 1st!!!\n\n");
    printf("[*] Please tell us a few things about your victory: ");
    read(0, buffer, 136); // overflow if local buffer < 136 in real stack
}

void choose_power_up() {
    printf("[!] Choose power up: \n\n");
    printf("1. Banana peel\n");
    printf("2. Rocket\n");
    printf("3. Mushroom\n");
    printf("4. Other\n\n");

    unsigned long choice = read_number();

    if (choice == 4) {
        custom_power_up();
    } else if (choice <= 4) {
        switch (choice) {
            case 1:
                show_banana();
                break;
            case 2:
                show_rocket();
                break;
            case 3:
                show_mushroom();
                break;
            default:
                show_error("Invalid Power Up! Are you trying to cheat?!\n");
                exit(1);
        }
    } else {
        show_error("Invalid Power Up! Are you trying to cheat?!\n");
        exit(1);
    }

    race_game();
}

int main(int argc, char **argv, char **envp) {
    show_banner();
    choose_power_up();
    return 0;
}
