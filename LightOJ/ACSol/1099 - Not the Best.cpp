#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 1000000000
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n, m, TC;
vector< vector<ii> > Adj;

priority_queue<ii, vector<ii>, greater<ii> > pq;

vector<int> dijkstra(int s) {
  vector<int> d(n + 1, INF);
  d[s] = 0;
  pq.push(ii(0, s));
  while(!pq.empty()) {
    ii front = pq.top(); pq.pop();
    int w = front.first, u = front.second;
    if(d[u] < w) continue;
    for(int i = 0; i < (int)Adj[u].size(); ++i) {
      ii v = Adj[u][i];
      if(d[v.first] > d[u] + v.second) {
        d[v.first] = d[u] + v.second;
        pq.push(ii(d[v.first], v.first));
      }
    }
  }
  return d;
}

void process(int no) {
    vector<int> d1 = dijkdtra(1);
    vector<int> dn = dijkstra(n);
    int ans = INF;
    for(int u = 1; u <= n; ++u) {
      for(int i = 0; i < (int)Adj[u].size(); ++i) {
        ii v = Adj[u][i];
        if(d1[u] + dn[v.first] + v.second == d1[n]) ans = min(ans,d1[u] + dn[v.first] + 3* v.second);
        else ans = min(ans, d1[u] + dn[v.first] + v.second);
      }
    }
    printf("Case %d: %d\n", no, ans);
}

void input() {
  scanf("%d%d", &n, &m);
  Adj.assign(n + 1, vector<ii>());
  while(m--) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    Adj[u].push_back(ii(v,w));
    Adj[v].push_back(ii(u,w));
  }
}
int main(int argc, char const *argv[]) {
  scanf("%d", &TC);
  for(int no = 1; no <= TC; ++no) {
    input();
    process(no);
  }
  return 0;
}
