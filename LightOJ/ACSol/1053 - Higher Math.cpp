#include <iostream>
#include <algorithm>
 
using namespace std;
 
int TC, a[3];
int main() {
    cin >> TC;
    for(int no = 1; no <= TC; ++no) {
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        cout << "Case " << no << ": ";
        if(a[0] * a[0] + a[1] * a[1] == a[2] * a[2]) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}
