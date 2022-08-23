#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, answer = 1;
    cin >> N;
    for (int i = 11; i <= N; i = i*10 + 1) {
        ++answer;
    }
    cout << answer << '\n';
    return 0;
}
