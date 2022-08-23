#include <iostream>
using namespace std;

int main() {
    int curr = 0, maxNum = 0;
    for (int i = 0; i < 10; ++i) {
        int out, in;
        cin >> out >> in;
        curr -= out;
        curr += in;
        if (curr > maxNum) {
            maxNum = curr;
        }
    }
    cout << maxNum;
    return 0;
}
