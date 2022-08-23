#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int C, N, score;
    cin >> C;
    for (int i = 0; i < C; ++i) {
        cin >> N;

        vector<int> score_vec;
        double avg = 0;
        for (int j = 0; j < N; ++j) {
            cin >> score;
            score_vec.push_back(score);
            avg += score;
        }
        avg /= score_vec.size();

        int cnt = 0;
        for (auto const &x : score_vec) {
            if (x > avg) {
                ++cnt;
            }
        }

        double percentage = (double) cnt / score_vec.size();
        percentage *= pow(10, 5);
        percentage = floor(percentage + 0.5);
        percentage /= pow(10, 3);

        cout.precision(3);
        cout << fixed << showpoint << percentage << "%\n";
    }
    return 0;
}
