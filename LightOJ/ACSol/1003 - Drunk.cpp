#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
 
 
using namespace std;
 
#define maxN 100010
 
int n, m, cycle;
int num[maxN];
vector< vector<int> > AdjList;
 
 
map<string, int> name;
 
 
void dfs(int u) {
    num[u] = 1;
    for (std::vector<int>::iterator i = AdjList[u].begin(); i != AdjList[u].end(); ++i)
    {
        int v = *i;
        if(!num[v]) dfs(v);
        else {
            if(num[v] == 1) cycle = 1;
        }
    }
    num[u] = 2;
}
 
void input() {
    scanf("%d\n", &m);
    n = 0;
    name.clear();
    AdjList.assign(maxN, vector<int> ());
    char a[10], b[10];
    while(m--) {
        int x, y;
        cin >> a >> b;
        if(name.count(a) == 0) name[a] = n++;
        if(name.count(b) == 0) name[b] = n++;
        x = name[a], y = name[b];
        AdjList[x].push_back(y);
    }
}
 
void process() {
    for (int i = 0; i < n; ++i) num[i] = 0;
    cycle = 0;
    for (int i = 0; i < n; ++i)
        if(num[i] == 0) dfs(i);
}
int main(int argc, char const *argv[])
{
//  freopen("test.inp", "r", stdin);
    int T;
    scanf("%d\n", &T);
    for (int no = 1; no <= T; ++no)
    {
        input();
        process();
        printf("Case %d: %s\n", no, (cycle) ? "No" : "Yes");
    }
    return 0;
}
