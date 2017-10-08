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
#define maxN 100
 
int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
 
int main() {
  //  inpFile("test.inp"); //outFile("test.out");
    int T, no = 0;
    for(cin >> T; T--; ) {
        long long W;
        long long N, M;
        cin >> W;
        M = 1;
        while(W % M == 0) M = M * 2;
        M /= 2;
        if(M != 1) cout << "Case " << ++no << ": " << W / M << " "<< M << endl;
        else cout << "Case " << ++no << ": Impossible"  << endl;
    }
    return 0;
}
 
