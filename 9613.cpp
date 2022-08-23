#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a%b);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> vec(n);
        for (auto &x : vec) {
            cin >> x;
        }
        long long sum = 0;
        for (int i = 0; i < vec.size() - 1; ++i) {
            for (int j = i + 1; j < vec.size(); ++j) {
                sum += gcd(vec[i], vec[j]);
            }
        }
        cout << sum << '\n';
    }
    return 0;
}
