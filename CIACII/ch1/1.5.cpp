#include <stdio.h>

int main() {
	double n, m;
	scanf("%lf", &n);
	m = n * 95.;
	if (m > 300) 
		m *= 0.85;
	printf("%.2lf\n", m);
	return 0;
}