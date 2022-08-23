#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string str(N, '*');
        for (int j = 3; j <= N; j *= 3) {
            if (j / 3 <= i % j && i % j < j / 3 * 2) {
                for (int k = 0; k < str.size(); ++k) {
                    if (j / 3 <= k % j && k % j < j / 3 * 2) {
                        str.at(k) = ' ';
                    }
                }
            }
        }
        cout << str << '\n';
    }
    return 0;
}
