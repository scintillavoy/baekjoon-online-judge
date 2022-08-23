#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int maxVal = 0;
    for (int i = 1; i <= K; ++i) {
        string str = to_string(N * i);
        reverse(str.begin(), str.end());
        if (maxVal < stoi(str)) {
            maxVal = stoi(str);
        }
    }
    cout << maxVal;
    return 0;
}
