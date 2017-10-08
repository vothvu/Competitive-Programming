#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
 
using namespace std;
 
#define inpFile(name)       freopen(name, "r", stdin)
#define outFile(name)       freopen(name, "w", stdout)
#define minID(name, a, b)   ((name[a] < name[b]) ? a : b)
#define maxN                100010
 
int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
 
int N, q, A[maxN];
int ST[maxN][20], L[maxN];
void init() {
    L[0] = 0;
    for(int i = 1; i <= 100000; ++i) L[ST[i][0] = i] = L[i >> 1] + 1;
}
 
void builtST(int N) {
    for(int j = 1; (1 << j) <= N; ++j) {
        for(int i = 1; i + (1 << j) - 1 <= N; ++i) {
            ST[i][j] = minID(A, ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
        }
    }
}
 
int RMQ(int i, int j) {
    int k = L[j - i + 1] - 1;
    return min(A[ST[i][k]], A[ST[j - (1 << k) + 1][k]]);
}
int main() {
   // inpFile("test.inp"); // outFile("test.out");
    int TC, no = 0;
    init();
    for(scanf("%d\n", &TC); TC--; ) {
        scanf("%d %d", &N, &q);
        for(int i = 1; i <= N; ++i) scanf("%d", &A[i]);
        builtST(N);
        printf("Case %d:\n", ++no);
        int u, v;
        while(q--){
            scanf("%d %d", &u, &v);
            printf("%d\n", RMQ(u, v));
        }
    }
    return 0;
}
