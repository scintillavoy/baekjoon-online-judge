#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int A_score, B_score, A_win = 0, B_win = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A_score >> B_score;
        if (A_score > B_score) {
            ++A_win;
        } else if (A_score < B_score) {
            ++B_win;
        }
    }
    cout << A_win << ' ' << B_win;
    return 0;
}
