#include <stdio.h>
#include <math.h>
#include <locale.h>

/* 
   Chinese Stream
   ''
   #include <locale.h>
   setlocale(LC_ALL, "chs");
   wprint(L"中文\n");
   '' 
*/

void basic_print() {
	printf("%d\n", 1+2);
	printf("%.2f\n", 8.0/5.0);
	//printf("%.2f\n", 8/5);
	//printf("%d\n", 8.0/5.0);
	printf("%.8f\n", 1+2*sqrt(3)/(5.0-0.1));
}

void addition() {
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n", a+b);
}

void get_cylindrical_area() {
	const float pi = acos(-1.0);
	float r, h, area;
	scanf("%f%f", &r, &h);
	area = 2 * pi * r * r + 2 * pi * r * h;
	printf("Area = %.3f\n", area);
}

void reverse_three_figures() {
	int n, r;
	scanf("%d", &n);
	r = (n % 10) * 100 + (n / 10 % 10) * 10 + n / 100;
	printf("%d\n", r);
	printf("%03d\n", r);
}

void swap_variables() {
	int x, y;
	scanf("%d%d", &x, &y);
	printf("%d %d\n", y, x);
}

void chick_and_rabbit() {
	int m, n;
	scanf("%d%d", &n, &m);

	int c, r;
	r = (m - 2 * n) / 2;
	c = n - r;

	if (m % 2 == 1 || r < 0 || c < 0)
		printf("No answer\n");
	else
		printf("%d %d\n", c, r);
}

void sort_three_numbers() {
	int a, b, c, tmp;
	scanf("%d%d%d", &a, &b, &c);
	if (a > b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	if (a > c) {
		a = a + c;
		c = a - c;
		a = a - c;
	}
	if (b > c) {
		b^=c^=b^=c;
	}
	printf("%d %d %d\n", a, b, c);
}

int main() {

	setlocale(LC_ALL, "chs");
	wprintf(L"\n1.1 算数表达式\n");
	//basic_print();

	wprintf(L"\n1.2 变量及其输入\n");
	//addition();
	//get_cylindrical_area();

	wprintf(L"\n1.3 顺序结构程序设计\n");
	//reverse_three_figures();
	//swap_variables();	

	wprintf(L"\n1.4 分支结构程序设计\n");
	//chick_and_rabbit();
	//sort_three_numbers();

	return 0;
}