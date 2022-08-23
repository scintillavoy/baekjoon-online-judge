#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        cout << N*(N+1)/2 << ' ' << N*(N+1)-N << ' ' << N*(N+1) << '\n';
    }
    return 0;
}
