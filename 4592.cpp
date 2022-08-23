#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    while (true) {
        cin >> N;
        if (N == 0) {
            break;
        }
        vector<int> vec;
        int curr, prev = 0;
        for (int i = 0; i < N; ++i) {
            cin >> curr;
            if (curr != prev) {
                vec.push_back(curr);
                prev = curr;
            }
        }
        for (auto const &x : vec) {
            cout << x << ' ';            
        }
        cout << "$\n";
    }
    return 0;
}
