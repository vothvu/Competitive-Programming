/*
ID: Vu Vo
PROG: 1033 - Generating Palindromes
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
 
int TC, no = 0, n;
char s[maxN];
int memo[maxN][maxN];
 
int dp(int i, int j) {
    if(i == j) return 0;
    if(i + 1 == j) return (s[i] != s[j]);
    if(memo[i][j] != -1) return memo[i][j];
    if(s[i] == s[j]) return memo[i][j] = dp(i + 1, j - 1);
    return memo[i][j] = min(dp(i + 1, j), dp(i, j - 1)) + 1;
}
int main() {
 //   inpFile("test.inp"); // outFile("test.out");
    for(scanf("%d\n", &TC); TC--; ) {
        scanf("%s\n", s);
        memset(memo, -1, sizeof(memo));
        printf("Case %d: %d\n", ++no, dp(0, strlen(s) - 1));
    }
    return 0;
}
 
