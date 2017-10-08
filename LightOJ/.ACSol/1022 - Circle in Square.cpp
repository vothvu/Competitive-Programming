#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
 
#define pi                  2 * acos(0.0)
#define outLJ(notest, res)  printf("Case %d: %.6lf\n", notest, res)
#define inpFile(name)       freopen(name, "r", stdin)
#define outFile(name)       freopen(name, "w", stdout)
 
int main() {
    int TC;
   // inpFile("test.inp"); //outFile("test.out");
    scanf("%d\n", &TC);
    for(int no = 1; no <= TC; ++no) {
        double r, ans;
        scanf("%lf", &r);
        printf("Case %d: %.2lf\n", no, (double)4.0 * r * r - r * r * pi + 10e-9);
    }
    return 0;
}
