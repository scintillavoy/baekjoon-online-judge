#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int V, E;
        cin >> V >> E;
        cout << 2 - V + E << '\n';
    }
    return 0;
}
