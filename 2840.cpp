#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int check[26] = {0};
    vector<char> wheelOfFortune(N, '?');
    int idx = N - 1;
    while (K--) {
        int S;
        char C;
        cin >> S >> C;
        idx -= S;
        while (idx < 0) {
            idx += N;
        }
        if (wheelOfFortune[idx] == C) {
            continue;
        } else if (wheelOfFortune[idx] != '?' || check[C - 'A'] != 0) {
            cout << "!\n";
            return 0;
        } else {
            wheelOfFortune[idx] = C;
            ++check[C - 'A'];
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << wheelOfFortune[idx];
        idx = (idx + 1) % N;
    }
    cout << '\n';
    return 0;
}
