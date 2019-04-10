#include <stdio.h>

int main() {
	int h, d, u;
	for (int i = 100; i < 1000; ++i) {
		h = i / 100;
		d = i / 10 % 10;
		u = i % 10;
		if (h*h*h + d*d*d + u*u*u == i)
			printf("%d\n", i);
	}
	return 0;
}