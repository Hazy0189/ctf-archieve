#include <stdio.h>
#include <string.h>

struct vocal {
	char word[100];
	int con;	
};

int countv(char *word){
	int i, value;
	value = 0;
	for (i = 0; word[i]!='\0'; i++){
		if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u'){
			value++;
		}
	}
	return value;
}

void swap(struct vocal *a, struct vocal *b){
	struct vocal temp = *a;
	*a = *b;
	*b = temp;
}

int partition(struct vocal *arr, int low, int high){
	int i, j;
	for (i = j = 0; i < high; i++){
		if (arr[i].con > arr[high].con) swap(&arr[i], &arr[j++]);
		else if (arr[i].con == arr[high].con && strcmp(arr[i].word, arr[high].word) < 0) swap(&arr[i], &arr[j++]);
	}
	swap(&arr[i], &arr[j]);
	return j;
}

void quicksort(struct vocal *arr, int low, int high){
	if (low < high){
		int mid = partition(arr, low, high);
		quicksort(arr, low, mid-1);
		quicksort(arr, mid+1, high);
	}
}

int main(){
	int N, i;
	scanf("%d", &N);
	struct vocal test[N+1];
	for (i = 0; i < N; i++){
		scanf(" %s", test[i].word);
		test[i].con = countv(test[i].word);
	}
	quicksort(test, 0, N-1);
	for (i = 0; i < N; i++){
		printf("%s %d\n", test[i].word, test[i].con);
	}
	return 0;
	
}
