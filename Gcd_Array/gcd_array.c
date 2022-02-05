#include <stdio.h>
#include <stdlib.h>

#define N	200000
#define Q	200000
#define A	200000
#define C	6	/* 2 * 3 * 5 * 7 * 11 * 13 * 17 > A */
#define MD	1000000007
#define INF	0x3f3f3f3f

int min(int a, int b) { return a < b ? a : b; }

int pp[A + 1][C], kk[A + 1][C], cnt[A + 1]; char composite[A + 1];

void init() {
	int a, b;

	for (a = 2; a <= A; a++) {
		if (composite[a])
			continue;
		for (b = a; b <= A; b += a) {
			int b_, k;

			composite[b] = 1;
			for (b_ = b, k = 0; b_ % a == 0; b_ /= a)
				k++;
			pp[b][cnt[b]] = a, kk[b][cnt[b]] = k, cnt[b]++;
		}
	}
}

long long power(long long a, int k) {
	long long p = 1;

	while (k) {
		if (k & 1)
			p = p * a % MD;
		a = a * a % MD;
		k >>= 1;
	}
	return p;
}

int *eh[A + 1], *ei[A + 1], *ek[A + 1], eo[A + 1];

void append(int a, int h, int i, int k) {
	int o = eo[a]++;

	if (o >= 2 && (o & o - 1) == 0) {
		eh[a] = (int *) realloc(eh[a], o * 2 * sizeof *eh[a]);
		ei[a] = (int *) realloc(ei[a], o * 2 * sizeof *ei[a]);
		ek[a] = (int *) realloc(ek[a], o * 2 * sizeof *ek[a]);
	}
	eh[a][o] = h, ei[a][o] = i, ek[a][o] = k;
}

int main() {
	static int ans[N + Q], kk_[N];
	int n, q, g, h, i, a;

	init();
	scanf("%d%d", &n, &q);
	for (a = 2; a <= A; a++) {
		eh[a] = (int *) malloc(2 * sizeof *eh[a]);
		ei[a] = (int *) malloc(2 * sizeof *ei[a]);
		ek[a] = (int *) malloc(2 * sizeof *ek[a]);
	}
	for (i = 0; i < n; i++) {
		scanf("%d", &a);
		for (g = 0; g < cnt[a]; g++)
			append(pp[a][g], i, i, kk[a][g]);
	}
	for (h = 0; h < q; h++) {
		scanf("%d%d", &i, &a), i--;
		for (g = 0; g < cnt[a]; g++)
			append(pp[a][g], n + h, i, kk[a][g]);
	}
	for (h = 0; h < n + q; h++)
		ans[h] = 1;
	for (a = 2; a <= A; a++) {
		int o, k0;

		k0 = n;
		for (o = 0; o < eo[a]; o++) {
			int k;

			h = eh[a][o], i = ei[a][o], k = ek[a][o];
			if (kk_[i] == 0)
				k0--;
			kk_[i] += k;
			if (k0 == 0) {
				k = INF;
				for (i = 0; i < n; i++)
					k = min(k, kk_[i]);
				ans[h] = ans[h] * power(a, k) % MD;
				k0 = 0;
				for (i = 0; i < n; i++)
					if ((kk_[i] -= k) == 0)
						k0++;
			}
		}
		for (o = 0; o < eo[a]; o++) {
			i = ei[a][o];
			kk_[i] = 0;
		}
	}
	for (h = 1; h < n + q; h++)
		ans[h] = (long long) ans[h] * ans[h - 1] % MD;
	for (h = n; h < n + q; h++)
		printf("%d\n", ans[h]);
	return 0;
}
