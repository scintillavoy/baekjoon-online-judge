#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> vec(N);
    for (auto &x : vec) {
        cin >> x;
    }
    
    int maxSum = 0;
    for (int i = 0; i < vec.size() - 2; ++i) {
        for (int j = i + 1; j < vec.size() - 1; ++j) {
            for (int k = j + 1; k < vec.size(); ++k) {
                int sum = vec[i] + vec[j] + vec[k];
                if (sum <= M && maxSum < sum) {
                    maxSum = sum;
                }
            }
        }
    }
    cout << maxSum;
    return 0;
}
