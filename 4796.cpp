#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int L, P, V;
    for (int i = 1; cin >> L >> P >> V; ++i) {
        if (!L && !P && !V) {
            break;
        }
        cout << "Case " << i << ": " << V / P * L + min(V % P, L) << '\n';
    }
    return 0;
}
