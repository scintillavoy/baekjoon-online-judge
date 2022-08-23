#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    int gandalf[6] = {1, 2, 3, 3, 4, 10};
    int sauron[7] = {1, 2, 2, 2, 3, 5, 10};
    for (int i = 0; i < T; ++i) {
        int gandalf_score = 0, sauron_score = 0;
        for (auto const &x : gandalf) {
            int num;
            cin >> num;
            gandalf_score += num * x;
        }
        for (auto const &x : sauron) {
            int num;
            cin >> num;
            sauron_score += num * x;
        }
        cout << "Battle " << i + 1 << ": ";
        if (gandalf_score > sauron_score) {
            cout << "Good triumphs over Evil\n";
        } else if (gandalf_score < sauron_score) {
            cout << "Evil eradicates all trace of Good\n";
        } else {
            cout << "No victor on this battle field\n";
        }
    }
    return 0;
}
