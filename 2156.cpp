#include <cstdio>
using namespace std;

#define MAX(X,Y) ((X)>(Y)?(X):(Y))
int N,input[10001], cache[10001][4];

int find(int a, int b) {
	if (a < 0 || a >= N) return 0;

	int& res = cache[a][b];
	if (res != -1) return res;
	
	res = 0;
	if (b == 0 || b==2){
		int tmp1 = find(a + 1, 0);
		int tmp2 = find(a + 1, 1) + input[a];
		res = MAX(tmp1, tmp2);
	}
	else if (b == 1) {
		int tmp1 = find(a + 1, 2);
		int tmp2 = find(a + 1, 3) + input[a];
		res = MAX(tmp1, tmp2);
	}
	else if (b == 3) {
		res = find(a + 1, 2);
	}

	return res;
}


int main() {

	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		scanf("%d", &input[i]);
		for (int j = 0; j < 4; ++j)cache[i][j] = -1;
	}
	int max1 = find(0, 1);
	int max2 = find(0, 2);
	int max3 = find(0, 3);
	
	max1 = MAX(max1, max2);
	max1 = MAX(max1, max3);

	printf("%d", max1);

	return 0;
}
