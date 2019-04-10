#include <stdio.h>

int main() {
	for (int i = 123; i < 333; i++) {
		bool exist[10] = {false};
		for (int j = 1; j < 4; ++j) {
			exist[(i*j)/100] = true;
			exist[(i*j)/10%10] = true;
			exist[(i*j)%10] = true;
		}
		bool all_exist = true;
		for (int j = 1; j < 10; ++j) {
			all_exist = all_exist && exist[j];
		}
		if (all_exist) 
			printf("%d %d %d\n", i, 2*i, 3*i);
	}
	return 0;
}