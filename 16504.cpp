#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long answer = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int num;
            cin >> num;
            answer += num;
        }
    }
    cout << answer << '\n';
    return 0;
}
