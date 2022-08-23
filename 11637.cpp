#include <iostream>
#include <utility>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int n;
        cin >> n;
        pair<int, int> winner(-1, -1);
        int numOfVotes = 0;
        for (int j = 0; j < n; ++j) {
            int vote;
            cin >> vote;
            numOfVotes += vote;
            if (vote > winner.first) {
                winner.first = vote;
                winner.second = j;
            } else if (vote == winner.first) {
                winner.second = -1;
            }
        }
        if (winner.second == -1) {
            cout << "no winner\n";
        } else {
            if (winner.first > numOfVotes / 2) {
                cout << "majority ";
            } else {
                cout << "minority ";
            }
            cout << "winner " << winner.second + 1 << '\n';
        }
    }
    return 0;
}
