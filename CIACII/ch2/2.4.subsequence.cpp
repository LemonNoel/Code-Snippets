#include <stdio.h>

int main() {
	int n, m, case_num = 1;
	while ((scanf("%d", &n) == 1) && (scanf("%d", &m) == 1) && (n || m)) {
		double sum = 0;
		for (int i = n; i <= m; ++i)
			sum += (1. / i / i);
		printf("Case %d: %.5lf\n", case_num++, sum);
	}
	return 0;
}