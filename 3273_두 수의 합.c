#include <stdio.h>

int main(void) {

	int n, x, k;
	int ai, aj, sum = 0;

	scanf("%d", &n);

	for (ai = 1; ai <= n; ai++) {
		for (aj = 1; aj <= n; aj++) {
			scanf("%d", &k);

		}
	}

	for (ai = 1; ai <= n; ai++) {
		for (aj = ai; aj <= n; aj++) {
			sum += ai;
			x = ai + aj;
		}
		printf("%d ", x);
	}
	return 0;
