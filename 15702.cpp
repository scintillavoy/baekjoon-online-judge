#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> score_dist(N);
    for (auto &x : score_dist) {
        cin >> x;
    }
    int max_id = 100000 + 1, max_score = 0;
    while (M--) {
        int id, score = 0;
        cin >> id;
        for (int i = 0; i < N; ++i) {
            char c;
            cin >> c;
            if (c == 'O') {
                score += score_dist[i];
            }
        }
        if (max_score < score) {
            max_score = score;
            max_id = id;
        } else if (max_score == score && max_id > id) {
            max_id = id;
        }
    }
    cout << max_id << ' ' << max_score << '\n';
    return 0;
}
