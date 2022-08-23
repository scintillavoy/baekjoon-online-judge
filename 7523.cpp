#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        long long n, m;
        cin >> n >> m;
        cout << "Scenario #" << i << ":\n";
        cout << m*(m+1)/2 - (n-1)*n/2 << "\n\n";
    }
    return 0;
}
