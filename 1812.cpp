#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    int sum = 0;
    for (auto &x : vec) {
        cin >> x;
        sum += x;
    }
    sum /= 2;
    for (int i = 1; i < vec.size(); i += 2) {
        sum -= vec[i];
    }
    vec.pop_back();
    cout << sum << '\n';
    for (auto const &x : vec) {
        cout << x - sum << '\n';
        sum = x - sum;
    }
    return 0;
}
