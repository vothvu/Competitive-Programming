#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int V;
vector< vector<int> > G;

int color[123456];
int num[123456], low[123456], cnt;

void input() {
    int u, v, k, m;
    char c1, c2;
    scanf("%d", &V);
    m = V;
    if(V) G.assign(V, vector<int>());
    while (m--) {
        scanf("%d", &u);
        c1 = getchar();
        c2 = getchar();
        scanf("%d", &k);
        c2 = getchar();
        c2 = getchar();
        for (int i = 0; i < k; ++i)  {
                scanf("%d", &v);
                G[u].push_back(v);
        }
    }
}

vector< pair<int, int> > ans;

int dfs(int u, int p)
{
    low[u] = num[u] = cnt++;
    color[u] = 1;
    for (int i = 0; i < (int)G[u].size(); ++i) {
        int v = G[u][i];
        if (color[v] == 0) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > num[u]) ans.push_back(make_pair(min(u, v), max(u,v)));
        } else
            if (v != p) low[u] = min(low[u], num[v]);
    }
}


int main()
{
    int T,  no = 0;
    scanf("%d", &T);
    while(T--) {
         input();
         memset(color, 0, sizeof(color));
         ans.clear();
         cnt = 0;
         for (int v = 0; v < V; ++v)
             if(color[v] == 0) dfs(v, -1);
         sort(ans.begin(), ans.end());
         printf("Case %d:\n", ++no);
         printf("%d critical links\n", ans.size());
         for (int i = 0; i < (int)ans.size(); ++i) {
             printf("%d - %d\n", ans[i].first, ans[i].second);
         }
    }
    return 0;
}







