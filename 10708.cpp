#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> target(M);
    for (auto &x : target) {
        cin >> x;
    }
    vector<int> score(N);
    for (int i = 0; i < target.size(); ++i) {
        int bonus = 0;
        for (int j = 0; j < N; ++j) {
            int guess;
            cin >> guess;
            if (guess == target[i]) {
                ++score[j];
            } else {
                ++bonus;
            }
        }
        score[target[i] - 1] += bonus;
    }
    for (auto const &x : score) {
        cout << x << '\n';
    }
    return 0;
}
