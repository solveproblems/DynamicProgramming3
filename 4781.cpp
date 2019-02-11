#include <cstdio>
#include <cstring>
using namespace std;

#define MAX(A,B) ((B)<(A)?(A):(B))
#define MIN(A,B) ((B)>(A)?(A):(B))

struct candy {
	int cal, price;
	candy() :cal(0), price(0) {}
};

struct candy candies[5001];
int n, cache[10001], cheap;
float m;

int calcCal(int money) {

	if (money < cheap) return 0;

	int& res = cache[money];
	if (res!= -1) return res;
	
	res = 0;

	for (int i = 0; i < n; ++i) {
		if (money - candies[i].price >= 0) {
			res = MAX(res, calcCal(money - candies[i].price) + candies[i].cal);
		}
	}

	return res;

}

int main() {
	
	while(1){
		memset(cache, -1, sizeof(cache));
		scanf("%d %f", &n, &m);
		if (n == 0 && m == 0.00) break;
		cheap = (int)(m*100);
		for (int i = 0; i < n; ++i) {
			float tmp = 0.00;
			scanf("%d %f", &candies[i].cal, &tmp);
			candies[i].price = (int)(tmp * 100);
			cheap = MIN(candies[i].price, cheap);
		}
		printf("%d\n", calcCal((int)(m * 100)));
	} 

	return 0;
}
