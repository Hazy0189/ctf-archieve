#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


void list_directory(char *path) {
	DIR *directory;
	struct dirent *dir_entry;
	directory = opendir(path);

	if (directory != NULL) {
		while ((dir_entry = readdir(directory))) {
			if (dir_entry->d_name[0] == '.') {
				;
			} else if (dir_entry->d_type == DT_DIR) {
				printf("%s/\n", dir_entry->d_name);
			} else {
				puts(dir_entry->d_name);
			}
		}
		closedir(directory);
		return;
	} else {
		puts("You're listing a non-existing category! ");
		return;
	}
}

void read_file(char *category) {
        char filename [2048];
        char path[4096];
	char buffer[4096];
        FILE *fd;
	int n;
        struct stat file_stat;

        printf("Filename? ");
        scanf(" %[^\n]", filename);
        if (strstr(filename, "..")) {
                puts("Hacker caught!");
                exit(0xdead);
        }

        sprintf(path, "%s/%s", category, filename);

        fd = fopen(path, "r");
	if (!fd) {
                puts("You're opening a non-existing archive!");
                return;
        }

	while ((n = fread(buffer, 1, sizeof(buffer), fd))) {
		fwrite(buffer, 1, n, stdout);
	}

        function_exit:
        fclose(fd);
        return;
}




int main() {
	char category[2048] = {'.',};
	char ops;


	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	puts("Welcome to Fishbaby's Library! Browse technical documentation and more online.");
	puts("If you would like a specific book added to the bookshelf, please contact the administrator.");
	puts("Do *NOT* access resources in the 'classified/' category, as it contains restricted files.");
	puts("Some security measures are taken to protect these important files against hackers.");


	while (1) {
		puts("Options:");
		puts("    [L]: List all category");
		puts("    [D]: List content of a category");
		puts("    [S]: Set a category");
		puts("    [C]: Clear out selected category");
		puts("    [R]: Read a file");
		puts("    [E]: Exit");
		printf("Your choice> ");
		scanf(" %c", &ops);

		switch (ops) {
		case 'L':
			list_directory(".");
			break;
		case 'D':
			list_directory(category);
			break;
		case 'S':
			printf("Which category interests you? ");

			memset(category, 0x00, sizeof(category));
			scanf(" %[^\n./]", category);

			if (strstr(category, "..") || strstr(category, "/") || strstr(category, "classified")) {
				puts("Hacker!");
				exit(0xdead);
			}

			break;
		case 'C':
			memset(category, 0x00, sizeof(category));
			puts("Category have been reset");
			break;
		case 'R':
			read_file(category);
			break;
		case 'E':
			puts("Take knowledge with you wherever you go - today\'s reading shapes tomorrow\'s journey!");
			puts("Bye!");
			exit(0);
		}
	}
}
