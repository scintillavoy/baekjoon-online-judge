#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int S1, S2, S3;
    cin >> S1 >> S2 >> S3;
    vector<int> vec(S1 + S2 + S3 - 2, 0);
    for (int i = 1; i <= S1; ++i) {
        for (int j = 1; j <= S2; ++j) {
            for (int k = 1; k <= S3; ++k) {
                ++vec[i + j + k - 3];
            }
        }
    }
    cout << max_element(vec.cbegin(), vec.cend()) - vec.cbegin() + 3;
    return 0;
}
