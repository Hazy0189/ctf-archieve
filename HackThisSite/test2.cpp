#include <stdio.h>

char map[101][101];
int move[4][2] = {{1,0},{0,-1},{0,1},{-1,0}};
int minimal(int a, int b){
	if (b == -1) return a;
	else if (a == -1) return b;
	return (a < b) ? a : b;
}
int minmaze(int x, int y, int N, int min){
	int answer = -1;
	if (x < 0 || x >= N || y < 0 || y >= N || map[x][y] == '#')
		return -1;
	if (map[x][y] == 'E') return min;
	map[x][y] = '#';
	for (int i = 0; i < 4; i++){
		answer = minimal(answer, minmaze(x+move[i][0], y+move[i][1], N, min+1));
	}
	return answer;
}

int main(){
	int N, i, y, cx, cy;
	scanf("%d", &N);
	for (i = 0; i < N; i++){
		for (y = 0; y < N; y++){
			if (y == 0) scanf(" %c", &map[i][y]);
			else scanf("%c", &map[i][y]);
			if (map[i][y] == 'S'){
				cx = i;
				cy = y;
			}
		}
	}
//	for (i = 0; i < N; i++){
//		for (y = 0; y < N; y++){
//			printf("%c", map[i][y]);
//		}
//		printf("\n");
//	}
	printf("%d", minmaze(cx, cy, N, 0));
	return 0;
}
