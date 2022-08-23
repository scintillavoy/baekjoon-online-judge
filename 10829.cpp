#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N;
    vector<int> N_binary;
    for (cin >> N; N > 0; N /= 2) {
        N_binary.push_back(N % 2);
    }
    for (auto it = N_binary.crbegin(); it != N_binary.crend(); ++it) {
        cout << *it;
    }
    return 0;
}
