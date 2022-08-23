#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (N--) {
        string str;
        getline(cin, str);
        int score = 0;
        for (auto const &x : str) {
            if (x != ' ') {
                score += x - 'A' + 1;
            }
        }
        if (score == 100) {
            cout << "PERFECT LIFE";
        } else {
            cout << score;
        }
        cout << '\n';
    }
    return 0;
}
