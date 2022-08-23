#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    for (auto &x : vec) {
        cin >> x;
    }
    sort(vec.begin(), vec.end(), greater<int>());
    int theDay = 0;
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] + i + 2 > theDay) {
            theDay = vec[i] + i + 2;
        }
    }
    cout << theDay;
    return 0;
}
