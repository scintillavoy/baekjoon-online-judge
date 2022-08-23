#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    string clubs[9] = {"PROBRAIN", "GROW", "ARGOS", "ADMIN", "ANT", "MOTION",
                       "SPG", "COMON", "ALMIGHTY"};
    int maxNum[9] = {0};
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < N; ++j) {
            int num;
            cin >> num;
            if (num > maxNum[i]) {
                maxNum[i] = num;
            }
        }
    }
    cout << clubs[max_element(maxNum, maxNum + 9) - maxNum];
    return 0;
}
