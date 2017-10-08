/*
ID: Vu Vo
PROG: 1005 - Rooks
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
 
using namespace std;
 
#define inpFile(name)   freopen(name, "r", stdin)
#define outFile(name)   freopen(name, "w", stdout)
#define INF             5000000
#define maxN            100
 
typedef pair<int, int> ii;
typedef pair<int, ii>  iii;
 
int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
 
int n, k, nTest;
long long C[maxN][maxN];
 
long long A(int n, int k) {
    long long res = 1;
    for(long long i = n; i > (n - k); --i) res *= i;
    return res;
}
void init() {
    for(int i = 0; i <= 30; ++i) C[i][0] = C[i][i] = 1;
    for(int i = 2; i <= 30; ++i)
        for(int j = 1; j < i; ++j) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
}
int main() {
  //  inpFile("test.inp"); // outFile("test.out");
    scanf("%d\n", &nTest);
    init();
    for(int no = 1; no <= nTest; ++no) {
        scanf("%d %d\n", &n, &k);
        printf("Case %d: %lld\n", no, (n >= k) ? A(n, k) * C[n][k] : 0);
    }
    return 0;
}
 
