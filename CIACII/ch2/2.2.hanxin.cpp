#define LOCAL
#include <stdio.h>

int main() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int a, b, c, case_num = 0;
	while ((scanf("%d", &a) == 1) && (scanf("%d", &b) == 1) && (scanf("%d", &c) == 1)) {
		int num = 10;
		for (; num < 101; ++num) {
			if ((num % 3 == a) && (num % 5 == b) && (num % 7 == c)) {
				printf("Case %d: %d\n", ++case_num, num);
				break;
			}
		}
		if (num > 100)
			printf("Case %d: %s\n", ++case_num, "No answer");
	}
	return 0;
}