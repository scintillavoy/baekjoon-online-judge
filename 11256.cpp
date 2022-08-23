#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int J, N;
        cin >> J >> N;
        vector<int> box(N);
        for (auto &x : box) {
            int R, C;
            cin >> R >> C;
            x = R * C;
        }
        sort(box.begin(), box.end(), greater<int>());
        int cnt = 0;
        for (int i = 0; J > 0; ++i) {
            J -= box[i];
            ++cnt;
        }
        cout << cnt << '\n';
    }
    return 0;
}
