#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>
 
using namespace std;
 
#define INF 2000000
#define maxN 101
#define inpFile(name) freopen(name, "r", stdin)
 
int N, M, TC, no = 0;
int A[maxN][maxN];
int d[maxN], check[maxN];
 
int dijkstra() {
    for(int i = 0; i <= N; ++i) d[i] = INF, check[i] = 0;
    d[1] = 0;
    while(1) {
        int u = 0;
        for(int v = 1; v <= N; ++v)
            if(!check[v] && d[u] > d[v]) u = v;
        if(u == N) return d[u];
        if(u == 0) return -1;
        check[u] = 1;
        for(int v = 1; v <= N; ++v)
            if(!check[v] && d[v] > d[u] + A[u][v]) d[v] = d[u] + A[u][v];
    }
}
 
void input() {
    cin >>  N >> M;
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N; ++j) A[i][j] = INF;
    while(M--) {
        int u, v, w;
        cin >> u >> v >> w;
        A[u][v] = A[v][u] =  min(A[u][v], w);
    }
}
 
int main() {
    //inpFile("test.inp");
    for(cin >> TC; TC--; ) {
        input();
        int ans = dijkstra();
        if(ans == -1) printf("Case %d: Impossible\n", ++no);
        else printf("Case %d: %d\n", ++no, ans);
    }
    return 0;
}
 
