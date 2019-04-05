#include <stdio.h>
#include <math.h>

int main() {
	const double PI = 3.1415926;
	double n;
	scanf("%lf", &n);
	printf("%f %f\n", sin(n * PI / 180), cos(n * PI / 180));
	return 0;
}