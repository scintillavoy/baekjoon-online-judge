#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> vec(n+1);
    vec[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            vec[i] += vec[j] * vec[i-j-1];
        }
    }
    cout << vec.back() << '\n';
    return 0;
}
