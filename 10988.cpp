#include <cstdio>
#include <cstring>
using namespace std;

char word[101];

int main() {

	memset(word, -1, sizeof(word));
	scanf("%s", word);

	int num = 0;
	for (int i = 0; i < 101; ++i) {
		if (word[i] == 0) break;
		num = i;
	}
	int cnt = 0;
	while (cnt<num) {
		if (word[num] != word[cnt]) {
			cnt = -1;
			break;
		}
		--num, ++cnt;
	}

	if (cnt == -1) printf("0");
	else printf("1");
	
	return 0;
}
