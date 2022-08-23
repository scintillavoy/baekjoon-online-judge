/* this problem has a problem
input
10
5 3 1 1 1 1 1 5 3 3

output
54

5   3   1   1 1 1 1 5 3 3 = 54
5 3   1 1   1 1 1   5 3 3 = 62
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    int product = 1;
    for (auto &x : vec) {
        cin >> x;
        product *= x;
    }

    int maxSum = 0, sum;

    // case 1
    sum = product / vec[0] / vec[1] / vec[2] + vec[0] + vec[1] + vec[2];
    if (maxSum < sum) {
        maxSum = sum;
    }

    // case 2
    sum = product / vec[0] / vec[1] / vec[N-1] + vec[0] + vec[1] + vec[N-1];
    if (maxSum < sum) {
        maxSum = sum;
    }

    // case 3
    sum = product / vec[0] / vec[N-2] / vec[N-1] + vec[0] + vec[N-2] + vec[N-1];
    if (maxSum < sum) {
        maxSum = sum;
    }

    // case 4
    sum = product / vec[N-3] / vec[N-2] / vec[N-1] + vec[N-3] + vec[N-2] + vec[N-1];
    if (maxSum < sum) {
        maxSum = sum;
    }

    cout << maxSum << '\n';
    return 0;
}
