#include <cstdio>
#include <cstring>
using namespace std;

long long dp[11][2001];
int n, m;

long long calc(int a, int b) { //a:뽑을 숫자의 갯수, b:숫자의 제한

	long long& res = dp[a][b];
	if (res != -1) return res;

	if (a == 1) res = b;
	else if ((1<<(a-1))>b) res = 0;
	else if ((1 << (a - 1))==b) res = 1;
	else {
		res = calc(a, b - 1)+calc(a-1,b/2);
	}

	return res;
}

int main() {
	int T = 0;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		memset(dp, -1, sizeof(dp[0][0]) * 11 * 2001);
		scanf("%d %d", &n, &m);
		printf("%llu\n",calc(n,m));
	}
	return 0;
}
