#include <cstdio>
#include <cstring>
using namespace std;

int N, cache[101][10][1024];

int stepN(int a, int b, int c) {
	if (a == N && b == 0) return 0; 
	if (a == 1 && c == 1023) return 1; 
	if (a == 1) return 0;
	if (b < 0 || b > 9) return 0;

	int& res = cache[a][b][c];
	if (res != -1) return res;

	res = 0;
	if (b == 0) {
		res = stepN(a - 1, b + 1, c | ( 1 << 1)) % 1000000000;
	}
	else if (b == 9) {
		res = stepN(a - 1, b - 1, c|(1<<8)) % 1000000000;
	}
	else {
		res = stepN(a - 1, b - 1, c | (1<<(b-1))) % 1000000000;
		res += stepN(a - 1, b + 1, c|(1<<(b+1))) % 1000000000;
	}
    
	return res % 1000000000;
}

int main() {

	memset(cache, -1, sizeof(cache[0][0][0]) * 101 * 10 * 1024);
	scanf("%d", &N);
	int ans = 0;
	for (int i = 0; i < 10; ++i) {
		ans += stepN(N, i, 1 << i) % 1000000000;
		ans %= 1000000000;
	}
	printf("%d", ans);
	
	return 0;
}
