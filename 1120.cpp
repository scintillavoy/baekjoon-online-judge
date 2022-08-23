#include <iostream>
#include <string>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;
    int minDiff = 50;
    for (int i = 0; i <= B.size() - A.size(); ++i) {
        int diff = 0;
        for (int j = 0; j < A.size(); ++j) {
            if (A[j] != B[i + j]) {
                ++diff;
            }
        }
        if (diff < minDiff) {
            minDiff = diff;
        }
    }
    cout << minDiff;
    return 0;
}
