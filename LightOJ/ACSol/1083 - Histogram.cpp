/*
ID: Vu Vo
PROG:
LANG: C++
*/
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cctype>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <set>
 
using namespace std;
 
#define inpFile(name)   freopen(name, "r", stdin)
#define outFile(name)   freopen(name, "w", stdout)
#define maxN            30001
 
int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
 
int N, A[maxN];
int L[maxN], R[maxN];
 
int process(int a[maxN], int n) {
    L[1] = 0;
    for(int i = 2; i <= n; ++i) {
        L[i] = i - 1;
        while(L[i] > 0 && a[L[i]] >= a[i]) L[i] = L[L[i]];
    }
    R[n] = n + 1;
    for(int i = n - 1; i > 0; --i) {
        R[i] = i + 1;
        while(R[i] < n + 1 && a[R[i]] >= a[i]) R[i] = R[R[i]];
    }
    int ans = 0;
    for(int i = 1; i <= N; ++i) {
        ans = max(a[i] * (R[i] - L[i] - 1), ans);
    }
    return ans;
}
int main() {
    //inpFile("test.inp"); //outFile("test.out");
    int TC, no = 0;
    for(scanf("%d\n", &TC); TC--; ) {
        scanf("%d\n", &N);
        for(int i = 1; i <= N; ++i) scanf("%d", &A[i]);
        printf("Case %d: %d\n", ++no, process(A, N));
    }
    return 0;
}
 
 
