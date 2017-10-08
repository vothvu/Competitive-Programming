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
#define maxN 100100

int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int TC, N, q, no = 0;
long long tree[maxN * 4], lazy[maxN * 4];

void initTree(int l, int r, int id) {
    lazy[id] = -1;
    if(l == r) tree[id] = 0;
    else {
        int m = (l + r) >> 1;
        initTree(l, m, (id << 1));
        initTree(m + 1, r, (id << 1) | 1);
        tree[id] = 0;
    }
}


void update(int u, int v, int l, int r, int val, int id) {
    if(v < l || u > r) return;
    if(l >= u && r <= v) {
        tree[id] = ((long long)(r - l + 1)) * val;
        lazy[id] = val;
        return ;
    }
    int m = (l + r) >> 1;
    if(lazy[id] != -1) {
        int val = lazy[id];
        lazy[(id << 1)] = val;
        tree[(id << 1)] = ((long long)(m - l + 1)) * val;
        lazy[(id << 1) | 1] = val;
        tree[(id << 1) | 1] = ((long long)(r - m)) * val;
        lazy[id] = -1;
    }
    update(u, v, l, m, val, (id << 1));
    update(u, v, m + 1, r, val, (id << 1) | 1);
    tree[id] = tree[(id << 1)] + tree[(id << 1) | 1];
}

long long query(int u, int v,  int l, int r, int id) {
    if(v < l || u > r) return 0;
    if(l >= u && r <= v) return tree[id];
    int m = (l + r) >>  1;
    if(lazy[id] != -1) {
        int val = lazy[id];
        lazy[id << 1] = val;
        tree[id << 1] = ((long long)(m - l + 1)) * val;
        lazy[(id << 1) | 1] = val;
        tree[(id << 1) | 1] = ((long long)(r - m)) * val;
        lazy[id] = -1;
    }
    return query(u, v, l, m, (id << 1)) + query(u, v, m + 1, r, (id << 1) | 1);
}

long long gcd(long long a, long long b) {
    return (a % b) ? gcd(b, a % b): b;
}
int main() {
    //inpFile("test.inp"); // outFile("test.out");
    for(scanf("%d\n", &TC); TC--; ) {
        scanf("%d %d\n", &N, &q);
        initTree(0, N - 1, 1);
        int ty, u, v, val;
        printf("Case %d:\n", ++no);
        while(q--) {
            scanf("%d", &ty);
            if(ty == 1) {
                scanf("%d %d %d\n", &u, &v, &val);
                update(u, v, 0, N - 1, val, 1);
            } else {
                scanf("%d %d\n", &u, &v);
                long long sum = query(u, v, 0, N - 1, 1);
                long long len = (v - u + 1);
                if(sum % len) {
                    long long r = gcd(sum, len);
                    sum /= r, len /= r;
                    printf("%lld/%lld\n", sum, len);
                } else printf("%lld\n", sum / len);
            }
        }
    }
    return 0;
}


