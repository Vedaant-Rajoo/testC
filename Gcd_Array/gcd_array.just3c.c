#include <stdio.h>
#include <stdlib.h>

#define N	200000
#define Q	200000
#define A	200000
#define C	6	/* 2 * 3 * 5 * 7 * 11 * 13 * 17 > A */
#define MD	1000000007
#define INF	0x3f3f3f3f

int min(int a, int b) _Checked { return a < b ? a : b; }

int pp _Checked[A + 1] _Checked[C];
int kk _Checked[A + 1] _Checked[C];
int cnt _Checked[A + 1]; char composite _Checked[A + 1];

void init() _Checked {
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

long long power(long long a, int k) _Checked {
	long long p = 1;

	while (k) {
		if (k & 1)
			p = p * a % MD;
		a = a * a % MD;
		k >>= 1;
	}
	return p;
}

_Array_ptr<int> eh _Checked[A + 1] = {((void *)0)};
_Array_ptr<int> ei _Checked[A + 1] = {((void *)0)};
_Array_ptr<int> ek _Checked[A + 1] = {((void *)0)};
int eo _Checked[A + 1];

void append(int a, int h, int i, int k) _Checked {
	int o = eo[a]++;

	if (o >= 2 && (o & o - 1) == 0) _Unchecked {
		eh[a] = (_Array_ptr<int>) realloc<int>(eh[a], o * 2 * sizeof *eh[a]);
		ei[a] = (_Array_ptr<int>) realloc<int>(ei[a], o * 2 * sizeof *ei[a]);
		ek[a] = (_Array_ptr<int>) realloc<int>(ek[a], o * 2 * sizeof *ek[a]);
	}
	eh[a][o] = h, ei[a][o] = i, ek[a][o] = k;
}

int main() {
	static int ans _Checked[N + Q];
static int kk_ _Checked[N];
	int n, q, g, h, i, a;

	init();
	scanf("%d%d", &n, &q);
	for (a = 2; a <= A; a++) {
		eh[a] = (_Array_ptr<int>) malloc<int>(2 * sizeof *eh[a]);
		ei[a] = (_Array_ptr<int>) malloc<int>(2 * sizeof *ei[a]);
		ek[a] = (_Array_ptr<int>) malloc<int>(2 * sizeof *ek[a]);
	}
	for (i = 0; i < n; i++) _Checked {
		_Unchecked { scanf("%d", &a); };
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
	for (a = 2; a <= A; a++) _Checked {
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
