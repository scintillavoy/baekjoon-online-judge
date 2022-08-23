#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    string N_str = to_string(N);
    int cnt = 0;
    while (N > 0 && M >= N_str.size()) {
        cout << N_str;
        --N;
        M -= N_str.size();
    }
    if (N > 0 && M > 0) {
        cout << N_str.substr(0, M);
    }
    return 0;
}
