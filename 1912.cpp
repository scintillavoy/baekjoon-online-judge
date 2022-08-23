#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int answer = -1000, sum = 0;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        sum += val;
        if (answer < sum) {
            answer = sum;
        }
        if (sum < 0) {
            sum = 0;
        }
    }
    cout << answer;
    return 0;
}
