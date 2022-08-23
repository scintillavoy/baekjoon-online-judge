#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        string a, b;
        cin >> a >> b;
        cout << "Distances:";
        for (int j = 0; j < a.size(); ++j) {
            int dist = b[j] - a[j];
            if (dist < 0) {
                dist += 26;
            }
            cout << ' ' << dist;
        }
        cout << '\n';
    }
    return 0;
}
