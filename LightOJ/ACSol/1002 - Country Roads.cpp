/*
tag : Graph/Dijkstra
ID: Vu Vo
PROG:
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
#define maxN            501
 
typedef pair<int, int> ii;
typedef pair<int, ii>  iii;
 
int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
 
int TC, no = 0;
int n, m, t;
int d[maxN];
priority_queue<ii, vector<ii>, greater<ii> > pq;
vector<vector<ii> > Adj;
 
void input() {
    int u, v, w;
    scanf("%d %d\n", &n, &m);
    Adj.assign(n, vector<ii>());
    while(m--) {
        scanf("%d %d %d\n", &u, &v, &w);
        Adj[u].push_back(ii(v, w));
        Adj[v].push_back(ii(u, w));
    }
    scanf("%d\n", &t);
}
 
void dijkstra(int t) {
    for(int i = 0; i < n; ++i) d[i] = INF;
    d[t] = 0;
    pq.push(ii(0, t));
    while(!pq.empty()) {
        ii fr = pq.top(); pq.pop();
        int w = fr.first, u = fr.second;
        if(w != d[u]) continue;
        for(int i = 0; i < (int)Adj[u].size(); ++i) {
            ii v = Adj[u][i];
            if(d[v.first] > max(d[u], v.second)) {
                d[v.first] = max(d[u], v.second);
                pq.push(ii(d[v.first], v.first));
            }
        }
    }
}
int main() {
  //  inpFile("test.inp"); // outFile("test.out");
    for(scanf("%d\n", &TC); TC--; ) {
        input();
        dijkstra(t);
        printf("Case %d:\n", ++no);
        for(int i = 0; i < n; ++i)
            if(d[i] != INF) printf("%d\n", d[i]);
            else printf("Impossible\n");
    }
    return 0;
}
 
