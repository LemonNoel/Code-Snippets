#include <stdio.h>

int main() {
	int a, b, c;
	while((scanf("%d", &a) == 1) && (scanf("%d", &b) == 1) && (scanf("%d", &c) == 1) && (a || b || c)) {
		char format[10] = {0};
		sprintf(format, "%%.%dlf\n", c);
		printf(format, a * 1.0 / b);
	}
	return 0;
}