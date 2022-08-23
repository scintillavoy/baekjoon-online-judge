#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    unsigned long long sum = 0;
    for (int i = 0; i < N; ++i) {
        unsigned int num;
        cin >> num;
        sum += num;
    }
    cout << sum - (unsigned long long)(N-1)*N/2 << '\n';
    return 0;
}
