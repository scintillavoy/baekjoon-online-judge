#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        for (int j = 0; j < N; ++j) {
            if (vec[j] == 0) {
                if (num == 0) {
                    vec[j] = i + 1;
                    break;
                } else {
                    --num;
                }
            }
        }
    }
    for (auto const &x : vec) {
        cout << x << ' ';
    }
    return 0;
}
