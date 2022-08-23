#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    int sum = 0;
    for (auto &x : vec) {
        cin >> x;
        sum += x;
    }
    sort(vec.begin(), vec.end());
    long long price = 0;
    for (auto const &x : vec) {
        sum -= x;
        price += sum * x;
    }
    cout << price << '\n';
    return 0;
}
