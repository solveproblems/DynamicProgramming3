#include <cstdio>
#include <cstring>
using namespace std;

#define MAX(a,b) ((a)<(b)?(b):(a))

struct job {
	int time, pay;
	job() : time(0), pay(0) {}
	job(int a, int b) : time(a), pay(b) {}
};

struct job jobs[16];
int n, cache[16];

int calc(int ord) {
	if (n == 1) {
		if (jobs[ord].time == 1) return jobs[ord].pay;
		return 0;
	}
	if (ord < 0 || ord >= n) return 0;
	
	int& res = cache[ord];
	if (res != -1) return res; 

	res = 0;

	if (ord+jobs[ord].time > n) {
		res = calc(ord+1);
	}
	else {
		res = MAX(calc(ord+1), calc(ord +jobs[ord].time) + jobs[ord].pay);
	}

	return res;
}

int main() {

	memset(cache, -1, sizeof(cache));

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a = 0, b = 0;
		scanf("%d %d", &a, &b);
		jobs[i].time = a;
		jobs[i].pay = b;
	}
	
	printf("%d", calc(0));

	return 0;
}
