/*
ID: Vu Vo
PROG: 1008 - Fibsieve`s Fantabulous Birthday
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
#include <cmath>
 
using namespace std;
 
#define inpFile(name)   freopen(name, "r", stdin)
#define outFile(name)   freopen(name, "w", stdout)
#define INF             5000000
#define maxN            100
 
typedef pair<int, int> ii;
typedef pair<int, ii>  iii;
 
int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
 
int TC, no = 0;
long long S;
 
 
int main() {
 //   inpFile("test.inp"); // outFile("test.out");
    for(scanf("%d\n", &TC); TC--; ) {
        scanf("%lld\n", &S);
        long long n = (long long)sqrt((double)(S - 1)) + 1;
        int x, y;
        long long m = (n - 1)* (n - 1) + n;
        if(n % 2 == 1) {
            if(S > m) {
                y = n;
                x = n * n - S + 1;
            } else {
                x = n;
                y = S - (n - 1) * (n - 1);
            }
        } else {
            if(S > m) {
                x = n;
                y = n * n - S + 1;
            } else {
                x = S - (n - 1) * (n - 1);
                y = n;
            }
        }
        printf("Case %d: %d %d\n", ++no, x, y);
    }
    return 0;
}
 
