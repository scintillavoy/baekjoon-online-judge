#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> vec;
    vec.reserve(N);
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        vec.push_back(num);
    }
    int cnt = 0;
    for (auto it = vec.rbegin(); it + 1 != vec.rend(); ++it) {
        if (*(it + 1) >= *it) {
            cnt += *(it + 1) - *it + 1;
            *(it + 1) = *it - 1;
        }
    }
    cout << cnt;
    return 0;
}
