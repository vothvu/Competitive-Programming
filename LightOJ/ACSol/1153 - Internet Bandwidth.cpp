#include <stdio.h>
#include <string.h>
#include <queue>
 
using namespace std;
 
int min(int a, int b) {
        return (a > b) ? b : a;
    }
 
#define maxN 200
#define INF 5000000000
int N, s, t, m;
int c[maxN][maxN], p[maxN];
 
int dfs(int v, int minEdge) {
        if(v == s) return minEdge;
        int f = dfs(p[v], min(c[p[v]][v], minEdge));
        c[p[v]][v] -= f;
        c[v][p[v]] += f;
        return f;
    }
   
int bfs(int s, int t) {
        memset(p, -1, sizeof(p));
        queue<int> q;
        q.push(s);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            if(u == t) break;
            for(int v = 1; v <= N; ++v)
                if(c[u][v] && p[v] == -1) {
                    p[v] = u;
                    q.push(v);
                }
        }
        return (p[t] != -1);
    }
 
int maxflow(int s, int t) {
        int mf = 0;
        while(bfs(s, t)) {
            int f;
            if(!(f = dfs(t, INF))) break;
            mf += f;
        }
        return mf;
    }
 
void input() {
        int u, v,  w;
        memset(c, 0, sizeof(c));
        scanf("%d", &N);
        scanf("%d%d%d", &s, &t, &m);
        for(int i = 0; i < m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            c[u][v] += w;
            c[v][u] += w;
        }
    }
int main() {
        int TC;
    //  freopen("test.inp", "r", stdin);
        scanf("%d", &TC);
        for(int no = 1; no <= TC; ++no) {
            input();
            printf("Case %d: %d\n", no, maxflow(s, t));
        }
        return 0;
    }
 
