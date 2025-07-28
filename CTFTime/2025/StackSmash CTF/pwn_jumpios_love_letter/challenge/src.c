#define MAX_NOTES 20

typedef struct Note {
    char* author;
    char* password;
    char* content;
    bool  is_protected;
} Note;

Note* notes[MAX_NOTES];
int note_count = 0;
FILE* fp;

int read_int() {
    char input[32] = {0};
    read(0, input, 0x20);
    return strtoll(input, NULL, 10);
}

void create_note() {
    if (note_count >= MAX_NOTES) {
        puts("Maximum Notes taken!");
        puts("Delete some to free up space!");
        return;
    }

    Note* note = malloc(sizeof(Note));
    note->author = malloc(8);
    note->content = malloc(0x100);
    note->is_protected = 0;
    note->password = NULL;

    puts("What is the nickname of the author of this note?");
    printf("> ");
    fgets(note->author, 7, stdin);

    puts("Input your note:");
    printf("> ");
    fgets(note->content, 255, stdin);

    puts("Do you want to password-protect this note?(y/n)");
    printf("> ");
    char choice[6] = {0};
    read(0, choice, 6);

    if (choice[0] == 'y') {
        note->is_protected = 1;
        note->password = malloc(8);
        puts("Enter a small password");
        printf("> ");
        fgets(note->password, 7, stdin);
    }

    notes[note_count++] = note;
    printf("Note %d taken successfully!\n\n", note_count);
}

void change_note() {
    int index;
    do {
        puts("Which note do you want to change?");
        printf("> ");
        index = read_int();
        putchar('\n');
    } while (index > MAX_NOTES);

    Note* note = notes[index - 1];
    if (!note) {
        puts("Note does not exist!");
        return;
    }

    char input_pass[8];

    if (!note->is_protected || (printf("Enter password: "), fgets(input_pass, 8, stdin), !strcmp(input_pass, note->password))) {
        printf("Change Author: ");
        fgets(note->author, 7, stdin);
        printf("Change Content: ");
        fgets(note->content, 256, stdin);
        printf("Note %d changed successfully!\n\n", index);
    } else {
        puts("Incorrect password!");
        putchar('\n');
    }
}

void print_note() {
    int index;

    do {
        puts("Which note do you want to see?");
        printf("> ");
        index = read_int();
        putchar('\n');
    } while (index > MAX_NOTES);

    Note* note = notes[index - 1];
    if (!note) {
        puts("Note does not exist!");
        return;
    }

    char input_pass[8];

    if (!note->is_protected || (printf("Enter password: "), fgets(input_pass, 8, stdin), !strcmp(input_pass, note->password))) {
        puts("----------------------");
        printf("Author: ");
        printf(note->author);  // ⚠️ format string vuln
        printf("Note: %s", note->content);
        puts("----------------------");
    } else {
        puts("Incorrect password!");
        putchar('\n');
    }
}

void delete_note() {
    int index;

    do {
        puts("Which note do you want to delete?");
        printf("> ");
        index = read_int();
        putchar('\n');
    } while (index > MAX_NOTES);

    Note* note = notes[index - 1];
    if (!note) {
        puts("Note does not exist!");
        return;
    }

    char input_pass[8];

    if (!note->is_protected || (printf("Enter password: "), fgets(input_pass, 8, stdin), !strcmp(input_pass, note->password))) {
        free(note->password);
        free(note->author);
        free(note->content);
        free(note);

        notes[index - 1] = NULL;

        // Shift notes to maintain array integrity
        for (int i = index; i < MAX_NOTES; i++) {
            notes[i - 1] = notes[i];
        }

        note_count--;
        printf("Note %d deleted successfully!\n\n", index);
    } else {
        puts("Incorrect password!");
        putchar('\n');
    }
}

void save_notes() {
    char* buffer = malloc(0x15A8);  // 5544 bytes
    int offset = 0;

    fp = fopen("notes.md", "w+");

    for (int i = 0; i < MAX_NOTES; i++) {
        Note* note = notes[i];
        if (!note) break;

        offset += sprintf(&buffer[offset], "----------------------\n");
        offset += sprintf(&buffer[offset], "## Author: %s", note->author);
        offset += sprintf(&buffer[offset], "### Note: %s", note->content);
        offset += sprintf(&buffer[offset], "----------------------\n\n");
    }

    fwrite(buffer, 1, strlen(buffer), fp);

    puts("Anything else you would like to add?");
    printf("> ");
    read(0, buffer + 5280, 0x1F4);  // 500 bytes
    fwrite(buffer + 5280, 1, strlen(buffer + 5280), fp);

    free(buffer);
    fclose(fp);

    puts("Saved notes successfully in file: notes.md");
}

void show_banner() {
    printf("\x1B[1;31m[!] I will help you write a Love Letter to Princess Pomegranate:\x1B[0m\n\n        ");
}

int menu() {
    puts("---------------");
    puts("1 - Create Note");
    puts("2 - Change Note");
    puts("3 - Print Note");
    puts("4 - Delete Note");
    puts("5 - Save Notes");
    puts("6 - Exit");
    puts("---------------\n");
    printf("Choice: ");
    return read_int();
}

int main() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(_bss_start, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    show_banner();

    while (1) {
        switch (menu()) {
            case 1:
                create_note();
                break;
            case 2:
                change_note();
                break;
            case 3:
                print_note();
                break;
            case 4:
                delete_note();
                break;
            case 5:
                save_notes();
                break;
            case 6:
                exit(0);
            default:
                puts("Select a valid option");
                break;
        }
    }

    return 0;
}
