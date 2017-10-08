/*
ID: Vu Vo
PROG: 1162 - Min Max Roads
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
 
#define inpFile(f) freopen(f,"r",stdin)
#define outFile(f) freopen(f,"w",stdout)
#define REP(i,n) for(int i = 0;i < n; ++i)
#define FOR(i,a,b) for(int i = a;i <= b; ++i)
#define FORD(i,a,b) for(int i = a;i >= b; --i)
#define fill(a,val) memset(a,val,sizeof(a))
#define ll long long
#define ull unsigned long long
#define INF 500000000
#define bit(i) ((i)&(-i))
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define nL(note) note+note
#define nR(note) note+note+1
 
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
 
#define MOD 10000007
#define maxN 100010
 
int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
 
int N, q;
int H[maxN];
vector<vector<ii> > Adj;
 
int minRoad[maxN][18], maxRoad[maxN][18], LCA[maxN][18];
 
void dfs(int v, int pV) {
    for(int i = 0; i < (int)Adj[v].size(); ++i) {
        ii u = Adj[v][i];
        if(u.first == pV) continue;
        LCA[u.first][0] = v;   H[u.first] = H[v] + 1;
        minRoad[u.first][0] = maxRoad[u.first][0] = u.second;
        dfs(u.first, v);
    }
}
 
void initLCA() {
    for(int j = 0; (1 << j) <= N; ++j)
        for(int i = 1; i <= N; ++i)  {
                LCA[i][j] = -1;
                maxRoad[i][j] = 0;
                minRoad[i][j] = INF;
        }
    memset(H, 0, sizeof(H));
    dfs(1, 0);
    for(int j = 1; (1 << j) <= N; ++j) {
        for(int i = 1; i <= N; ++i) {
            if(LCA[i][j - 1] != -1) {
                LCA[i][j] = LCA[LCA[i][j - 1]][j - 1];
                if(LCA[i][j] != -1) minRoad[i][j] = min(minRoad[i][j - 1], minRoad[LCA[i][j - 1]][j - 1]);
                if(LCA[i][j] != -1) maxRoad[i][j] = max(maxRoad[i][j - 1], maxRoad[LCA[i][j - 1]][j - 1]);
            }
        }
    }
 
}
 
int log2(int N) {
    int ans = 0;
    while(N) N /= 2, ++ans;
    return --ans;
}
void process(int u, int v) {
    int ans1, ans2;
    ans1 = INF, ans2 = 0;
    if(H[u] < H[v]) swap(u, v);
    int k = log2(H[u]);
    for(int i = k; i >= 0; --i) {
        if(LCA[u][i] != -1 && H[LCA[u][i]] >= H[v]) {
                ans1 = min(ans1, minRoad[u][i]);
                ans2 = max(ans2, maxRoad[u][i]);
                u = LCA[u][i];
        }
    }
    if(u != v) {
        for(int i = k; i >= 0; --i) {
            if(LCA[u][i] != -1 && LCA[u][i] != LCA[v][i]) {
                ans1 = min(ans1, min(minRoad[u][i], minRoad[v][i]));
                ans2 = max(ans2, max(maxRoad[u][i], maxRoad[v][i]));
                u = LCA[u][i], v = LCA[v][i];
            }
        }
        ans1 = min(ans1, min(minRoad[u][0], minRoad[v][0]));
        ans2 = max(ans2, max(maxRoad[u][0], maxRoad[v][0]));
    }
    printf("%d %d\n", ans1, ans2);
}
int main() {
   // inpFile("test.inp");// outFile("test.out");
    int TC, no = 0;
    for(scanf("%d\n", &TC); TC--; ) {
        printf("Case %d:\n", ++no);
        scanf("%d\n", &N);
        Adj.assign(N + 1, vector<ii>() );
        int u, v, w;
        for(int i = 1; i < N; ++i) {
            scanf("%d %d %d\n", &u, &v, &w);
            Adj[u].push_back(ii(v, w));
            Adj[v].push_back(ii(u, w));
        }
        initLCA();
        scanf("%d\n", &q);
        while(q--) {
            scanf("%d %d\n", &u, &v);
            process(u, v);
        }
    }
    return 0;
}
