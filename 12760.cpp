#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // input
    int N, M;
    cin >> N >> M;
    vector< vector<int> > vec(N, vector<int>(M));
    for (auto &x : vec) {
        for (auto &y : x) {
            cin >> y;
        }
        sort(x.begin(), x.end());
    }

    // compute score
    vector<int> score(N);
    for (int i = 0; i < M; ++i) {
        vector<int> maxPlayer;
        int maxNum = 0;
        for (int j = 0; j < N; ++j) {
            if (vec[j].back() > maxNum) {
                maxPlayer = {j};
                maxNum = vec[j].back();
            } else if (vec[j].back() == maxNum) {
                maxPlayer.push_back(j);
            }
            vec[j].pop_back();
        }
        for (auto const &x : maxPlayer) {
            ++score[x];
        }
    }

    // compute winner
    int maxScore = 0;
    for (auto const &x : score) {
        if (x > maxScore) {
            maxScore = x;
        }
    }
    for (int i = 0; i < N; ++i) {
        if (score[i] == maxScore) {
            cout << i + 1 << ' ';
        }
    }
    return 0;
}
