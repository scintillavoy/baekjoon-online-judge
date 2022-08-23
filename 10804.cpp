#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vec(20);
    for (int i = 0; i < vec.size(); ++i) {
        vec[i] = i + 1;
    }
    for (int i = 0; i < 10; ++i) {
        int a, b;
        cin >> a >> b;
        reverse(vec.begin() + a - 1, vec.begin() + b);
    }
    for(auto const &x : vec) {
        cout << x << ' ';
    }
    return 0;
}
