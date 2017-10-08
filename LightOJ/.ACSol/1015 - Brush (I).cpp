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
#define maxN 1000
 
int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, 1, 0, -1, 1 , 1, -1, -1};
 
int TC, no;
int N, a[maxN];
 
int main() {
 //   inpFile("test.inp");// outFile("test.out");
    no = 0;
    for(cin >> TC; TC--; ) {
        cin >> N;
        int sum = 0;
        for(int i = 0; i < N; ++i) {
            cin >> a[i];
            sum += max(a[i], 0);
        }
        cout << "Case " << ++no << ": " << sum << endl;
    }
    return 0;
}
 
 
