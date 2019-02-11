#include <cstdio>
#include <cstring>
using namespace std;

int arr[16][16];

int main() {
	
	memset(arr, 0, sizeof(arr[0][0])*16*16);

	int N = 0, M = 0, K = 0;
	scanf("%d %d %d", &N, &M, &K);

	if (K == 0) {
		for (int i = 0; i < M; ++i) arr[0][i] = 1;
		for (int i = 0; i < N; ++i) arr[i][0] = 1;
		for (int i = 1; i < N; ++i) {
			for (int j = 1; j < M; ++j) 
				arr[i][j] = arr[i][j-1] + arr[i-1][j];
		}
		printf("%d", arr[N - 1][M - 1]);
	}
	else {
		int ky = (K - 1) / M;
		int kx = (K - 1) % M;
		for (int i = 0; i <= kx; ++i) arr[0][i] = 1;
		for (int i = 0; i <= ky; ++i) arr[i][0] = 1;
		for (int i = 1; i <= ky; ++i) {
			for (int j = 1; j <= kx; ++j)
				arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
		}
		for (int i = kx + 1; i < M; ++i) arr[ky][i] = 1;
		for (int i = ky + 1; i < N; ++i) arr[i][kx] = 1;
		for (int i = ky+1; i < N; ++i) {
			for (int j = kx + 1; j < M; ++j)
				arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
		}
		printf("%d", arr[ky][kx] * arr[N - 1][M - 1]);
	}

	return 0;
}
