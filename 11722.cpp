#include <cstdio>
using namespace std;

int input[1001], cache[1001];

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		scanf("%d", &input[i]);
	}

	int res = 0;
	for (int i = 0; i < N; ++i) {
		cache[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (input[j] > input[i] && cache[i]<cache[j]+1) { 
				cache[i] = cache[j] + 1;
			}
		}
		if (res < cache[i])
			res = cache[i];
	}
	
	printf("%d", res);

	return 0;
}
