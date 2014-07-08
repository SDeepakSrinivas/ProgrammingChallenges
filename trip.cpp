/*
 *By SDS
 *Solution for The Trip
 *
 */
#include <cstdio>

int main () {
	long n;
	double tot;
	double ex;

	double equa;

	double diff;
	double negativeSum;
	double positiveSum;

	int i;

	while(scanf("%ld", &n) != 0) {

		if (!n) {
			return 0;
		}
		double cost[n];
		tot = 0;
		negativeSum = 0;
		positiveSum = 0;

		for (i = 0; i < n; i++) {
			scanf("%lf\n", &cost[i]);
			tot += cost[i];
		}

		equa = tot / n;

		for (i = 0; i < n; i++) {
			diff = (double) (long) ((cost[i] - equa) * 100.0) / 100.0;

			if (diff < 0) {
				negativeSum += diff;
			} else {
				positiveSum += diff;
			}
		}

		ex = (-negativeSum > positiveSum) ? -negativeSum : positiveSum;

		printf("$%.2lf\n", ex);
	}

    return 0;
}
