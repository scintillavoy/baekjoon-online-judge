#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int K;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        int N;
        cin >> N;
        vector<int> vec(N);
        for (auto &x : vec) {
            cin >> x;
        }
        sort(vec.begin(), vec.end());
        int gap = 0;
        for (int j = 1; j < vec.size(); ++j) {
            if (vec[j] - vec[j-1] > gap) {
                gap = vec[j] - vec[j-1];
            }
        }
        cout << "Class " << i + 1 << '\n';
        cout << "Max " << vec.back() << ", Min " << vec.front();
        cout << ", Largest gap " << gap << '\n';
    }
    return 0;
}
