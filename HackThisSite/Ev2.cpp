#include <stdio.h>

int binarySearch(long long int prefixSum[], int start, int end, long long int M) {
    if (start > end) {
        return -1;
    }

    int mid = (start + end) / 2;

    if (prefixSum[mid] <= M) {
        int result = binarySearch(prefixSum, mid + 1, end, M);
        return (result != -1) ? result : mid;
    } else {
        return binarySearch(prefixSum, start, mid - 1, M);
    }
}


int main(){
    int N, Q, i, j;
    scanf("%d", &N);
    long long int Ai[N+1], prefixSum[N+3];
    
    prefixSum[0] = 0;
    for (i = 0; i < N; i++){
        scanf(" %lld", &Ai[i]);
        prefixSum[i + 1] = prefixSum[i] + Ai[i];
    }

    scanf(" %d", &Q);    
    for (i = 0; i < Q; i++){
        long long int M, ans;
        scanf(" %lld", &M);
        ans = -1;
        for (j = 0; j < N; j++) {
            int endIndex = binarySearch(prefixSum, j, N, prefixSum[j] + M);
            if (endIndex != -1) {
                int length = endIndex - j + 1;
                if (ans == -1 || length > ans) {
                    ans = length;
                }
            }
        }
        printf("Case #%d: %lld\n", i+1, ans-1);
    }
    return 0;
}

