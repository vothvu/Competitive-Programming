/*
ID: Vu Vo
PROG: 1047 - Neighbor House
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
 
int TC, n, no = 0;
int g[maxN], r[maxN], b[maxN];
int main() {
 //   inpFile("test.inp"); // outFile("test.out");
    for(cin >> TC; TC--; ) {
        cin >> n;
        g[0] = r[0] = b[0] = 0;
        for(int i = 1; i <= n; ++i) {
            cin >> r[i] >> g[i] >> b[i];
            r[i] += min(g[i - 1], b[i - 1]);
            g[i] += min(r[i - 1], b[i - 1]);
            b[i] += min(r[i - 1], g[i - 1]);
        }
        printf("Case %d: %d\n", ++no, min(r[n], min(g[n], b[n])));
    }
    return 0;
}
