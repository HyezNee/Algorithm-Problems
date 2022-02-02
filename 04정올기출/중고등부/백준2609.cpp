#include <stdio.h>

int Gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return Gcd(b, a % b);
	}
}

int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);
	if (a < b) {
		int temp;
		temp = a;
		a = b;
		b = temp;
	}
	int gcd = Gcd(a, b);
	int lcm = a * b / gcd;
	printf("%d\n%d", gcd, lcm);

	return 0;
}