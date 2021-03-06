#include <stdio.h>
#include <math.h>
#include <time.h>

void program_2_1() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		printf("%d\n", i);
}

bool is_aabb(int num) {
	if ((num % 10 == num/10 % 10) && (num/100 % 10 == num/1000 % 10))
		return true;
	else
		return false;
} 

void example_2_1() {
	for(int i = floor(sqrt(1000.)) + 1; i < 100; i++) {
		if(is_aabb(i * i))
			printf("%d\n", i * i);
	}
}

void example_2_2() {
	int n;
	scanf("%d", &n);

	long long m = n;
	int num_step = 0;
	while (m > 1) {
		if (m % 2 == 0)
			m /= 2;
		else
			m = 3 * m + 1;
		num_step += 1;
	}
	printf("%d\n", num_step);
}

void example_2_3() {
	double sum = 0;
	for (int i = 0; ; i++) {
		double term = 1. / (i * 2. + 1.);
		if (i % 2 == 0)
			sum += term;
		else
			sum -= term;
		if (term < 10e-6) 
			break; 
	} 
	printf("%f\n", sum);
}

void example_2_4() {
	int n, S = 0;
	scanf("%d", &n);

	//if (n > 25) n = 25;
	long long term = 1;
	for (int i = 1; i <= n; i++) {
		term = term * i % 1000000;
		S = (S + term) % 1000000;
	}
	printf("%d\n", S);
}

void example_2_5() {
	int num, count = 0, sum = 0, min_num = 1001, max_num=0;
	while (scanf("%d", &num) == 1) {
		if (num < min_num) min_num = num;
		if (num > max_num) max_num = num;
		sum += num;
		count += 1;
	}
	printf("%d %d %.3f", min_num, max_num, sum * 1.0 / count);
}

void program_2_10() {
	/*
	#define LOCAL
	#include <stdio.h>

	int main() {
	#ifdef LOCAL
		freopen("data.in", "r", stdin);
		freopen("data.out", "w", stdout);
	#endif
		int x;
		while (scanf("%d", &x) == 1) {
			printf("%d\n", x+1);
		}
		return 0;
	}
	*/
}

void program_2_11() {
	/*
	#include <stdio.h>

	int main() {
		FILE *fin, *fout;
		fin = fopen("data.in", "rb");
		fout = fopen("data.out", "wb");
		int x;
		while (fscanf(fin, "%d", &x) == 1) {
			fprintf(fout, "%d\n", x+1);
		}
		fclose(fin);
		fclose(fout);
		return 0;
	}
	*/
}

void example_2_6() {
	int num, x, case_num = 1;
	while (scanf("%d", &num) == 1 && num != 0) {
		int count = 0, sum = 0.0, min = 1001, max = -1001;
		for (int i = 0; i < num; ++i) {
			scanf("%d", &x);
			count += 1;
			sum += x;
			if (x < min) min = x;
			if (x > max) max = x;
		}
		printf("Case %d: %d %d %.3f\n\n", case_num, min, max, sum * 1.0 / count);
		case_num += 1;
	}
}

int main() {
	//program_2_1();
	//example_2_1();
	//example_2_2();
	//example_2_3();
	//example_2_4();
	//example_2_5();
	example_2_6();

	//printf("Time Used: %.3fs\n", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}