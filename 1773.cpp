#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, C;
    cin >> N >> C;
    vector<int> student(N);
    for (auto &x : student) {
        cin >> x;
    }
    sort(student.begin(), student.end());
    vector<bool> hanabi(C + 1, false);
    for (auto const &x : student) {
        if (hanabi[x]) {
            continue;
        }
        for (int i = x; i <= C; i += x) {
            hanabi[i] = true;
        }
    }
    cout << count(hanabi.begin(), hanabi.end(), true);
    return 0;
}
