#include <iostream>
 
using namespace std;
int main() {
    long long n, m;
    int T, no = 1 ;
    for(cin >> T; T--; ++no) {
        cin >> n >> m;
        cout << "Case " << no << ": " << n / 2 * m << endl;
    }
    return 0;
}
