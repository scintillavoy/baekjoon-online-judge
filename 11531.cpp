#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<int> wrongCnt(26), rightTime(26, -1);
    int m;
    char name;
    string result;
    while (cin >> m) {
        if (m == -1) {
            break;
        }
        cin >> name >> result;
        if (result == "wrong") {
            ++wrongCnt[name - 'A'];
        } else if (result == "right") {
            rightTime[name - 'A'] = m;
        }
    }

    int rightCnt = 0, penalty = 0;
    for (int i = 0; i < 26; ++i) {
        if (rightTime[i] != -1) {
            ++rightCnt;
            penalty += rightTime[i] + wrongCnt[i] * 20;
        }
    }

    cout << rightCnt << ' ' << penalty;
    return 0;
}
