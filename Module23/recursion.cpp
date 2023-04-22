#include <stdio.h>

#include <string.h>

#define INF 2000000000



int i, res, n;

int dp[1000001];



int min(int a, int b, int c)

{

  int res = a;

  if (b < res) res = b;

  if (c < res) res = c;

  return res;

}



int f(int n)

{

  if (n == 1) return 0;

  if (dp[n] != -1) return dp[n];

  int a = f(n - 1);

  int b = (n % 2 == 0) ? f(n / 2) : INF;

  int c = (n % 3 == 0) ? f(n / 3) : INF;

  return dp[n] = min(a,b,c) + 1;

}



int main(void)

{

  memset(dp, -1, sizeof(dp));

  while (scanf("%d", &n) == 1)

  {

    res = f(n);

    printf("%d\n", res);

  }

  return 0;

}
