#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

// Global variables
char g_completed = 0;
__int64 g_coins = 0;
struct termios g_old_termios;
struct termios g_new_termios;

// Function prototypes
void set_terminal_mode(int enable_raw);
unsigned long read_number();
void buy_flowers();
void render_ui(int skip_clear);
unsigned long show_special_card();
unsigned long initialize();
void cleanup_terminal();

// Utility Functions
void set_terminal_mode(int enable_raw) {
    if (enable_raw) {
        tcgetattr(0, &g_old_termios);
        memcpy(&g_new_termios, &g_old_termios, sizeof(struct termios));
        g_new_termios.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(0, 0, &g_new_termios);
    } else {
        tcsetattr(0, 0, &g_old_termios);
    }
}

unsigned long read_number() {
    char buffer[0x20] = {0};
    read(0, buffer, 31);
    return strtoul(buffer, NULL, 10);
}

void render_ui(int skip_clear) {
    system("clear");
    puts("â");  // likely some kind of emoji or box art
    if (!skip_clear) {
        puts("\n\n\n");
    }
    puts("      ");
}

unsigned long show_special_card() {
    char ch;
    int fd = open("./flag.txt", 0);
    if (fd < 0) {
        perror("\nError opening flag.txt. Please contact an Administrator.\n");
        exit(1);
    }
    while (read(fd, &ch, 1) > 0) {
        putchar(ch);
    }
    close(fd);
    return 0;
}

void buy_flowers() {
    char flower_choice[5];
    unsigned long quantity;

    set_terminal_mode(0);
    printf("\n\033[1;32m[!] You collected \033[1;33m%ld\033[1;32m \033[0m", g_coins);
    
    fgets(flower_choice, 3, stdin);
    
    printf("\n\033[1;34mHow many bouquets?\n\n> ");
    quantity = read_number();

    if (flower_choice[0] == '1') {
        g_coins -= 9 * quantity;
        if (g_coins) {
            printf("\n\033[1;32m[+] You chose \033[1;37mWhite Roses\033[1;32m! They\n");
            g_coins -= 9 * quantity;
            exit(0);
        }
        printf("\n\033[1;31m[-] Not enough coins!\n");
        exit(1);
    }

    if (flower_choice[0] == '2') {
        g_coins -= 1337 * quantity;
        if (g_coins) {
            printf("\n\033[1;32m[+] You chose \033[1;35mPink Roses\033[1;32m, \033[1;35mPrincess Pomegranate's\033[1;32m favorite! "
                   "We also add a special card for such occasions!\n\n\033[0m");
            show_special_card();
            exit(0);
        }
        printf("\n\033[1;31m[-] Not enough coins!\n");
        exit(1);
    }

    printf("\n\033[1;31m[-] We don't serve those!\n\n");
    exit(1);
}

int main(int argc, char **argv, char **envp) {
    char input;

    set_terminal_mode(1);
    while (1) {
        render_ui(0);
        printf("\n\033[1;34m[*] Press 'W' to jump and collect coins! Coins: [\033[1;33m%ld\033[1;34m]\033[0m\n", g_coins);
        input = getchar();

        if (input == 'w' || input == 'W') {
            render_ui(1);
            usleep(90000); // 0x15F90
            g_coins++;
        } else if (input == 'q' || input == 'Q') {
            break;
        }

        if (g_coins == 10) {
            buy_flowers();
        }
    }
    set_terminal_mode(0);
    return 0;
}

unsigned long initialize() {
    setvbuf(stdin, 0, _IONBF, 0);
    setvbuf(stdout, 0, _IONBF, 0);
    alarm(4882); // 0x1312
    return 0;
}

void cleanup_terminal() {
    // Placeholder if needed later
}
