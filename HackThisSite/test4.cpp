#include <stdio.h>

int main(){
	int sum, num, ans;
	char next;
	FILE *file = fopen("testdata.txt", "r");
	sum = 0;
	while (!feof(file)){
		if(fscanf(file, "%d%c", &num, &next) == 2) {
			printf("%d%c", num, next);
			sum += num;
			if(next == '\n') {
				ans = (ans < sum) ? sum : ans;
				sum = 0;
			}
		}
	}
	fclose(file);
	printf("%d", ans);
	return 0;
}
