#include <stdio.h>
#include <string.h>

void merge(char *arr, int low, int mid, int high) {
    int i = low, j = mid + 1, index = 0, size = high - low + 1;
    char temp[size];
    while (i <= mid || j <= high) {
        temp[index++] = (j > high || (i <= mid && arr[i] < arr[j])) ? arr[i++] : arr[j++];
    }
    for (i = 0; i < size; i++) arr[low + i] = temp[i];
}


void mergesort(char *arr, int low, int high){
	if (low < high){
		int mid = low + ((high-low)/2);
		mergesort(arr, low, mid);
		mergesort(arr, mid+1, high);
		merge(arr, low, mid, high);
	}
}

int main(){
	char list[10000][100];
	char list2[10000][100];
	int i, y, z;
	char ans[10][100];
	FILE *txt = fopen("wordlist.txt", "r");
	for (i = 0; !feof(txt); i++){
		fscanf(txt, "%s\n", list[i]);
		strcpy(list2[i], list[i]);
	}
	for (y = 0; y < i; y++){
		mergesort(list2[y], 0, strlen(list2[y])-1);
	}
	for (z = 0; z < 10; z++){
		scanf(" %s", ans[z]);
		mergesort(ans[z], 0, strlen(ans[z])-1);
		for (y = 0; y < i; y++){
			if (strcmp(list2[y], ans[z]) == 0){
				printf("%s %s\n", ans[z], list[y]);
				strcpy(ans[z], list[y]);
				break;
			}
		}
	}
	printf("Answer: ");
	for (z = 0; z < 10; z++){
		printf("%s,", ans[z]);
	}
	return 0;
}
