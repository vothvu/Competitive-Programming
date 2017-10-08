/*
ID: Vu Vo
PROG: 1007 - Mathematically Hard
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
#define maxN            5 * (int)1e6
 
typedef pair<int, int> ii;
typedef pair<int, ii>  iii;
 
int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
 
int TC, a, b, no;
unsigned long long phi[maxN + 10];
 
void init() {
    for(int i = 1; i <= maxN; ++i) phi[i] = i;
    for(int i = 2; i <= maxN; ++i)
        if(i == phi[i])  {
            phi[i] = i - 1;
            for(int j = i + i; j <= maxN; j += i)
                phi[j] = phi[j] - phi[j] / i;
        }
    phi[1] = 0;
    for(int i = 2; i <= maxN; ++i) phi[i] = phi[i - 1] +  phi[i] * phi[i];
}
 
 
int main() {
  //  inpFile("test.inp"); // outFile("test.out");
    init();
    no = 0;
    for(scanf("%d\n", &TC); TC--; ) {
        scanf("%d %d\n", &a, &b);
        printf("Case %d: %llu\n", ++no, phi[b] - phi[a - 1]);
    }
    return 0;
}
 
