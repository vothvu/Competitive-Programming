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
 
#define inpFile(f) freopen(f,"r",stdin)
#define outFile(f) freopen(f,"w",stdout)
#define REP(i,n) for(int i = 0;i < n; ++i)
#define fto(i,a,b) for(int i = a;i <= b; ++i)
#define fdo(i,a,b) for(int i = a;i >= b; --i)
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
#define maxN 111
 
int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
 
 
int p[maxN];
 
int findSet(int i) {
    return (p[i] == i) ? i : (p[i] = findSet(p[i]));
}
 
bool sameSet(int i, int j) {
    return findSet(i) == findSet(j);
}
 
void unionSet(int i, int j) {
    p[findSet(i)] = findSet(j);
}
 
int T;
int N, M;
vector<iii> edge;
 
bool Cmp(iii x, iii y) { return (x.ff > y.ff); }
 
int findST(int n, int m, vector < iii > e) {
    int ans = 0;
    for(int i = 0; i <= n; ++i) p[i] = i;
    for(int i = 0; i < m; ++i) {
        //cout << e[i].ss.ff << " " << e[i].ss.ss << endl;
        if(sameSet(e[i].ss.ff, e[i].ss.ss)) continue;
        ans += e[i].ff;
        //cout << e[i].ss.ff << " " << e[i].ss.ss << endl;
        unionSet(e[i].ss.ff, e[i].ss.ss);
    }
    return ans;
}
int main() {
    //inpFile("test.inp"); //outFile("test.out");
    scanf("%d\n", &T);
    fto(no, 1, T) {
        int u, v, w;
        scanf("%d\n", &N);
        edge.clear();
        while(scanf("%d %d %d\n", &u, &v, &w)) {
            if(u == 0 && v == 0 && w == 0) break;
            edge.push_back(iii(w, ii(u, v)));
        }
        int minST, maxST;
        M = (int) edge.size();
        sort(edge.begin(), edge.end());
        minST = findST(N, M, edge);
        reverse(edge.begin(), edge.end());
        maxST = findST(N, M, edge);
        int p = (minST + maxST);
        if(p % 2 == 0) printf("Case %d: %d\n", no, p / 2);
        else printf("Case %d: %d/%d\n", no, p, 2);
    }
    return 0;
}
 
 
 
