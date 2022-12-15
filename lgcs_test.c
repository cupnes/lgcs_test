/* 線形合同法(Linear congruential generators, LGCs)の実験プログラム

LGCsについて：
- X_{n + 1} = (A * X_n + B) mod M
  - A, B, M :: const
    - M > A
    - M > B
    - A > 0
    - B >= 0
  - 生成される乱数列は周期性を持つ
  - 周期は最大でMであり、以下の条件が満たされたときに最大周期Mをもつ(☆)
    1. BとMが互いに素である(BとMの最大公約数が1である)
    2. A-1が、Mの持つ全ての素因数で割りきれる(A-1が、Mの全ての約数で割り切れる)
    3. Mが4の倍数である場合は、A-1も4の倍数である
- ref
  - 線形合同法 - Wikipedia
    https://ja.wikipedia.org/wiki/%E7%B7%9A%E5%BD%A2%E5%90%88%E5%90%8C%E6%B3%95
*/

#include <stdio.h>

/* ☆の条件を満たす例 */
/*
#define LGCS_A	13
#define LGCS_B	5
#define LGCS_M	24
*/
/*
#define LGCS_A	5
#define LGCS_B	3
#define LGCS_M	32768
*/
#define LGCS_A	5
#define LGCS_B	3
#define LGCS_M	16

/* X_0 */
#define LGCS_X0	0

int lgcs(void)
{
	static int xn = LGCS_X0;
	xn = (LGCS_A * xn + LGCS_B) % LGCS_M;
	return xn;
}

int main(void)
{
	int i;
	for (i = 0; i < 1000; i++) {
		printf("%d ", lgcs());
	}
	return 0;
}
