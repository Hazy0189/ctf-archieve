#include <stdio.h>

int main(){
	int N, i, y, z, sum1, sum2, sum;
	scanf("%d", &N);
	for (z = 0; z <= N; z++){
	sum = 1;
	for (i = 1; i <= z; i++){
		sum *= i; 
	}

	for (i = 0; i <= z; i++){
		sum1 = 1;
		for (y = 1; y <= (z-i); y++){
			sum1 *= y;
		}
		for (y = 1; y <= i; y++){
			sum1 *= y;
		}
		if (i == z) printf("%d\n", sum/sum1);
		else printf("%d ", sum/sum1);
	}
	
	}
	return 0;
}
