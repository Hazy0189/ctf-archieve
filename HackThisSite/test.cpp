#include <stdio.h>
#include <string.h>
int main(){
	int N, i, j, index, index2, valid, checkstart[N*N+1][2];
	scanf("%d", &N);
	char map[N+1][N+1];
	char word[N+1];
	index = 0;
	index2 = 0;
	valid = 0;
	scanf(" %s", word);
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			scanf(" %c", &map[i][j]);
			if (map[i][j] == word[0]){
				checkstart[index2][0] = i;
				checkstart[index2++][1] = j;
			}
		}
	}
	for (i = 0; i < index2; i++){
		for (j = checkstart[i][0]; j < N; j++){
			if (map[j][checkstart[i][1]] == word[index]) index++;
			else if (index == strlen(word)){
				valid = 1;
				break;	
			} else {
				index = 0;
				break;
			}
		}
		if (index == strlen(word)){
			valid = 1;
			break;
		}
		if (valid) break;

		for (j = checkstart[i][0]; j >= 0; j--){
			if (map[j][checkstart[i][1]] == word[index]) index++;
			else if (index == strlen(word)){
				valid = 1;
				break;	
			} else {
				index = 0;
				break;
			}
		}
		if (index == strlen(word)){
			valid = 1;
			break;
		}
		if (valid) break;
		
		for (j = checkstart[i][1]; j < N; j++){
			if (map[checkstart[i][0]][j] == word[index]) index++;
			else if (index == strlen(word)){
				valid = 1;
				break;	
			} else {
				index = 0;
				break;
			}
		}
		if (index == strlen(word)){
			valid = 1;
			break;
		}
		if (valid) break;

		for (j = checkstart[i][1]; j >= 0; j--){
			if (map[checkstart[i][0]][j] == word[index]) index++;
			else if (index == strlen(word)){
				valid = 1;
				break;	
			} else {
				index = 0;
				break;
			}
		}
	}
	if (valid) printf("YES\n");
	else printf("NO\n");
	return 0;
}
