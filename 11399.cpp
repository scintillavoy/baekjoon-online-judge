#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    for (auto &x : vec) {
        cin >> x;
    }
    sort(vec.begin(), vec.end());
    for (int i = 1; i < N; ++i) {
        vec[i] += vec[i-1];
    }
    int answer = 0;
    for (auto const &x : vec) {
        answer += x;
    }
    cout << answer;
    return 0;
}
