#include <stdio.h>

#define maxN 100001

int n, m, TC;
int a[maxN], c[maxN];
int main(int argc, char const *argv[]) {
  scanf("%d\n", &TC);
  for(int no = 1; no <= TC; ++no) {
    scanf("%d %d\n", &n, &m);
    for(int i = 0; i < m; ++i) c[i] = 0;
    a[0] = 0;
    for(int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      a[i] = (a[i] + a[i - 1]) % m;
    }
    long long ans = 0;
    for(int i = 0; i <= n; ++i) {
      ans += c[a[i]];
      c[a[i]] += 1;
    }
    printf("Case %d: %lld\n", no, ans);
  }
  return 0;
}
